#include <algorithm>
int quadri(int N, long long M, int V[]) {
    int risposta = N;
    long long window = 0;
    for(int start = 0, end = 0; end < N; start++) {
        while (end < N and window + V[end] <= M) {
            window += V[end];
            end++;
        }
        risposta = std::min(risposta, end-start);
        window -= V[start];
    }
    return risposta;
}
