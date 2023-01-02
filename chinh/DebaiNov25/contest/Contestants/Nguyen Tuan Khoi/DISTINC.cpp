#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define NAME "DISTINC"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=200001;
ll n,k,a[maxn],ans=INF;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>k;
    for(ll i=0;i<n;++i)
    {
        cin>>a[i];
    }
    ll l=0,r=-1;
    map<ll,ll>q;
    while(r+1<n)
    {
        ++q[a[++r]];
        while(sz(q)>k&&l<=r)
        {
            --q[a[l]];
            if(q[a[l]]==0)
            {
                q.erase(a[l]);
            }
            ++l;
        }
        while(sz(q)==k&&q[a[l]]>1)
        {
            --q[a[l]];
            if(q[a[l]]==0)
            {
                q.erase(a[l]);
            }
            ++l;
        }
        if(sz(q)==k&&l<=r)
        {
            ans=min(ans,r-l+1);
        }
    }
    if(ans==INF)
    {
        cout<<-1;
        exit(0);
    }
    cout<<ans;
    return 0;
}
