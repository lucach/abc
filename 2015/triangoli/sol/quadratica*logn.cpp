#include <bits/stdc++.h>

using namespace std;
#define MAXN 100000
int sides[MAXN];


int main(int argc, char *argv[])
{

    int n;
    ifstream in("input.txt");
    in >> n;
    long long ans = 0;
    for(int x = 0; x < n; ++x)
        in >> sides[x];
    sort(sides, sides + n);
    for(int x = 0; x < n; ++x)
        for(int y = x + 1; y < n; ++y)
        {
            ans += x - distance(
                       lower_bound(sides, sides + x, sides[y] - sides[x]),
                       upper_bound(sides, sides + x, sides[x] + sides[y]));
        }
    ofstream out("output.txt");
    out << ans << endl;
    return 0;
}

