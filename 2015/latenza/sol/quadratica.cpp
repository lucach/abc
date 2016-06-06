#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <climits>
#define MAX 1000010
using namespace std;
typedef pair<int,int> pii;
int V, E, maxn, maxd;
int dist[2501][2501];
bool seen[2501];
int res = 0;
vector<vector<pii> > graph(MAX+1);

int distanza(int node, int curnode, int curdist) {
    seen[curnode] = true;
	for(vector<pii>::iterator it = graph[curnode].begin(); it != graph[curnode].end(); it++)
        if (!seen[it->second])
        {
            dist[node][it->second] = curdist + it->first;
            distanza(node, it->second, dist[node][it->second]);
        }
}

main() {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	int u, v, we;
	cin >> V;
    E = V - 1;
    for(int i = 1; i <= V; i++) graph[i].clear();
    for(int i = 1; i <= E; i++) {
        cin >> u >> v >> we;
        graph[u].push_back(pii (we, v));
        graph[v].push_back(pii (we, u));
    }
    memset(dist, INT_MAX, sizeof(int) * 2501 * 2501);
    for (int i = 1; i <= V; i++)
    {
        memset(seen, false, sizeof(bool) * 2501);
        distanza(i, i, 0);
    }
    for (int i = 1; i <= V; i++)
        for (int k = i + 1; k <= V; k++)
        {
            res = max(res, dist[i][k]);
        }
    cout << res << endl;
}
