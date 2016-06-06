#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAXN 1000
int valori[MAXN];
int N;

int massimo(int idx, bool is_ultimo_prendibile) {
    if (idx >= N)
        return 0;
    if (idx == N - 1 && !is_ultimo_prendibile)
        return 0;
    else
        return max(massimo(idx + 1, is_ultimo_prendibile), massimo(idx + 2, is_ultimo_prendibile) + valori[idx]);
}

int main() {
    ifstream in("input.txt");
    in >> N;
    for (int i = 0; i < N; i++)
        in >> valori[i];
    ofstream out("output.txt");
    out << max(massimo(2, false) + valori[0], massimo(1, true)) << endl;
}
