#include <fstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, pos, a, b;
    vector<int> valori;
    ifstream in("input.txt");
    in >> N >> pos;
    pos--;
    for (int i = 0; i < N; i++)
    {
        in >> a >> b;
        for (int j = a; j <= b; j++)
            valori.push_back(j);
    }
    sort(valori.begin(), valori.end());
    ofstream out("output.txt");
    out << valori[pos] << endl;
}
