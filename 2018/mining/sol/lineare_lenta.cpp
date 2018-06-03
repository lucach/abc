#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
const int MAXN = 100000;

bool isValida(int N, int K, int T[], int M) {
    int placed = K;
    int elapsed = 0;
    vector<int> times(K);
    for (int i = 0; i < K; i++)
        times[i] = T[i];
    do {
        int min = *min_element(times.begin(), times.end());
        elapsed += min;
        for (int i = 0; i < K; i++)
            times[i] -= min;
        for (int i = 0; i < K; i++)
            if (times[i] == 0)
                times[i] = T[placed++];
    } while (placed < N);
    elapsed += *max_element(times.begin(), times.end());
    return (elapsed <= M);
}

int gpu(int N, int M, int T[]) {
    for (int k = 1; k <= N; k++)
        if (isValida(N, k, T, M))
            return k;
}
