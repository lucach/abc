// Qui usiamo long long, mentre in soluzione.cpp usiamo int.
// Non è richiesto l'utilizzo dei long, qua vengono usati solo per verificare
// la correttezza di soluzione.cpp.
#include <fstream>
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

vector<pair<long long, long long > > range;
vector<long long> sz;

bool p(long long pos, long long mid) {
    long long cur = 0;
    for (int i = 0; i < range.size(); i++) {
        if (mid < range[i].first)
            continue;
        if (mid >= range[i].first && mid <= range[i].second) {
            cur += mid - range[i].first;
            continue;
        }
        else
            cur += sz[i];
    }

    return (cur > pos);
}

long long nthElement(vector<long long> lower, vector<long long> upper, long long pos) {
    sz = vector<long long> (lower.size(), 0);

    for (int i = 0; i < lower.size(); i++) {
        pair<long long, long long> tmp;
        tmp.first = lower[i];
        tmp.second = upper[i];
        range.push_back(tmp);
    }
    sort(range.begin(), range.end());
    for (int i = 0; i < range.size(); i++)
        sz[i] = range[i].second - range[i].first + 1;

    long long l = numeric_limits<long long>::max();
    long long h = 0;

    for (long long i = 0; i < range.size(); i++) {
        l = min(l, range[i].first);
        h = max(h, range[i].second);
    }

    while (l < h) {
        long long m = l + (h - l + 1) / 2;
        if (p(pos, m))
            h = m - 1;
        else
            l = m;
    }
    return l;
}

int main() {
    long long N, pos;
    ifstream in("input.txt");
    in >> N >> pos;
    pos--;
    vector<long long> lower(N), upper(N);
    for (long long i = 0; i < N; i++)
        in >> lower[i] >> upper[i];

    ofstream out("output.txt");
    out << nthElement(lower, upper, pos) << endl;
}
