/**
Esempio input
2
2 5 6 2
0 5 3 1
Esempio output
2

Soluzione: semplice implementazione del testo (D=1).
Nessun problema di complessità computazionale.
Unica attenzione: gestione dei negativi.
*/
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

int rett[200][200]; // globale per auto-zero
int main(int argc, char* argv[])
{
    int N, a, b, c, d;
    ifstream in;
    (argc == 1) ? in.open("input.txt") : in.open(argv[1]);
    in >> N;
    cout << N << endl;
    assert(N <= 100);
    for (int i = 0; i < N; i++)
    {
        in >> a >> b >> c >> d;
        assert (a < c && d < b);
        assert (a > -100 && a < 100);
        assert (b > -100 && b < 100);
        assert (c > -100 && c < 100);
        assert (d > -100 && d < 100);
        for (int i = 0; i < c - a; i++)
            for (int j = 0; j < b - d; j++)
            {
                rett[a + i + 100][d + j + 100]++;
            }
    }
    int res = -1;
    for (int i = 0; i < 200; i++)
        for (int j = 0; j < 200; j++)
            res = max(res, rett[i][j]);
    cout << res << endl;
}
