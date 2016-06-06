#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

const int LIM = 32769;
int lim[LIM], w[LIM];
void bt(int m, int s, int d){
	if(s >= LIM) return;
	++w[s];
	if(d == 4) return;
	for(int i = m; i < lim[s]; ++i) bt(i, s + i*i, d + 1);
}
int main(void){
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, tmp;
	for(int i = 0; i < LIM; ++i) w[i] = 0, lim[i] = floor(sqrt(LIM - i) + 1);
	bt(1, 0, 0);
	cin >> n;
	for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cout << w[tmp] << " ";
    }
    cout << endl;
}
