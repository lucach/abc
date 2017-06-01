#define MAXN 10000000

bool taken[MAXN];

bool associabili(int N, int* v1, int* v2) {
    for (int i = 0; i < N; i++) taken[i] = false;
    for (int i = 0; i < N; i++) {
        bool done = false;
        for (int j = 0; j < N && !done; j++) {
            if (!taken[j] && v2[j] > v1[i]) {
                done = true;
                taken[j] = true;
            }
        }
        if (!done) return false;
    }        
    return true;
}
