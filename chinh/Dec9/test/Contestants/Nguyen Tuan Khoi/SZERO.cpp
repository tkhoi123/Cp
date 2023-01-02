#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "SZERO"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,a[maxn],pref[maxn],ans=0;
int main()
{
    unordered_map<ll,ll>mp;
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    mp[0]=0;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        pref[i]+=a[i]+pref[i-1];
        if(mp.count(pref[i]))
        {
            ans=max(i-mp[pref[i]],ans);
        }
        else
        {
            mp[pref[i]]=i;
        }
    }
    cout<<ans;
    return 0;
}
