#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 50000;
const int MAXM = 100000;
const int MAXK = 10;

int N, M;
pair<int, int> edges[MAXM];
pair<int, vector<int> > graph[MAXN];
bool solution_found;
set<int> solution;

bool verify_cover(set <int> cover) {
    bool covered[MAXM] = {};
    for (int v : cover) {
        for (int i = 0; i < M; i++)
            if (edges[i].first == v or edges[i].second == v)
                covered[i] = true;
    }
    for (int i = 0; i < M; i++)
        if (!covered[i])
            return false;
    return true;
}

bool cmp(pair<int, vector<int> > v1, pair<int, vector<int> > v2) {
    return v1.second.size() > v2.second.size();
}

int riassumi(int N, int M, int A[], int B[], int S[]) {
    ::N = N; ::M = M;
    for (int i = 0; i < N; i++)
        graph[i].first = i;
    for (int i = 0; i < M; i++) {
        edges[i] = {A[i] - 1, B[i] - 1};
        graph[A[i] - 1].second.push_back(B[i] - 1);
        graph[B[i] - 1].second.push_back(A[i] - 1);
    }
    sort(graph, graph + N, cmp);
    for (int i = 0; i < 10; i++)
        S[i] = graph[i].first + 1;
    return 10;
}

