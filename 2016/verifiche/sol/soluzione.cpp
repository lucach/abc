#include <bits/stdc++.h>

#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)

using namespace std;
long long quanti[10000001];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ms(quanti,-1000000);
    int m,t,r;
    cin>>m>>t>>r;
    vector<int>v;
    int num;
    for(int i=0; i<m; i++)
    {
        cin>>num;
        v.pb(num);
    }
    if(t<r)
        cout<<-1<<endl;
    else
    {
        int ans=0;
        for(int i=0; i<m; i++)
        {
            int c=0;
            for(int j=1; j<=r; j++)
                if(quanti[j]+t>=v[i])
                    c++;
            if(c==r) continue;
            else
            {
                c=0;
                for(int j=1; j<=r; j++)
                    if(quanti[j]+t<v[i])
                    {
                        quanti[j]=v[i]-(++c);
                        ans++;
                    }

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
