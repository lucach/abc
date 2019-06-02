#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
long long int n,m,i,v[maxn+1],x,no,s[maxn];
bool check;
int quadri(int N, long long M, int V[]){
  m=M;
  n=N;
  v[0]=0;
  for(i=1;i<=n;i++){
    v[i]=V[i-1]+v[i-1];
  }
  if(v[n]<=m)return n;
  for(i=n-1;i>0;i--){
    int b=n,a=n-i;
    while(a>=0){
      if(v[b]-v[a]>m)break;
      if(!a) {
        return i;
        break;
      }
      a--; b--;
    }
  }
  return no;
}
