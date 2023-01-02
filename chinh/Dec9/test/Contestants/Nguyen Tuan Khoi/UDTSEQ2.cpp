#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "UDTSEQ2"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100005;
ll n,m,a[maxn],b[maxn],s[maxn];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<m;++i)
    {
        ll l,r,k;
        cin>>l>>r>>k;
        a[l]+=k;
        a[r+1]%=INF;
        a[r+1]-=k;
        a[r+1]-=(r-l+1)*k%INF;
        a[r+2]+=(r-l+1)*k%INF;
        a[r+2]%=INF;
    }
    for(ll i=1;i<=n;++i)
    {
        b[i]+=(b[i-1]+a[i])%INF;
        b[i]%=INF;
        s[i]+=(s[i-1]+b[i]+INF)%INF;
        cout<<s[i]<<" ";
    }
    return 0;
}
