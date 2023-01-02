#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define NAME "COUNTSEQ"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=2222222;
ll n,pref[maxn],ans=0,q[maxn];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    cin>>n;
    string s;
    cin>>s;
    q[0]=1;
    for(ll i=0; i<sz(s); ++i)
    {
        if(i==0)
        {
            pref[i]=(s[i]=='1');
        }
        else
        {
            pref[i]+=pref[i-1]+(s[i]=='1');
        }
        if(pref[i]>=n)
        {
            ans+=q[pref[i]-n];
        }
        ++q[pref[i]];
    }
    cout<<ans;
    return 0;
}
