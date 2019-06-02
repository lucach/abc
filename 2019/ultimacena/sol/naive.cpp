// Soluzione naive per vertex cover.
// Per ogni vertice, prova ingenuamente a inserirlo (oppure no) nella copertura.

#include <iostream>
#include <vector>
#include <set>
#include <cassert>
using namespace std;

const int MAXN = 50000;
const int MAXM = 100000;
const int MAXK = 10;

int N, M;
pair<int, int> edges[MAXM];
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

void explore(int vertex, set <int> cover) {
    if (!solution_found) {
        if (cover.size() == MAXK or vertex == N) {
            if (verify_cover(cover)) {
                solution_found = true;
                solution = cover;
            }
        }
        else {
            // Try to include / exclude the vertex in / from the cover.
            set<int> new_cover = cover;
            new_cover.insert(vertex);
            explore(vertex + 1, new_cover);
            explore(vertex + 1, cover);
        }
    }
}

int riassumi(int N, int M, int A[], int B[], int S[]) {
    ::N = N; ::M = M;
    for (int i = 0; i < M; i++) {
        edges[i] = {A[i] - 1, B[i] - 1};
    }
    set<int> cover;
    explore(0, cover);
    assert(solution_found);
    int i = 0;
    for (int v : solution)
        S[i++] = v + 1;
    return solution.size();
}
