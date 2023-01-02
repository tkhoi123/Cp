#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "PS"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,a[maxn],pref[maxn],ans=0,left1=0,right1=0;
map<ll,ll>mp;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    mp[0]=0;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        pref[i]+=a[i]+pref[i-1];
        for(auto qq:mp)
        {
            if(qq.first<pref[i])
            {
                ll temp=i-qq.second;
                if(temp>ans)
                {
                    ans=temp;
                    left1=qq.second+1;
                    right1=i;
                }
            }
            else
            {
                break;
            }
        }
        if(!mp.count(pref[i]))
        {
            mp[pref[i]]=i;
        }
    }
    cout<<left1<<" "<<right1;
    return 0;
}
