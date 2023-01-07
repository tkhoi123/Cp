//15/20 test case
//3/4 subtask
#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "SCHEDU"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,m,x,y;
vii a,b;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m;
    for(ll i=0;i<n;++i)
    {
        cin>>x>>y;
        if(x>=y)
        {
            a.pb({x,y});
        }
        else
        {
            b.pb({x,y});
        }
    }
    sort(all(b));
    sort(all(a),[](pii a,pii b){return a.second>b.second;});
    ll t1=0,t2=0;
    for(auto pa:b)
    {
        t1+=pa.first;
        t2=max(t1,t2)+pa.second;
    }
    for(auto pa:a)
    {
        t1+=pa.first;
        t2=max(t1,t2)+pa.second;
    }
    cout<<t2;
    return 0;
}
