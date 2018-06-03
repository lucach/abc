#include <queue>
#include <vector>
#include <limits>
#include <algorithm>

#define pii pair<int,int>
#define MAXN 2000
using namespace std;

int INF = numeric_limits<int>::max();
vector<pii> graph[MAXN];

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

int latenza(int N, int M, int A[], int B[], int L[])
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
