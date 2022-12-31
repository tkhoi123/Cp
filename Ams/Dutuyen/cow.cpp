#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define NAME "temp"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,rao=0,m,dem=0,dx[4]= {0,0,1,-1},dy[4]= {1,-1,0,0},Visit[111][111];
char a[111][111];
void dfs(ll x,ll y)
{
            ++rao;
    Visit[x][y]=1;
    for(ll k=0; k<4; ++k)
    {
        ll i1=dx[k]+x,j1=dy[k]+y;
        if(i1>=1&&j1>=1&&j1<=m&&i1<=n&&a[i1][j1]=='0'&&Visit[i1][j1]==0)
        {
            dfs(i1,j1);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m;
    for(ll i=1; i<=n; ++i)
    {
        for(ll j=1; j<=m; ++j)
        {
            cin>>a[i][j];
            if(a[i][j]=='1')
            {
                ++rao;
            }
        }
    }
    for(ll i=1; i<=n; ++i)
    {
        for(ll j=1; j<=m; ++j)
        {
            if((i==1||j==1||i==n||j==m)&&a[i][j]=='0'&&Visit[i][j]==0)
            {
                dfs(i,j);
            }
        }
    }
    cout<<n*m-rao;
    return 0;
}
