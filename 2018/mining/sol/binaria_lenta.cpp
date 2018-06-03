#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
const int MAXN = 10000;

bool isValida(int N, int k, int T[], int M) {
    int placed = k;
    int elapsed = 0;
    vector<int> times(k);
    for (int i = 0; i < k; i++)
        times[i] = T[i];
    do {
        int min = *min_element(times.begin(), times.end());
        elapsed += min;
        for (int i = 0; i < k; i++)
            times[i] -= min;
        for (int i = 0; i < k; i++)
            if (times[i] == 0)
                times[i] = T[placed++];
    } while (placed < N);
    elapsed += *max_element(times.begin(), times.end());
    return (elapsed <= M);
}

int gpu(int N, int M, int T[]) {
    int l = 1, h = N;
    while (l < h) {
        int m = (l+h)/2;
        if (isValida(N, m, T, M))
            h = m;
        else
            l = m + 1;
    }
    return l;
}
