#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "PRJCHAIN"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,a[maxn],b[maxn],ans=0,sum=0;
struct cviec{
    ll order,chi,thu;
};
vector<cviec>cv1;
vector<cviec>cv2;
bool cmp(cviec p1,cviec p2)
{
    return p1.thu>p2.thu;
}
bool cmp2(cviec p1,cviec p2)
{
    return p1.chi<p2.chi;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    for(ll i=1; i<=n; ++i)
    {
        cin>>a[i];
    }
    for(ll i=1; i<=n; ++i)
    {
        cin>>b[i];
        if(a[i]<=b[i])
        {
            cv1.pb({i,a[i],b[i]});
        }
        else
        {
            cv2.pb({i,a[i],b[i]});
        }
    }
    sort(all(cv1),cmp2);
    sort(all(cv2),cmp);
    for(ll i=0;i<sz(cv1);++i)
    {
        sum-=cv1[i].chi;
        ans=min(sum,ans);
        sum+=cv1[i].thu;
    }
    for(ll i=0;i<sz(cv2);++i)
    {
        sum-=cv2[i].chi;
        ans=min(sum,ans);
        sum+=cv2[i].thu;
    }
    cout<<abs(ans);el;
    for(ll i=0;i<sz(cv1);++i)
    {
        cout<<cv1[i].order<<" ";
    }
    for(ll i=0;i<sz(cv2);++i)
    {
        cout<<cv2[i].order<<" ";
    }
    return 0;
}
