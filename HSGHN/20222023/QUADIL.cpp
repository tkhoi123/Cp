//18/20 testcase
//3/4 subtask
#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "QUADIL"
using namespace std;
using ll = long long;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
struct point{
    ll x,y;
};
ll n,ans=0;
point p[maxn];
pii vecto(point a,point b)
{
    return {b.x-a.x,b.y-a.y};
}
ll tinh(point a,point b,point c)
{
    pii v1=vecto(a,b);
    pii v2=vecto(a,c);
    return abs(v1.first*v2.second-v1.second*v2.first);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;++i)
    {
        cin>>p[i].x>>p[i].y;
    }
    for(ll i=1;i<=n;++i)
    {
        for(ll j=i+2;j<=n;++j)
        {
            //tgiactrong
            ll low=i+1,high=j-1,tgiactrong=0;
            while(high-low>1)
            {
                ll mid=(low+high)>>1;
                ll temp1=tinh(p[i],p[j],p[mid]),temp2=tinh(p[i],p[j],p[mid+1]);
                if(temp1>temp2)
                {
                    high=mid;
                }
                else
                {
                    if(temp1<temp2)
                    {
                        low=mid+1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for(ll z=low;z<=high;++z)
            {
                tgiactrong=max(tgiactrong,tinh(p[i],p[j],p[z]));
            }
            //tgiacngoai
            low=1;high=i-1;
            ll tgiacngoai=0;
            while(high-low>1)
            {
                ll mid=(low+high)>>1;
                ll temp1=tinh(p[i],p[j],p[mid]),temp2=tinh(p[i],p[j],p[mid+1]);
                if(temp1>temp2)
                {
                    high=mid;
                }
                else
                {
                    if(temp1<temp2)
                    {
                        low=mid+1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for(ll z=low;z<=high;++z)
            {
                tgiacngoai=max(tgiacngoai,tinh(p[i],p[j],p[z]));
            }
            low=1,high=i-1,tgiacngoai=0;
            while(high-low>1)
            {
                ll mid=(low+high)>>1;
                ll temp1=tinh(p[i],p[j],p[mid]),temp2=tinh(p[i],p[j],p[mid+1]);
                if(temp1>temp2)
                {
                    high=mid;
                }
                else
                {
                    if(temp1<temp2)
                    {
                        low=mid+1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            for(ll z=low;z<=high;++z)
            {
                tgiacngoai=max(tgiacngoai,tinh(p[i],p[j],p[z]));
            }
            ans=max(ans,tgiacngoai+tgiactrong);
        }
    }
    cout<<ans/2;
    if(ans&1)
    {
        cout<<".5";
    }
    else
    {
        cout<<".0";
    }
    return 0;
}
