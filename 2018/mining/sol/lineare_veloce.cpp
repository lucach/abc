#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
const int MAXN = 100000;

bool isValida(int N, int K, int T[], int M) {
    priority_queue<long long, vector<long long>, greater<long long> > pq;
    long long elapsed = 0;
    for (int i = 0; i < N; i++) {
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
    for (int k = 1; k <= N; k++)
        if (isValida(N, k, T, M))
            return k;
}
