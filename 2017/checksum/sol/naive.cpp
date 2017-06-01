#include <fstream>
#include <cassert>
using namespace std;
#define MAXM 4000000
bool stato[MAXM + 1];

int gcd (int a, int b)
{
    int c;
    while (a != 0) {
        c = a; a = b % a; b = c;
    }
    return b;
}

int P, M;

void inizializza(int P, int M) {
    ::P = P;
    ::M = M;
}

int controlla(int val) {
    assert(stato[val] == false);

    // Controllo che non ci siano conflitti assicurandomi che il gcd
    // tra ciascuno di quelli precedenti validi e quello corrente sia 1.
    for (int i = 2; i <= M; i++)
        if (stato[i] == true && gcd(val, i) != 1) {
            return i;
        }

    // Se invece è tutto ok, segno come valido e ritorno 0.
    stato[val] = true;
    return 0;
}
