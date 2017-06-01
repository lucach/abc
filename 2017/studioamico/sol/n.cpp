#define MAXN 10000000
#define MAXV 100

int c[MAXV];
int b[MAXN];

void countingsort(int N, int* a) {
    for (int i = 0; i < MAXV; i++) c[i] = 0;
    for (int i = 0; i < N; i++) c[a[i]]++;
    for (int i = 1; i < MAXV; i++) c[i] += c[i - 1];
    for (int i = N - 1; i >= 0; i--) {
        int posc = a[i];
        int posb = c[posc] - 1;
        b[posb] = a[i];
        c[posc]--;
    }
    for (int i = 0; i < N; i++) a[i] = b[i];
}


bool associabili(int N, int* v1, int* v2) {

    countingsort(N, v1);
    countingsort(N, v2);

    // strictly less
    int wrong = 0;
    for (int i = 0; i < N; i++)
        if (v1[i] >= v2[i])
            return false;

    return true;
}
