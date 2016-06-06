#include <iostream>
using namespace std;

#define MAXN 200000

int val[MAXN], N;
long long res = 0;

int main()
{

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> val[i];
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            res += (val[i] > val[j]);
    cout << res << endl;
}
