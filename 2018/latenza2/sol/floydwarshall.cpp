#include <limits>
#include <algorithm>
using namespace std;

const int SMALLINF = 1 << 29;
const int MAXN = 2000;

int dist[MAXN][MAXN];

int latenza(int N, int M, int A[], int B[], int L[])
{

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = SMALLINF;

    for (int i = 0; i < M; i++)
    {
        int a = A[i] - 1;
        int b = B[i] - 1;
        dist[a][b] = L[i];
        dist[b][a] = L[i];
    }

    for (int i = 0; i < N; i++)
        dist[i][i] = 0;

    //Floyd-warshall
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    // Find max
    int best = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            best = max(best, dist[i][j]);

    return best;
}

