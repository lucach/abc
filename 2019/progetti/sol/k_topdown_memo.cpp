/*
	Author: Fabio Marchesi.
	Complexity: O(n).
	Description: Counts all the possible ways, without doing the same counts multiple times.
				 It does not work on big numbers: stack overflow.
*/
#include<bits/stdc++.h>
using namespace std;
int const MAXN=2000000, MOD=1000000007;
int memo[MAXN];
int dp(int i, int n, int k) {
    if(memo[i]!=-1)	return memo[i];
    if(i==n)	return 1;
    int ans = dp(i+1, n, k) % MOD;
    for (int step = 2; step <= k; step++) {
        if (i < n - step + 1) {
            ans += dp(i + step, n, k);
            ans %= MOD;
        }
    }
    return memo[i]=ans;
}
int progetti(int n, int k) {
    for(int i=0; i<=n; i++)
        memo[i]=-1;
    return dp(0, n, k);
}
