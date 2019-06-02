/*
	Author: Fabio Marchesi.
	Complexity: O(N^2).
	Description: 2 loops
				1<=l<=n
					sliding window
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solve(int n, ll m, int* V) {
    for(int l=1; l<=n; l++) {	//length of subarray
        ll sum=0;
        for(int i=0; i<n; i++) {
            sum+=V[i];
            if(i-l>=0)
                sum-=V[i-l];
            if(sum>m)	return l-1;
        }
    }
    return n; //sum of all elements<m
}

int quadri(int n, ll m, int* V) {
    return solve(n, m, V);
}
