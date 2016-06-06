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
int shortest[5005][5005];
bool isAulaStudio[5005];

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

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            shortest[i][j] = inf;

    for (int i = 0; i < N; i++)
        shortest[i][i] = 0;


    for (int i = 0; i < M; i++)
    {
        int a,b,L;
        in >> a >> b >> L;
        a--;
        b--;
        graph[a].push_back(pii(L, b));
        graph[b].push_back(pii(L, a));
        shortest[a][b] = L;
        shortest[b][a] = L;
    }


    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                if (shortest[j][k] > shortest[i][j] + shortest[i][k])
                {
                    shortest[j][k] = shortest[i][j] + shortest[i][k];
                    shortest[k][j] = shortest[i][j] + shortest[i][k];
                }

    int best = inf;
    int order[K];
    for (int i = 0; i < K; i++)
        order[i] = i;

    do
    {
        int total = inf;
        for (int i = 0; i < N; i++) 
            if(!isAulaStudio[i])
                total = min(total, shortest[aulestudio[order[0]]][i] + shortest[aulestudio[order[K-1]]][i]);

        for (int i = 1; i < K; i++)
            total += shortest[aulestudio[order[i-1]]][aulestudio[order[i]]];

        best = min(best, total);
    }
    while(next_permutation(order, order + K));


    out << best << "\n";
    out.close();
    return 0;
}

