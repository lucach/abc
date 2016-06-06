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

#define pii pair<int,int>

using namespace std;

int N,M,K;
int aulestudio[6];
int inf = 1 << 29;
vector<pii> graph[5005];
int shortest[6][5005];
bool isAulaStudio[5005];

void dijkstra (int start) //from a market
{
  priority_queue <pii, vector<pii>, greater<pii> > pq;
  pq.push(pii(0, aulestudio[start]));

  while(!pq.empty()) //standard heap dijkstra
    {
      int curdist = pq.top().first;
      int curnode = pq.top().second;
      pq.pop();

      if(shortest[start][curnode] <= curdist)
	continue;

      shortest[start][curnode] = curdist;

      for (int i = 0; i < graph[curnode].size(); i++)
	{
	  int nextnode = graph[curnode][i].second;
	  int nextdist = graph[curnode][i].first + curdist;

	  if(nextdist < shortest[start][nextnode])
	    pq.push(pii(nextdist, nextnode));
	}
    }
}

int main()
{
  ifstream in ("input.txt");
  ofstream out ("output.txt");

  in >> N >> M >> K;
  for (int i = 0; i < N; i++)
    isAulaStudio[i] = false;
  for (int i = 0; i < K; i++)
    {
      in >> aulestudio[i];
      aulestudio[i]--;
      isAulaStudio[aulestudio[i]] = true;
    }
  for (int i = 0; i < M; i++)
    {
      int a,b,L;
      in >> a >> b >> L;
      a--; b--;
      graph[a].push_back(pii(L, b));
      graph[b].push_back(pii(L, a));
    }

  for (int i = 0; i < K; i++)
    {
      for (int j = 0; j < N; j++)
	shortest[i][j] = inf;
      dijkstra(i);
    }

  int best = inf;
  int order[K];
  for (int i = 0; i < K; i++)
    order[i] = i;

  do{
    int total = inf;
    for (int i = 0; i < N; i++) 
      if(!isAulaStudio[i])
	total = min(total, shortest[order[0]][i] + shortest[order[K-1]][i]);

    for (int i = 1; i < K; i++)
      total += shortest[order[i-1]][aulestudio[order[i]]];

    best = min(best, total);
  }while(next_permutation(order, order + K));


  out << best << "\n";
  out.close();
  return 0;
}

