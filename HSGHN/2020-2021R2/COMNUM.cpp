//3/4 subtask
//Da sinh test cho sub1
#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "temp"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=1001;
ll dp[2][maxn];
string l,r;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>l>>r;
    for(auto &q:l)
    {
        q-='0';
    }
    for(auto &q:r)
    {
        q-='0';
    }
    reverse(all(l));
    while(sz(l)<sz(r))
    {
        l+=char(0);
    }
    reverse(all(l));
    dp[0][0]=max(r[0]-1,1);
    if(r[0]==l[0])
    {
        dp[0][0]=-1;
    }
    dp[1][0]=r[0];
    bool check=l[0]==r[0];
    for(ll i=1; i<sz(r); ++i)
    {
        if(r[i-1]==0||check)
        {
            dp[0][i]=dp[0][i-1]*9;
        }
        else
        {
            dp[0][i]=max(dp[0][i-1]*9,(dp[1][i-1]/r[i-1])*(r[i-1]-1)*9);
        }
        check=check&(r[i]==l[i]);
        dp[1][i]=dp[1][i-1]*r[i];
    }
    cout<<max(dp[0][sz(r)-1],dp[1][sz(r)-1]);
    return 0;
}

