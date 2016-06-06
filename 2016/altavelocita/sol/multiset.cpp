#include <fstream>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

#define MAXV 1000000

int arr[MAXV];

int main() {
    int N, pos, a, b;
    multiset<int> multinsieme;
    ifstream in("input.txt");
    in >> N >> pos;
    pos--;
    for (int i = 0; i < N; i++)
    {
        in >> a >> b;
        for (int j = 0; j <= b - a; j++)
            arr[j] = j + a;
        multinsieme.insert(arr, arr + (b - a + 1));
    }

    // Get nth element
    multiset<int>::iterator it = multinsieme.begin();
    advance(it, pos);

    ofstream out("output.txt");
    out << *it << endl;
}
