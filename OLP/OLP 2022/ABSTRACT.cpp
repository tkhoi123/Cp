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
ll n,x[4],y[4],xx[4],yy[4],ans=0;
vector<ll>kc[4];
vector<ll>temp[4];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    for(ll i=0; i<4; ++i)
    {
        cin>>x[i]>>y[i];
    }
    for(ll i=0; i<4; ++i)
    {
        for(ll j=0; j<4; ++j)
        {
            if(i==j)continue;
            kc[i].pb(abs(x[j]-x[i])+abs(y[j]-y[i]));
        }
        sort(all(kc[i]));
    }
    cin>>n;
    while(n--)
    {
        for(ll i=0; i<4; ++i)
        {
            cin>>xx[i]>>yy[i];
            temp[i].clear();
        }
        ll dem=0,dau;
        for(ll i=0; i<2; ++i)
        {
            for(ll j=0; j<4; ++j)
            {
                if(i==j)continue;
                temp[i].pb(abs(xx[j]-xx[i])+abs(yy[j]-yy[i]));
            }
            sort(all(temp[i]));
            for(ll z=0; z<4; ++z)
            {
                bool check=true;
                if(dem==1&&dau==z)continue;
                for(ll k=0;k<sz(temp[i]);++k)
                {
                    if(kc[z][k]!=temp[i][k])
                    {
                        check=false;
                    }
                }
                if(check)
                {
                    ++dem;
                    dau=z;
                    break;
                }
            }
        }
        if(dem>=2)
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
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
ll n,x[4],y[4],xx[4],yy[4],ans=0;
vector<ll>kc[4];
vector<ll>temp[4];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    for(ll i=0; i<4; ++i)
    {
        cin>>x[i]>>y[i];
    }
    for(ll i=0; i<4; ++i)
    {
        for(ll j=0; j<4; ++j)
        {
            if(i==j)continue;
            kc[i].pb(abs(x[j]-x[i])+abs(y[j]-y[i]));
        }
        sort(all(kc[i]));
    }
    cin>>n;
    while(n--)
    {
        for(ll i=0; i<4; ++i)
        {
            cin>>xx[i]>>yy[i];
            temp[i].clear();
        }
        ll dem=0,dau;
        for(ll i=0; i<2; ++i)
        {
            for(ll j=0; j<4; ++j)
            {
                if(i==j)continue;
                temp[i].pb(abs(xx[j]-xx[i])+abs(yy[j]-yy[i]));
            }
            sort(all(temp[i]));
            for(ll z=0; z<4; ++z)
            {
                bool check=true;
                if(dem==1&&dau==z)continue;
                for(ll k=0;k<sz(temp[i]);++k)
                {
                    if(kc[z][k]!=temp[i][k])
                    {
                        check=false;
                    }
                }
                if(check)
                {
                    ++dem;
                    dau=z;
                    break;
                }
            }
        }
        if(dem>=2)
        {
            ++ans;
        }
    }
    cout<<ans;
    return 0;
}
