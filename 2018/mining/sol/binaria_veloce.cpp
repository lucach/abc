#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
const int MAXN = 10000;

bool isValida(int N, int k, int T[], int M) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int elapsed = 0;
    for (int i = 0; i < N; i++) {
        if (i >= k) {
            elapsed = pq.top();
            pq.pop();
        }
        pq.push(T[i] + elapsed);
    }
    int high = 0;
    while (!pq.empty()) {
        high = pq.top();
        pq.pop();
    }
    return (high <= M);
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
