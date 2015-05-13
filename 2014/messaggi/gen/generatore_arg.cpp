#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

void rand_str(char *dest, size_t length) {
    char charset[] = "0123456789"
                     "abcdefghijklmnopqrstuvwxyz";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof charset - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}

int main(int argc, char* argv[])
{
    #define USERNAME_LENGTH 10
    if (argc != 3) { cout << "Errore parametri."; return 1; }
    int N = atoi(argv[1]);
    int R = atoi(argv[2]);
    int N_USER = 2*R; // Assumiamo come invariante che gli utenti siano il doppio delle richieste.
    char user[N_USER][USERNAME_LENGTH+1];
    vector <pair<int, int> > usati;
    for (int i = 0; i < N_USER; i++)
        rand_str(user[i], USERNAME_LENGTH);
    cout << N << " " << R << endl;
    for (int i = 0; i < N; i++)
    {
        int r1 = rand()%N_USER, r2;
        do { r2 = rand()%N_USER; } while (r1 == r2);
        cout << user[r1] << " " << user[r2] << endl;
    }
    string s1 = "INVIATI", s2 = "RICEVUTI";
    for (int i = 0; i < R; i++)
    {
        int r1, r2;
        do
        {
            r1 = rand()%N_USER;
            r2=rand()%2;
        } while (find(usati.begin(), usati.end(), make_pair(r1, r2)) != usati.end());
        usati.push_back(make_pair(r1, r2));
        cout << user[r1] << " " << ((r2) ? s1 : s2) << endl;
    }
}
