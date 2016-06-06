#include <fstream>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;

#define MAXN 1000
#define MAXV 1000

bool valori[MAXN][MAXV];

int main() {
    int N, pos, a, b;
    ifstream in("input.txt");
    in >> N >> pos;
    pos--;
    for (int i = 0; i < N; i++)
    {
        in >> a >> b;
        memset(&valori[i][a], 1, (b - a + 1) * sizeof(bool));
    }
    ofstream out("output.txt");
    int counter = 0;
    for (int j = 0; j < MAXV; j++)
        for (int i = 0; i < N; i++)
        {
            counter += valori[i][j];
            if (counter == pos + 1)
            {
                out << j << endl;
                return 0;
            }
        }
    // Should never reach this point.
    assert(false);
}
