#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int M, T, R;
int W[10000001];

deque<int> deq;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d %d %d", &M, &T, &R);

    for(int Mi = 0; Mi < M; Mi++)
        scanf("%d", &W[Mi]);

    if( R > T ){ puts("-1"); return 0; }

    int Ans = 0;

    for(int Mi = 0; Mi < M; Mi++)
    {
        while( !deq.empty() && W[Mi]-deq.front()+1 > T )
            deq.pop_front();

        int sp = max(R-(int)deq.size(), 0);

        for(int si = 1; si <= sp; si++)
            deq.push_back(W[Mi]-sp+si), Ans++;
    }

    printf("%d\n", Ans);
}
