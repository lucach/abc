#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define MAXN 100000
int sides[MAXN];

int main(int argc, char *argv[])
{

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    long long ans = 0;
    for(int x = 0; x < n; ++x)
        cin >> sides[x];
    sort(sides, sides + n);
    for(int x = 0; x < n; ++x)
    {
        int i = 0;
        int j = x - 1;
        while(i < j)
        {
            if(sides[x] <= sides[j] + sides[i])
                j--;
            else
            {
                ans += j - i;
                i++;
            }
        }
    }
    cout << ans;
    return 0;
}

