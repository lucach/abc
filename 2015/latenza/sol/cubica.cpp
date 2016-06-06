#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#define MAX 1000010
using namespace std;
typedef pair<int,int> pii;
int V, E, maxn, maxd;
bool seen[MAX + 1];
int res = 0;
vector<vector<pii> > graph(MAX+1);

int distanza(int from, int to, int dist) {
    seen[from] = true;
	if (from == to)
        return dist;
	for(vector<pii>::iterator it = graph[from].begin(); it != graph[from].end(); it++)
        if (!seen[it->second])
        {
            int val = distanza(it->second, to, dist + it->first);
            if (val != -1)
                return val;
        }
    return -1;
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
    for (int i = 1; i <= V; i++)
        for (int k = i + 1; k <= V; k++)
        {
            memset(seen, false, sizeof(bool) * MAX);
            int val = distanza(i, k, 0);
            res = max(res, val);
        }
    cout << res << endl;
}
