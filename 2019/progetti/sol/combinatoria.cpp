/*
	Author: Simone Moretti.
	Complexity: O(log(N)(log(N)+k^2)).
	Description: using Combinatorics to calculate the nth element of the sequence.
	In a sequence like this one, where i-element is the sum of the prevoius k elements(k=3) it is the equivalent of:
	To compute the i-element it's like create a ix1 matrix using only pieces of width=1 and height <= k:
		The first step is divide the problem in 2 halfs and then: f(i)=f(i/2)f(i/2 **+1 id i is odd): in this way we are counting
		all the combinations of making a piece of height i using the result of 2 pieces of height i/2.
		Now, we have to add at that value all the combinations where we ad a new piece of height<=k in that matrix, in a way that this
		piece divides the remaining space in two parts, the only thing we need to do is check the position of this piece and his height,
		adding the possible ways to the result.
		For every call: logN we can put k^2 different pieces in the middle, using a map the complexity became: O(log(N)(log(N)+k^2)).
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
map<ll,ll> M;
ll i, j;
ll ric(ll a, int n, int k) {
    if(a<0)
        return 0;
    ll t=M[a], x, y, i, j;
    if(t)
        return t;
    x=y=a/2;
    if(a%2)
        y++;
    t=(ric(x,n,k)*ric(y,n,k))%mod;
    for(i=2; i<=k; i++) {
        for(j=1; j<i; j++) {
            t+=(ric(x-j,n,k)*ric(y-i+j,n,k))%mod;
        }
    }
    t%=mod;
    return M[a]=t, t;
}
int progetti(int n, int k) {
    M[0]=1;
    for(i=0; i<k; i++)
        for(j=0; j<i; j++)
            M[i]+=M[j];
    return ric(n,n,k);
}
