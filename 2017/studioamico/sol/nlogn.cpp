#include <algorithm>
#define MAXN 10000000

bool associabili(int N, int* v1, int* v2) {
    int wrong = 0;
    std::sort(v1, v1 + N);
    std::sort(v2, v2 + N);
    for (int i = 0; i < N; i++)
        if (v1[i] >= v2[i])
            return false;
    return true;
}
