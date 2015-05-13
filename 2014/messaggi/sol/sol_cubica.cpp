#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <assert.h>

using namespace std;

/**
Esempio di input:
3 2
Luca Mario
Luca Pietro
Francesca Pietro
Luca INVIATI
Pietro RICEVUTI

Esempio di output:
2 Mario Pietro
2 Luca Francesca*/

int trova(string s, vector <pair <string, vector <string> > > & v)
{
     vector <pair <string, vector <string> > >::iterator it = v.begin();
     for (; it != v.end(); it++)
        if ((*it).first == s)
            return distance(v.begin(), it);
    /** Se non lo trovo, lo aggiungo in fondo! */
    pair <string, vector <string> > tmp;
    vector <string> tmpv;
    tmp.first = s;
    tmp.second = tmpv;
    v.push_back(tmp);
    return v.size()-1;
}

int main()
{
    vector <pair <string, vector <string> > > inviati, ricevuti;
    ifstream in("input.txt");
    int n, r;
    in >> n >> r;
    string a, b;
    for (int i = 0; i < n; i++)
    {
        in >> a >> b;
        inviati[trova(a, inviati)].second.push_back(b);
        ricevuti[trova(b, ricevuti)].second.push_back(a);
    }
    for (int i = 0; i < r; i++)
    {
        in >> a >> b;
        vector<string> res;
        vector<string>::iterator it;
        if (b == "INVIATI")
            res = inviati[trova(a, inviati)].second;
        else if (b == "RICEVUTI")
            res = ricevuti[trova(a, ricevuti)].second;
        else assert(false);
        cout << res.size() << " ";
        for (it = res.begin(); it != res.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}
