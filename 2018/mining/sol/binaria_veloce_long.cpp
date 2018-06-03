#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
const long long MAXN = 10000;

bool isValida(long long N, long long K, int T[], long long M) {
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    long long elapsed = 0;
    for (long long i = 0; i < N; i++) {
        if (i >= K) {
            elapsed = pq.top();
            pq.pop();
        }
        pq.push(T[i] + elapsed);
    }
    long long high = 0;
    while (!pq.empty()) {
        high = pq.top();
        pq.pop();
    }
    return (high <= M);
}

int gpu(int N, int M, int T[]) {
    long long l = 1, h = N;
    while (l < h) {
        long long m = (l+h)/2;
        if (isValida(N, m, T, M))
            h = m;
        else
            l = m + 1;
    }
    return l;
}
