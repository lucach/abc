#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <cmath>
#include <functional>
#include <cstring>
#include <algorithm>
#include <assert.h>
#include <limits.h>

#define pii pair<int,int>

using namespace std;

int N,M,K;
int aulastudio;
int inf = INT_MAX;
vector<pii> graph[5005];
int shortest[5005];

void dijkstra (int start)
{
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.push(pii(0, start));

    while(!pq.empty()) //standard heap dijkstra
    {
        int curdist = pq.top().first;
        int curnode = pq.top().second;
        pq.pop();

        if(shortest[curnode] <= curdist)
            continue;

        shortest[curnode] = curdist;

        for (int i = 0; i < graph[curnode].size(); i++)
        {
            int nextnode = graph[curnode][i].second;
            int nextdist = graph[curnode][i].first + curdist;

            if(nextdist < shortest[nextnode])
                pq.push(pii(nextdist, nextnode));
        }
    }
}

int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    in >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        in >> aulastudio;
        aulastudio--;
    }
    for (int i = 0; i < M; i++)
    {
        int a,b,L;
        in >> a >> b >> L;
        a--;
        b--;
        graph[a].push_back(pii(L, b));
        graph[b].push_back(pii(L, a));
    }

    for (int j = 0; j < N; j++)
        shortest[j] = inf;


    int best = inf;
    dijkstra(aulastudio);

    for (int i = 0; i < N; i++) {
        if (i == aulastudio) continue;
        best = min(best, 2*shortest[i]);
    }

    out << best << "\n";
    out.close();
    return 0;
}

