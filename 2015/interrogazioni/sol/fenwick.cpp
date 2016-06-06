#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define inf 1000000000
#define MAXN 200001

using namespace std;

void insert(int index, long long *fenwick)
{
    for(int i = index + 1; i < MAXN; i += i & -i)
    {
        fenwick[i]++;
    }
}

int sum(int index, long long *fenwick)
{
    int retVal = 0;
    for(int i = index + 1; i > 0; i -= i & -i)
    {
        retVal += fenwick[i];
    }
    return retVal;
}

int values[MAXN];
int positions[MAXN];

int cmp(int a, int b)
{
    if(values[a] != values[b]) return values[a] < values[b];
    return positions[a] < positions[b];
}

int main()
{

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    long long fenwick[MAXN];
    memset(fenwick, 0, sizeof fenwick);
    int n;
    cin >> n;
    long long sol = 0;
    vector<int> pos;
    for(int i = 0; i < n; ++i)
    {
        cin >> values[i];
        positions[i] = i;
        pos.push_back(i);
    }
    sort(pos.begin(), pos.end(), cmp);
    for(int i = 0; i < n; ++i)
    {
        insert(pos[i], fenwick);
        sol += pos[i] - sum(pos[i], fenwick) + 1;
    }
    cout << sol << endl;
    return 0;
}
