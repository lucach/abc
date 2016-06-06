#include <iostream>
#include <algorithm>
using namespace std;
bool candele[20000001];
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int N, T, R;
    cin >> N >> T >> R;
    if (T < R)
        cout << "-1" << endl;
    else
    {
        for (int i = 0; i < N; i++)
        {
            int val;
            cin >> val;
            val += 10000000;
            int accese = 0;
            for (int j = val - 1; j >= val - T; j--)
                accese += candele[j];
            int idx = val - 1;
            while (accese < R) {
                if (candele[idx] == 0) {
                    candele[idx] = 1;
                    accese++;
                }
                idx--;
            }
        }
        cout << accumulate(candele, candele + 20000001, 0) << endl;
    }
}
