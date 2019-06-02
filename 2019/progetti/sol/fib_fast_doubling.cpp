/*
	Author: Fabio Marchesi.
	Complexity: O((logN)^2).
	Description: It uses Fibonacci recurrence:
		fib(2N+1)=fib(N)^2+fib(N+1)^2
		fib(2N)=fib(N)*(2fib(N+1)-fib(N))
	Efficency: for fib(1000000000) does 153 calls.
*/
#include<bits/stdc++.h>
using namespace std;
int const MOD=1000000007;
map<int,int> memo;
int fib(int i) {
    if(i==1 || i==2)	return 1;
    if(memo.find(i)!=memo.end())	return memo[i];
    long long int f=fib(i/2), s=fib(i/2+1), res;
    if(i%2==0)	res=(f*(2*s-f+MOD))%MOD;
    else	res=((f*f)%MOD+(s*s)%MOD)%MOD;
    return memo[i]=res;
}
int progetti(int n, int k) {
    // Assume K == 2.
    return fib(n+1);
}
