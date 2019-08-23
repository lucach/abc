/*
	Author: Fabio Marchesi.
	Complexity: O(K^3log(N)).
	Description: using fast exponentation to compute M^(N-1), M is the KxK matrix which M*B=C:
        B=|f(n)    |   C=|f(n+1)  |
   	  |.       |     |.       |
  	  |.       |     |.       |
  	  |f(n-k+1)|     |f(n-k+2)|
*/
#include<bits/stdc++.h>
using namespace std;
int const MOD=1000000007;
int K, m[5][5], dp[5][5];
int add(int a, int b){
	return (a%MOD+b%MOD)%MOD;
}
int mult(long long int a, long long int b){
	return (a%MOD*b%MOD)%MOD;
}
void mult(int a[5][5], int b[5][5]){ //A=A*B
	int c[5][5];
	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++){
			c[i][j]=0;	
			for(int z=0;z<K;z++)
				c[i][j]=add(c[i][j],mult(a[i][z],b[z][j]));
		}
	for(int i=0;i<K;i++)
		for(int j=0;j<K;j++)
			a[i][j]=c[i][j];
}
int progetti(int N, int K){
  ::K=K;
  for(int i=0;i<K;i++)
	m[0][i]=1, dp[0][i]=1;
  for(int i=1, j=0;i<K;i++,j++)
		m[i][j]=1, dp[i][j]=1;
	N--;
	while(N>0){   //FAST EXP
		if(N%2==1) 
			mult(dp,m);
		N/=2;
		mult(m,m);
	}
	return dp[0][0];
}
