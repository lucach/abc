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
2 Luca Francesca

In alternativa alla map si può memorizzare anche un vettore
di stringhe e banalmente cercare ogni volta il nome.
La complessità diventa O(n^2) anziché O(nlogn).
*/
int main(int argc, char* argv[])
{
    map<string, vector<string> > inviati, ricevuti;
    ifstream in;
    (argc == 2) ? in.open(argv[1]) : in.open("input.txt");
    int n, r;
    in >> n >> r;
    string a, b;
    for (int i = 0; i < n; i++)
    {
        in >> a >> b;
        inviati[a].push_back(b);
        ricevuti[b].push_back(a);
    }
    for (int i = 0; i < r; i++)
    {
        in >> a >> b;
        vector<string> res;
        vector<string>::iterator it;
        if (b == "INVIATI")
            res = inviati[a];
        else if (b == "RICEVUTI")
            res = ricevuti[a];
        else assert(false);
        cout << res.size() << " ";
        for (it = res.begin(); it != res.end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}
