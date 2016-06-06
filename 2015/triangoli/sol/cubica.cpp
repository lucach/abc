#include <bits/stdc++.h>
#define MAXN 100000
int sides[MAXN];

using namespace std;
int isNotTri(int a, int b, int c)
{
    if((a + b) < c)return 1;
    if((a + c) < b)return 1;
    if((b + c) < a)return 1;
    return 0;
}
int main(int argc, char *argv[])
{
    ifstream in("input.txt");
    int n;
    in >> n;
    long long ans = 0;
    for(int x = 0; x < n; ++x)
        in >> sides[x];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                ans += isNotTri(sides[i], sides[j], sides[k]);
    ofstream out("output.txt");
    out << ans << endl;
    return 0;
}

