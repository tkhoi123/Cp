#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "WATERING"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,h[maxn];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>h[i];
    }
    ll start=1,res=0;
    while(start<=n)
    {
        while(start+1<=n&&h[start]<=h[start+1])
        {
            ++start;
        }
        while(start+1<=n&&h[start]>=h[start+1])
        {
            ++start;
        }
        ++res;
        ++start;
    }
    cout<<res;
    return 0;
}
