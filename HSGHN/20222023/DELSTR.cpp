#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "DELSTR"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll m,k,ans=INF,sz=1;
string s;
map<ll,ll>mp;
ll gmin()
{
    ll res=INF;
    for(auto pa:mp)
    {
        res=min(pa.second,res);
    }
    return res;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    cin>>m>>k>>s;
    ll l=0,r=-1;
    while(l<sz(s))
    {
        while(r+1<sz(s)&&(sz(mp)<m||gmin()<k))
        {
            ++mp[s[++r]];
        }
        if(sz(mp)==m&&gmin()>=k)
        {
            ans=min(ans,r-l+1);
        }
        if(mp[s[l]]==1)
        {
            mp.erase(s[l]);
        }
        else
        {
            --mp[s[l]];
        }
        ++l;
    }
    cout<<ans-m*k;
    return 0;
}
