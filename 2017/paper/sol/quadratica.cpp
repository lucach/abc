#include <queue>
using namespace std;
int paper(int N, int M, int* from, int* to) {
    int res = 0;
    vector<vector<int> > graph(N + 1);
    vector<bool> visited(N + 1);
    for (int i = 0; i < M; i++) {
        graph[from[i]].push_back(to[i]);
    }
    // Provo una visita da ogni nodo e controllo se raggiungo tutti
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        for (int j = 1; j <= N; j++) visited[j] = false;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            for (auto adj : graph[cur])
                if (!visited[adj])
                    q.push(adj);
        }
        bool raggiunti = true;
        for (int j = 1; j <= N && raggiunti; j++)
            if (!visited[j])
                raggiunti = false;
        if (raggiunti)
            res++;
    }
    return res;
}
