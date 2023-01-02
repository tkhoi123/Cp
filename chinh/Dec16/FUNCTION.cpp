#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "FUNCTION"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll a,b,c,d;
ld f(ld x)
{
    return a*x*x*x+b*x*x+c*x+d;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>a>>b>>c>>d;
    ld l=-1e6,r=1e6,ep=1e-9;
    while(r-l>ep)
    {
        ld mid=(l+r)/2;
        if(f(l)*f(mid)>0)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    cout<<fixed<<setprecision(9)<<l;
    return 0;
}
