#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn=1000;
bool check[maxn][maxn];
ll n,m,a[1000][1000];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<m;++j)
        {
            cin>>a[i][j];
        }
    }
    for(ll i=0;i<n;++i)
    {
        ll cur=0;
        for(ll j=0;j<m;++j)
        {
            if(a[i][j]>cur)
            {
                check[i][j]=1;
                cur=a[i][j];
            }
        }
    }
    for(ll j=0;j<m;++j)
    {
        ll cur=0;
        for(ll i=0;i<n;++i)
        {
            if(a[i][j]>cur)
            {
                check[i][j]=1;
                cur=a[i][j];
            }
        }
    }
    for(ll i=0;i<n;++i)
    {
        ll cur=0;
        for(ll j=m-1;j>=0;--j)
        {
            if(a[i][j]>cur)
            {
                check[i][j]=1;
                cur=a[i][j];
            }
        }
    }
    for(ll j=0;j<m;++j)
    {
        ll cur=0;
        for(ll i=n-1;i>=0;--i)
        {
            if(a[i][j]>cur)
            {
                check[i][j]=1;
                cur=a[i][j];
            }
        }
    }
    ll res=0;
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<m;++j)
        {
            res+=check[i][j];
        }
    }
    cout<<res;
    return 0;
}
