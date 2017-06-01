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
    for (int i = 2; i <= val; i++)
        if (val % i == 0)
            if (divisoredi[i] != 0) {
                return divisoredi[i];
            }
    stato[val] = true;
    for (int i = 2; i <= val; i++)
        if (val % i == 0)
            divisoredi[i] = val;
    return 0;
}
