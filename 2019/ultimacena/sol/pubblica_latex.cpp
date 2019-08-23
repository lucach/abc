#include <vector>
#include <set>

using namespace std;

const int MAXN = 50000;
const int MAXM = 100000;
const int MAXK = 10;

int N, M;
pair<int, int> archi[MAXM];
bool salta_arco[MAXM];
vector<int> grafo[MAXN];
bool soluzione_trovata;
set<int> soluzione;

bool verifica_copertura(set <int> copertura) {
    bool coperto[MAXM] = {};
    for (int v : copertura)
        for (int i = 0; i < M; i++)
            if (archi[i].first == v or archi[i].second == v)
                coperto[i] = true;
    for (int i = 0; i < M; i++)
        if (!coperto[i])
            return false;
    return true;
}

void esplora(int arco, set <int> copertura) {
    if (salta_arco[arco])
        esplora(arco + 1, copertura);
    else {
        if (!soluzione_trovata) {
            if (copertura.size() == MAXK or arco == M) {
                if (verifica_copertura(copertura)) {
                    soluzione_trovata = true;
                    soluzione = copertura;
                }
            }
            else {
                bool a_trovato = copertura.find(archi[arco].first) != copertura.end();
                bool b_trovato = copertura.find(archi[arco].second) != copertura.end();
                if (a_trovato or b_trovato)
                    esplora(arco + 1, copertura);
                else {
                    set<int> nuova_copertura_a = copertura;
                    set<int> nuova_copertura_b = copertura;
                    nuova_copertura_a.insert(archi[arco].first);
                    nuova_copertura_b.insert(archi[arco].second);
                    esplora(arco + 1, nuova_copertura_a);
                    esplora(arco + 1, nuova_copertura_b);
                }
            }
        }
    }
}

int riassumi(int N, int M, int A[], int B[], int S[]) {
    ::N = N; ::M = M;
    for (int i = 0; i < M; i++) {
        archi[i] = {A[i] - 1, B[i] - 1};
        grafo[A[i]-1].push_back(B[i]-1);
        grafo[B[i]-1].push_back(A[i]-1);
    }
    // Preprocessing: aggiungo alla copertura i vertici con grado >= 11.
    set<int> copertura;
    for (int i = 0; i < N; i++)
        if (grafo[i].size() >= 11)
            copertura.insert(i);
    for (int i = 0; i < M; i++)
        if (copertura.find(archi[i].first) != copertura.end() or
                copertura.find(archi[i].second) != copertura.end())
            salta_arco[i] = true;
    // Bounded search tree (FPT).
    esplora(0, copertura);
    // Restituisco la copertura trovata come soluzione. 
    int i = 0;
    for (int v : soluzione)
        S[i++] = v + 1;
    return soluzione.size();
}
