// Fenwick Tree / BIT
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cassert>
#include <queue>
#include <set>
#include <numeric>
#include <stack>
using namespace std;
#define mp make_pair
#define INF (int)1e9
#define X first
#define Y second
#define REP(i, n) for(int i=0; i < n; i++)
#define FOR(i, a, b) for(int i=a; i < b; i++)
#define fill(a, x) memset(a, x, sizeof(a))
#define all(c) c.begin(), c.end()
#define sz(x)    ((int) x.size())
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;

int arr[200010], indices[200010], aux[200010];
ll tree[200010];


bool cmp (int a, int b) {
	return arr[a] < arr[b];
}

ll read(int idx) {
	ll sum = 0;
	while(idx > 0) {
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, int val) {
	while(idx < 200010) {
		tree[idx] += (ll) val;
		idx += (idx & -idx);
	}
}

int main() {

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

	int n;
	fill(tree, 0LL);
	cin >> n;
	for(int i=1; i <= n; i++) cin >> arr[i];
	REP(i, n+1) aux[i] = i;
	sort(aux+1, aux+n+1, cmp);
	FOR(i, 1, n+1) indices[aux[i]] = i;
	ll incnt = 0;
	for(int i = n; i > 0; i--) {
		incnt += read(indices[i]-1);
		update(indices[i], 1);
	}
 	cout << incnt << endl;
}
