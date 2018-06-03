#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

#define pii pair<int,int>
#define MAXN 2000
using namespace std;

const int INF = numeric_limits<int>::max();
const int SMALLINF = 1 << 29;

vector<pii> graph[MAXN];
int dist[MAXN][MAXN];

int dijkstra(int N, int start) {
    vector<int> distance(N, INF);
    priority_queue<pii> q;
    q.push({0, start});
    while (!q.empty()) {
        int u = q.top().second;
        int w = -q.top().first;
        q.pop();
        if (distance[u] == INF) {
            distance[u] = w;
            for (auto next: graph[u])
                q.push({-(w + next.first), next.second});
        }
    }
    return *max_element(distance.begin(), distance.end());
}

int do_dijkstra(int N, int M, int A[], int B[], int L[])
{
    for (int i = 0; i < M; i++)
    {
            int a = A[i] - 1;
            int b = B[i] - 1;
            graph[a].push_back(pii(L[i], b));
            graph[b].push_back(pii(L[i], a));
        }

    int best = 0;
    for (int i = 0; i < N; i++)
        best = max(best, dijkstra(N, i));

    return best;
}

int floyd_warshall(int N, int M, int A[], int B[], int L[])
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

    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int best = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            best = max(best, dist[i][j]);

    return best;
}

int latenza(int N, int M, int A[], int B[], int L[])
{
    if (M <= 2 * N)
        return do_dijkstra(N, M, A, B, L);
    else
        return floyd_warshall(N, M, A, B, L);
}
