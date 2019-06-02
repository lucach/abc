#include<bits/stdc++.h>
using namespace std;

int n, m, rem=10;
vector<vector<int>> g;
vector<int> d, sol;

void add(int node) {
    d[node]=0;
    sol.push_back(node);
    for(auto near:g[node]) {
        d[near]--;
        g[near].erase(find(g[near].begin(), g[near].end(), node));
    }
    g[node].clear();
}

void cover() {
    int best=0, ibest=-1;
    for(int i=0; i<n; i++)
        if(d[i]>best) {
            best=d[i];
            ibest=i;
        }
    if(ibest==-1)	return;
    add(ibest);
}


int riassumi(int N, int M, int A[], int B[], int S[]) {
    ::n = N;
    ::m = M;
    g.resize(n);
    d.resize(n);
    fill(d.begin(), d.end(), 0);
    for(int i=0; i<m; i++) {
        int from = A[i], to = B[i];
        g[from-1].push_back(to-1);
        g[to-1].push_back(from-1);
        d[from-1]++;
        d[to-1]++;
    }

    /* 100% sure nodes */
    for(int i=0; i<n; i++)
        if(g[i].size()==1) {
            add(g[i][0]);
            rem--;
        }

    /* Add the nodes with maximum current degree */
    while(rem--)	cover();
    
    int i = 0;
    for(auto x: sol)
        S[i++] = x + 1;
    return sol.size();
}
