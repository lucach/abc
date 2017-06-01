#include <stack>
#include <vector>
using namespace std;

#define MAXN 100005
stack<int> s;
bool visited[MAXN];
int scc[MAXN], degree[MAXN];
vector<int> graph[MAXN], tgraph[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (auto next : graph[node])
        if (!visited[next])
            dfs(next);
    s.push(node);
}

void t_dfs(int node, int scc_id) {
    visited[node] = true;
    scc[node] = scc_id;
    for (auto next : tgraph[node])
        if (!visited[next])
            t_dfs(next, scc_id);
}

int paper(int N, int M, int* from, int* to) {
    for (int j = 0; j <= N; j++) {
        graph[j].clear();
        tgraph[j].clear();
        degree[j] = 0;
        visited[j] = false;
    }
    for (int i = 0; i < M; i++) {
        graph[from[i]].push_back(to[i]);
        tgraph[to[i]].push_back(from[i]);
    }
    // dfs
    for (int i = 1; i <= N; i++)
        if (!visited[i])
            dfs(i);
    // reset visited array
    for (int i = 1; i <= N; i++)
        visited[i] = false;
    // find SCC
    int scc_id = 0;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        if (!visited[cur]) {
            t_dfs(cur, scc_id);
            scc_id++;
        }
    }
    // calcolo quanti archi in ingresso ci sono per ogni scc
    for (int i = 1; i <= N; i++)
       for (auto adj : graph[i]) {
          if (scc[i] != scc[adj])
             degree[scc[adj]]++;
        }

    int zero_deg = 0;
    for (int i = 0; i < scc_id; i++)
        if (degree[i] == 0)
            zero_deg++;
    if (zero_deg > 1)
        return 0;
    else {
        int res = 0;
        for (int i = 1; i <= N; i++)
            if (degree[scc[i]] == 0)
                res++;
        return res;
    } 
}
