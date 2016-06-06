#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

const int MAX = 1 << 15;
char buff[4096], *p;
int sqr[192], ways[1<<15];

int main() {
    #ifdef EVAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

	int n, i, j, k, l, tmp;
	for(i = 0; i < 192; i++) sqr[i] = i*i;
	for(i = 0; 4*sqr[i] < MAX; i++)
		for(j = i; sqr[i]+3*sqr[j] < MAX; j++)
			for(k = j; sqr[i]+sqr[j]+2*sqr[k] < MAX; k++)
				for(l = k; sqr[i]+sqr[j]+sqr[k]+sqr[l] < MAX; l++)
					ways[sqr[i]+sqr[j]+sqr[k]+sqr[l]]++;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        cout << ways[tmp] << " ";
    }
    cout << endl;
	return 0;
}
