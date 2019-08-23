	Author: Fabio Marchesi.
	Complexity: O(N).
	Description: Using sliding window, for every possible start compute how far "end" can go before becoming greater than M. Both start
               and end are incremented at most N times. For computing where end should be starting from i we begin from its position 
               for i-1.
#include<bits/stdc++.h>
using namespace std;
int quadri(int N, long long M, int V[]){
	int res=N;
	long long window=0LL;
	for(int start=0,end=0;end<N;window-=V[start++]){
		while(end<N && window+V[end]<=M)
			window+=V[end++];
		res=min(res,end-start);
	}
	return res;
}
