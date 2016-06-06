#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAXN 1000
int best[MAXN];
int valori[MAXN];
int N;

int massimo(int idx, bool is_ultimo_prendibile) {
    if (idx >= N)
        return 0;
    if (idx == N - 1 && !is_ultimo_prendibile)
        return 0;
    else {
        if (best[idx] == -1)
            best[idx] = max(massimo(idx + 1, is_ultimo_prendibile), massimo(idx + 2, is_ultimo_prendibile) + valori[idx]);
        return best[idx];
    }
}

int main() {
    ifstream in("input.txt");
    in >> N;
    for (int i = 0; i < N; i++)
        in >> valori[i];
    memset(best, -1, sizeof(best));
    int b1 = massimo(2, false) + valori[0];
    memset(best, -1, sizeof(best));
    int b2 = massimo(1, true);
    ofstream out("output.txt");
    out << max(b1, b2) << endl;
}
