#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000
int cache[MAXN][2];
int valori[MAXN];
int N;

int massimo(int idx, int one) {
    if (idx == N) return 0;
    if (idx == N - 1 && one)
        return 0;
    else if (idx == N - 1)
            return valori[idx];
    if (cache[idx][one] == -1)
        cache[idx][one] = max(massimo(idx + 1, one), massimo(idx + 2, one) + valori[idx]);

    return cache[idx][one];
}

int main() {
    ifstream in("input.txt");
    in >> N;
    for (int i = 0; i < N; i++)
    {
        in >> valori[i];
        cache[i][0] = cache[i][1] = -1;
    }
    ofstream out("output.txt");
    out << max(massimo(2, 1) + valori[0], massimo(1, 0)) << endl;
}
