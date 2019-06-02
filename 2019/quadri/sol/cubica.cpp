/*
	Author: Fabio Marchesi.
	Complemity: O(N^3).
	Description: 3 loops
				1<=l<=n
					1<=start<=n-l
						start<=j<=start+l
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solve(int n, ll m, int* V) {
    for(int l=1; l<=n; l++)	//length of subarray
        for(int start=0; start<=n-l; start++) {	 //possible start points of a subarrat of lenght l
            ll sum=0;
            for(int i=start; i<start+l; i++)
                sum+=V[i];
            if(sum>m)	return l-1;
        }
    return n; //sum of all elements<m
}

int quadri(int n, ll m, int* V) {
    return solve(n, m, V);
}
