#include <iostream>
#include <algorithm>
using namespace std;
bool candele[10000001];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N, T, R;
    cin >> N >> T >> R;
    // Funziona solo per N == 1
    if (N == 1)
        if (T < R)
            cout << "-1" << endl;
        else
            cout << R << endl;
    else
        cout << -1 << endl; // questo non deve comunque produrre punti su altri ST
}
