#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "MAXNUM"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n;
bool cmp(string &a,string &b)
{
    if(sz(a)<sz(b))
    {
        swap(a,b);
    }
    ll temp=min(sz(a),sz(b));
    for(ll i=0;i<temp;++i)
    {
        if(a[i]!=b[i])
        {
            return a[i]>b[i];
        }
    }
    return a[temp]>b[0];
}
vector<string>a;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
//    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    for(ll i=0;i<n;++i)
    {
        string temp;
        cin>>temp;
        a.pb(temp);
    }
    sort(all(a),cmp);
    string ans;
    for(ll i=0;i<n;++i)
    {
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}
