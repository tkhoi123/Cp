#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "SUBSEQ"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=1000001;
ll n,k,a[maxn],pref[maxn];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        pref[i]+=pref[i-1]+a[i];
    }
    ll minn=INF*INF,res=-INF*INF;
    for(ll i=k;i<=n;++i)
    {
        minn=min(minn,pref[i-k]);
        res=max(res,pref[i]-minn);
    }
    cout<<res;
    return 0;
}
