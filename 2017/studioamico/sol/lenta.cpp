#define MAXN 100

int* v1;
int* v2;
bool taken[MAXN];
int N;

bool prova(int idx, bool* t) {
    if (idx == N) return true;
    // Provo tutti quelli possibili
    for (int j = 0; j < N; j++) {
        if (!t[j] && v2[j] > v1[idx]) {
            t[j] = true;
            if (prova(idx + 1, t))
                return true;
            t[j] = false;
        }
    }
    return false;
}

bool associabili(int N, int* values_A, int* values_B) {
    ::N = N;
    v1 = values_A;
    v2 = values_B;
    for (int i = 0; i < N; i++) taken[i] = false;
    return prova(0, taken);
}
