/*
	Author: Fabio Marchesi.
	Complexity: O(n).
	Description: Linear calculation of Tribonacci sequence.
*/
#include<bits/stdc++.h>
using namespace std;
int const MOD=1000000007;
int progetti(int n, int k) {
    // Assume K == 3.
    int a=1, b=1, c=0, d=0;
    for(int i=1; i<n; i++) {
        d=c;
        c=b;
        b=a;
        a=((b+c)%MOD+d)%MOD;
    }
    return a;
}
