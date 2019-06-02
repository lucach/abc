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
int dp(int i, int n) {
    if(memo[i]!=-1)	return memo[i];
    if(i==n)	return 1;
    int ans=dp(i+1, n);
    ans%=MOD;
    if(i<n-1)	ans+=dp(i+2, n);
    ans%=MOD;
    return memo[i]=ans;
}
int progetti(int n, int k) {
    for(int i=0; i<=n; i++)
        memo[i]=-1;
    return dp(0,n);
}
