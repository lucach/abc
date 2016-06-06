#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define MAX 1000010
#define FOR(i,end) for(int i = 0; i < end; i++)
using namespace std;
typedef pair<int,int> pii;
int V, E, maxn, maxd;
bool seen[MAX + 1];
vector<vector<pii> > graph(MAX+1);

void dfs(int node, int dist) {
	if(dist > maxd) {
		maxn = node;
		maxd = dist;
	}
	seen[node] = 1;
	//consider the adjacent nodes
	for(vector<pii>::iterator it = graph[node].begin(); it != graph[node].end(); it++)
			if(!seen[(*it).second])
				dfs((*it).second, dist + it->first);
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
    memset(seen, 0, sizeof(bool) * (V+1));
    maxd = -1;
    dfs(1, 0);
    memset(seen, 0, sizeof(bool) * (V+1));
    maxd = -1;
    dfs(maxn, 0);
    cout << maxd << endl;
}
