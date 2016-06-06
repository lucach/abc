// Per ogni (i,j) dfs, prendo il massimo
// N * (N - 1) * N = N^3

#include <iostream>
#include <fstream>
#include <algorithm>
#define MAX 100001

using namespace std;

struct coll
{
    int a;
    int b;
    int costo;
};

int n;
coll c[MAX];
bool visitati[MAX];

int latenza(int k)
{
    int tot = 0;
    visitati[k] = true;
    for(int i = 0; i < n - 1; i++)
    {
        if(c[i].a == k)
        {
            if(!visitati[c[i].b])
                tot = max(tot, latenza(c[i].b) + c[i].costo);
        }
        else
            if(c[i].b == k)
                if(!visitati[c[i].a])
                {
                    tot = max(tot, latenza(c[i].a) + c[i].costo);
                }
    }
    visitati[k] = false;
    return tot;
}

int main()
{
    ifstream in("input.txt");
    ofstream ou("output.txt");
    in >> n;
    for(int i = 0; i < n - 1; i++) in >> c[i].a >> c[i].b >> c[i].costo;
    int m = latenza(1);
    for(int i = 2; i <= n; i++)
        m = max(m, latenza(i));
    ou << m;
    return 0;
}

