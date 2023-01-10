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
ll gt[21],nen[22];
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll rand(ll a,ll b)
//{
//    return uniform_int_distribution<ll>(a,b)(rng);
//}
ll res(ll l,ll r)
{
    ll num=0;
    ll temp=0;
    for(ll i=20;i>=1;--i)
    {
        ll div=r/gt[i]-(l-1)/gt[i];
        num+=(div-temp)*(nen[i+1]+1);
        temp=div;
    }
    return num;
}
//ll trau(ll l,ll r)
//{
//    ll num=0;
//    for(ll i=l;i<=r;++i)
//    {
//        ll temp=i;
//        while(temp>2)
//        {
//            for(ll i=2;i<temp;++i)
//            {
//                if(temp%i!=0)
//                {
//                    temp=i;
//                    break;
//                }
//            }
//            ++num;
//        }
//    }
//    return num;
//}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    gt[1]=1;
    for(ll i=2;i<=20;++i)
    {
        gt[i]=gt[i-1]*i/(__gcd(gt[i-1],i));
    }
    for(ll i=3;i<=21;++i)
    {
        ll num=0;
        ll temp=i;
        while(temp>2)
        {
            for(ll i=2;i<temp;++i)
            {
                if(temp%i!=0)
                {
                    temp=i;
                    break;
                }
            }
            ++num;
        }
        nen[i]=num;
    }
    ll l,r;
    cin>>l>>r;
    cout<<res(l,r);
//Sinh test sub1
//    for(;;)
//    {
//        ll l=rand(3,1e6),r=rand(l,1e6);
//        ll r_trau=trau(l,r),r_ans=res(l,r);
//        if(r_trau==r_ans)
//        {
//            cout<<"CORRECT "<<l<<" "<<r<<" "<<r_trau;el;
//        }
//        else
//        {
//            cout<<"UNCORRECT "<<l<<" "<<r<<" "<<r_trau<<" "<<r_ans;return 0;
//        }
//    }
    return 0;
}

