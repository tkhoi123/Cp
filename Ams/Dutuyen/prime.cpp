#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define NAME "temp"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,pref[maxn];
bool check[maxn];
vi ngto;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    for(ll i=4;i<=maxn;i+=2)
    {
        check[i]=true;
    }
    ngto.pb(2);
    for(ll i=3;i<=maxn;i+=2)
    {
        if(i*i<=maxn&&check[i]==false)
        {
            for(ll j=i*i;j<=maxn;j+=2*i)
            {
                check[j]=true;
            }
        }
        if(check[i]==false)
        {
            ngto.pb(i);
        }
    }
    for(ll i=0;i<sz(ngto);++i)
    {
        if(i==0)
        {
            pref[i]=ngto[i];
        }
        else
        {

        pref[i]+=pref[i-1]+ngto[i];
        }
    }
    cin>>n;
    while(n--)
    {
        ll l,r,val,ans=0;
        cin>>l>>r>>val;
        ll bdau=lower_bound(all(ngto),l)-ngto.begin();
        ll ket=upper_bound(all(ngto),r)-ngto.begin();
        ll lhon=lower_bound(ngto.begin()+bdau,ngto.begin()+ket,val)-ngto.begin();
        --ket;
        ans+=pref[ket]-pref[lhon-1]-(ket-lhon+1)*val;
        ans+=-pref[lhon-1]+pref[bdau-1]+val*(lhon-bdau);
        cout<<ans;el;
    }
    return 0;
}
