#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "GAME"
using namespace std;
using ll = long long;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100000;
ll n,w,dp[3001],can=0;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>>q[3001];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(NAME".INP","r",stdin);
    freopen(NAME".OUT","w",stdout);
    cin>>n>>w;
    ll m,e,s;
    for(ll i=0;i<n;++i)
    {
        cin>>m>>e>>s;
        q[m].push({e,s});
    }
    for(ll i=1; i<=3000; ++i)
    {
        while(sz(q[i])&&q[i].top().first>can)
        {
            e=q[i].top().first;
            s=q[i].top().second;
            q[i].pop();
            bool check=false;
            for(ll j=w; j>=i; --j)
            {
                if(dp[j-i]+e>dp[j])
                {
                    dp[j]=dp[j-i]+e;
                    check=true;
                }
            }
            if(check==false)
            {
                can=max(can,e);
                break;
            }
            if(e-s>can)
            {
                q[i].push({e-s,s});
            }
        }
    }
    cout<<dp[w];
    return 0;
}
