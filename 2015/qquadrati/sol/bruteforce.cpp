#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        int res = 0;
        for (int i = 0; i * i <= tmp; i++)
            for (int j = i; j * j <= tmp; j++)
                for (int k = j; k * k <= tmp; k++)
                    for (int z = k; z * z <= tmp; z++)
                        if (i*i + j*j + k*k + z*z == tmp)
                            res++;
        cout << res << " ";
    }
    cout << endl;
	return 0;
}
