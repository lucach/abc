#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

using namespace std;

void ex(float score, std::string message) {
  std::cout << score << std::endl;
  std::cerr << message << std::endl;
  exit(0);
}

int N, M;

bool verify_cover(set <int> cover, vector<pair<int, int> > edges) {
    vector<bool> covered(M, false);
    for (int i = 0; i < M; i++) {
        for (int v : cover)
            if (edges[i].first == v or edges[i].second == v)
                covered[i] = true;
    }
    for (int i = 0; i < M; i++)
        if (!covered[i])
            return false;
    return true;
}


int main(int argc, char const *argv[]) {
    ifstream in(argv[1]);
    ifstream corr(argv[2]);
    ifstream user(argv[3]);

    in >> N >> M;
    vector<pair<int, int> > edges(M);
    for (int i = 0, a, b; i < M; i++) {
        in >> a >> b;
        edges[i] = {a - 1, b - 1};
    }

    int K;
    user >> K;
    // MAXK hardcoded a 10
    if (K < 1 or K > 10)
        ex(0.0, "Dimensione della copertura non valida (deve essere <= 10).");

    set<int> cover;

    for (int i = 0, v; i < K; i++) {
        user >> v;
        if (v < 1 or v > N)
            ex(0.0, "Numero nodo non valido.");
        cover.insert(v - 1);
    }

    if (verify_cover(cover, edges))
        ex(1.0, "Output corretto.");
    else
        ex(0.0, "Output errato.");
    return 0;
}
