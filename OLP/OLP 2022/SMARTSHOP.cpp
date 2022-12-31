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
const ll maxn=100001;
ll n,m,low,high,temp;
vi a;
bool check(ll x)
{
    if(1073741824ll%x==0||1162261467ll%x==0||1220703125ll%x==0)
    {
        return true;
    }
    return false;
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    while(n--)
    {
        cin>>temp;
        if(temp!=0&&check(temp))
        {
            a.pb(temp);
        }
    }
    sort(all(a));
    while(m--)
    {
        cin>>low>>high;
        auto it=lower_bound(all(a),low);
        auto it2=upper_bound(it,a.end(),high);
        cout<<it2-it;el;
    }
    return 0;
}
