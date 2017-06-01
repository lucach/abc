#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int P, M;
const int MAXM = 4000000;
bool stato[MAXM + 1];

void ex(const char *msg, float res) {
    cerr << msg;
    cout << res;

    exit(0);
}

int gcd (int a, int b)
{
    int c;
    while (a != 0) {
        c = a; a = b % a; b = c;
    }
    return b;
}

int main(int argc, char *argv[]) {
    if (argc < 4) return 1;

    ifstream fin(argv[1]);  // input
    ifstream fcor(argv[2]); // output corretto
    ifstream fout(argv[3]); // da controllare

    fin >> P >> M;
    for (int i = 0; i < P; i++) {
        int val, esito, esitocorretto;
        fin >> val;
        fout >> esito;
        fcor >> esitocorretto;
        
        if (esitocorretto == 0) {
            if (esito == 0)
                stato[val] = true;
            else
                ex("Soluzione errata: un checksum valido è stato considerato invalido!", 0.0);
        }
        
        if (esitocorretto > 0) {
            if (esito <= 0)
                ex("Soluzione errata: non è stato identificato un checksum invalido!", 0.0);
            else if (esito != esitocorretto) {
                if (!(stato[esito] == true && gcd(esito, val) != 1))
                    ex("Soluzione errata: in un checksum invalido è stato indicato un riferimento a un pacchetto che non creava problemi per tale checksum.", 0.0);
            }
        }
    }

    // Tutto ok

    ex("Soluzione corretta", 1.0);

    return 0;
}
