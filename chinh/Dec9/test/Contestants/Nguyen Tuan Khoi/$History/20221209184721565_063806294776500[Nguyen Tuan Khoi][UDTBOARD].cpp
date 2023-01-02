#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "UDTBOARD"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,m,q,a[555][555];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m>>q;
    for(ll i=1;i<=q;++i)
    {
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        a[x1][y1]+=1;
        a[x1][y2+1]-=1;
        a[x2+1][y1]-=1;
        a[x2+1][y2+1]+=1;
    }
    for(ll i=1;i<=n;++i)
    {
        for(ll j=1;j<=m;++j)
        {
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            cout<<a[i][j]<<" ";
        }
        el;
    }
    return 0;
}
