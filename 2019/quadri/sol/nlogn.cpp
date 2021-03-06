/*
	Author: Fabio Marchesi.
	Complexity: O(NlogN).
	Description: Binary search of L using sliding window to calculate the sum
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool check(int l, ll m, int *V, int n) {
    ll sum=0;
    for(int i=0; i<n; i++) {
        sum+=V[i];
        if(i-l>=0) sum-=V[i-l];
        if(sum>m) return false;
    }
    return true;
}

int binary_search(int start, int end, ll m, int *V, int n) {
    int mid, ans=0;
    while(start<=end) {
        mid=(start+end)/2;
        if(check(mid,m,V, n)) {
            ans=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}

int quadri(int n, ll m, int *V) {
    return binary_search(1,n,m,V,n);
}

