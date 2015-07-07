#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <sstream>



using namespace std;

ifstream *fin;
ifstream *fcor;
ifstream *fout;

void ex(const char *msg, float res)
{
    if(msg)
        fprintf(stderr, "%s ", msg);
    printf("%f\n", res);
    exit(0);
}

template <class T>
T safe_read(const T &lowerBound, const T &upperBound)
{
    // Legge in maniera sicura un tipo ordinato e controlla che stia in
    // [lowerBound, upperBound]
    T x;
    if(lowerBound > upperBound)
    {
        cerr << "safe_read chiamato con parametri errati: " << lowerBound << " " <<
             upperBound << "\n";
        return 1;
    }
    *fout >> x;

    if(fout->fail())
        ex("Output malformato", 0.0f);
    if(x < lowerBound || x > upperBound)
        ex("Output invalido", 0.0f);
    return x;
}

void
check_fine_file()
{
    string x;

    if(fout->eof())
        return;

    *fout >> x;
    if(x != "" || !fout->eof())
        ex("Output malformato", 0.0f);
}

int nstudents, nbugs, maxpass;

int main(int argc, char *argv[])
{
    if(argc < 4)
    {
        cerr << "Usage: " << argv[0] << " <input> <correct output> <test output>" <<
             endl;
        return 1;
    }

    fin = new ifstream(argv[1]);
    fcor = new ifstream(argv[2]);
    fout = new ifstream(argv[3]);

    if(fin->fail())
    {
        cerr << "Impossibile aprire il file di input " << argv[1] << "." << endl;
        return 1;
    }
    if(fcor->fail())
    {
        cerr << "Impossibile aprire il file di output corretto " << argv[2] << "." <<
             endl;
        return 1;
    }
    if(fout->fail())
        ex("Impossibile aprire il file di output generato dal codice sottoposto al problema.",
           0.0);

    *fin >> nstudents >> nbugs >> maxpass;

    string expectedoutcome, outcome;
    *fout >> outcome;
    *fcor >> expectedoutcome;
    bool good_outcome = false;
    if(outcome != "SI" && outcome != "NO")
    {
        ex("Output invalido", 0.0f);
        return 0;
    }
    if(outcome == expectedoutcome)
        good_outcome = true;

    if(fout->eof())
        if(good_outcome)
        {
            if(outcome == "NO")
                ex("L'output è corretto", 1.0f);
            ex("Solo determinazione SI/NO corretta", 0.3f);
        }
        else
            ex("Determinazione SI/NO errata", 0.0f);
    int x;
    *fout >> x;
    if(fout->eof())
        if(good_outcome)
        {
            if(outcome == "NO")
                ex("L'output è corretto", 1.0f);
            ex("Solo determinazione SI/NO corretta", 0.3f);
        }
    else
            ex("Determinazione SI/NO errata", 0.0f);
    vector<int> risultati(nbugs);
    vector<int> complessitabugs(nbugs);
    vector<int> competenzestudenti(nstudents);
    vector <int> costi(nstudents);
    vector <int> usati(nstudents, 0);
    ostringstream oss;
    if(x < 1 || x > nstudents)
        ex("Output invalido", 0.0f);
    risultati[0] = x;

    for(int i = 0; i < nbugs; i++)
        *fin >> complessitabugs[i];

    for(int i = 0; i < nstudents; i++)
        *fin >> competenzestudenti[i];

    for(int i = 0; i < nstudents; i++)
        *fin >> costi[i];

    for(int i = 0; i < nbugs; i++)
    {
        if(i != 0)
            risultati[i] = safe_read(1, nstudents);
        if(competenzestudenti[risultati[i] - 1] < complessitabugs[i])
        {
            oss << "SI/NO corretto, ma lo studente " << risultati[i] <<
                " ha un livello di abilità "
                << competenzestudenti[risultati[i] - 1] <<
                " non sufficiente a risolvere il bug " << i + 1 <<
                " che ha una complessità "
                << complessitabugs[i];
            ex(oss.str().c_str(), 0.3f);
        }
        usati[risultati[i] - 1]++;
    }
    check_fine_file();
    long long costo = 0, expectedcosto;
    int totgiorni = -1, expectedtotgiorni;
    *fcor >> expectedcosto;
    *fcor >> expectedtotgiorni;
    for(int i = 0; i < nstudents; i++)
        if(usati[i] > 0)
        {
            costo += costi[i];
            totgiorni = max(totgiorni, usati[i]);
        }
    if(totgiorni != expectedtotgiorni)
    {
        oss << "SI/NO corretto, ma numero giorni errato: previsto "
            << expectedtotgiorni << ", ricevuto " << totgiorni << endl;
        ex(oss.str().c_str(), 0.3f);
        return 0;
    }
    ex("L'output è corretto", 1.0f);
    return 0;
}
