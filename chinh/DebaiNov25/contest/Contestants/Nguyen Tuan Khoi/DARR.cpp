#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define NAME "DARR"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,k,a[maxn],pref[maxn],ans=0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
    }
    for(ll i=n;i>=1;--i)
    {
        pref[i]+=a[i]+pref[i+1];
    }
    ans+=pref[1];
    sort(pref+2,pref+n+1);
    for(ll i=n;i>n-k+1;--i)
    {
        ans+=pref[i];
    }
    cout<<ans;
    return 0;
}
