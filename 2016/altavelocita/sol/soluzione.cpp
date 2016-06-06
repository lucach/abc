#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAXN 1000

int inizio[MAXN], fine[MAXN];

int main() {
    int N;
    long long pos;
    ifstream in("input.txt");
    in >> N >> pos;
    pos--;
    for (int i = 0; i < N; i++)
        in >> inizio[i] >> fine[i];

    int low = *min_element(inizio, inizio + N);
    int high = *max_element(fine, fine + N);
    while (low < high) {
        int cur = low + 1 + ((high - low) / 2);
        long long counter = 0;
        for (int i = 0; i < N; i++)
        {
            if (cur >= inizio[i] && cur <= fine[i])
                counter += cur - inizio[i];
            if (cur >= inizio[i] && cur > fine[i])
                counter += fine[i] - inizio[i] + 1;
        }
        if (counter <= pos)
            low = cur;
        else
            high = cur - 1;
    }

    ofstream out("output.txt");
    out << low << endl;
}
