#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "SORTF"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n;
vi chan,le;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        ll temp;
        cin>>temp;
        if(temp%2==0)
        {
            chan.pb(temp);
        }
        else
        {
            le.pb(temp);
        }
    }
    sort(all(chan));
    sort(all(le),greater<ll>());
    for(auto a:chan)
    {
        cout<<a<<" ";
    }
    for(auto a:le)
    {
        cout<<a<<" ";
    }
    return 0;
}
