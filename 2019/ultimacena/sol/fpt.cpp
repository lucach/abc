// Soluzione "FPT" per vertex cover.
// Vertex cover e' NP ma e' trattabile fissato il parametro (FPT), 
// ovvero la dimensione della copertura. Ci viene garantito che la
// copertura esiste ed e' piccola.
// L'osservazione chiave e' che dato un arco, almeno uno dei suoi due
// vertici estremi deve essere incluso nella copertura (altrimenti l'arco
// non sarebbe coperto). La soluzione prova quindi per ogni arco ad
// aggiungere l'uno o l'altro estremo (se necessario).

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

void explore(int edge, set <int> cover) {
    if (!solution_found) {
        if (cover.size() == MAXK or edge == M) {
            if (verify_cover(cover)) {
                solution_found = true;
                solution = cover;
            }
        }
        else {
            // One of the two extremes of the edge must be included in the cover.
            bool a_found = cover.find(edges[edge].first) != cover.end();
            bool b_found = cover.find(edges[edge].second) != cover.end();
            if (a_found or b_found)
                explore(edge + 1, cover);
            else {
                set<int> new_cover_a = cover;
                set<int> new_cover_b = cover;
                new_cover_a.insert(edges[edge].first);
                new_cover_b.insert(edges[edge].second);
                explore(edge + 1, new_cover_a);
                explore(edge + 1, new_cover_b);
            }
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
