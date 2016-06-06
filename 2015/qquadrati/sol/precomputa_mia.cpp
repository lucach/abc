#include <cstdio>
#include <iostream>
using namespace std;

const int MAXV = 1 << 15;

int quanti[4*MAXV];

int main() {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int res = 0;
    for (int i = 0; i * i <= MAXV; i++)
        for (int j = i; j * j <= MAXV; j++)
            for (int k = j; k * k <= MAXV; k++)
                for (int z = k; z * z <= MAXV; z++)
                    quanti[i*i + j*j + k*k + z*z]++;

    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cout << quanti[tmp] << " ";
    }
    cout << endl;
	return 0;
}
