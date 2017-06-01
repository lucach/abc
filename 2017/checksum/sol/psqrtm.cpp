#include <cmath>
#include <cassert>
#define MAXM 4000000
bool stato[MAXM + 1];
int divisoredi[MAXM + 1];

int P, M;

void inizializza(int P, int M) {
    ::P = P;
    ::M = M;
}

int controlla(int val) {
    assert(stato[val] == false);
    for (int i = 1; i <= sqrt(val); i++)
        if (val % i == 0) {
            if (i != 1 && divisoredi[i] != 0)
                return divisoredi[i];
            else if (val / i != 1 && divisoredi[val / i] != 0)
                return divisoredi[val / i];
        }

    stato[val] = true;
    for (int i = 1; i <= sqrt(val); i++)
        if (val % i == 0) {
            divisoredi[i] = val;
            divisoredi[val / i] = val;
        }
    return 0;
}
