#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

#define MAXM 4000000

bool stato[MAXM + 1];
int divisoredi[MAXM + 1];
bool isprime[MAXM + 1];
vector<int> primes;
vector<int> fattori[MAXM + 1];

void inizializza(int P, int M) {
    // Crivello di Eratostene in O(M * log(log(M)))
    for (int i = 2; i <= M; i++) isprime[i] = true;
    primes.reserve(M / sqrt(M)); 
    for (int i = 2; i <= M; i++) 
        if (isprime[i]) {
            primes.push_back(i);
            if (i <= sqrt(M))
                for (int j = i * i; j <= M; j += i)
                    isprime[j] = false;
        }
        
    // Per ogni i in [1..M] computo efficientemente i suoi fattori primi
    for (int i = 1; i <= M; i++) {
        fattori[i].reserve(5);
        int idx = 0, p = primes[0], cur = i;
        while (cur != 1 && (p * p <= cur)) {
            while (cur % p == 0) {
                cur /= p;
                fattori[i].push_back(p);
            }
            p = primes[++idx];
        }
        if (cur != -1)
            fattori[i].push_back(cur);
    }
}

int controlla(int val) {
    assert(stato[val] == false);

    // Controllo che non ci siano conflitti.
    for (auto p : fattori[val])
        if (p != 1 && divisoredi[p] != 0) {
            return divisoredi[p];
        }

    // Se invece è tutto ok, segno come valido e ritorno 0.
    stato[val] = true;
    for (auto p : fattori[val])
        divisoredi[p] = val;
    return 0;
}
