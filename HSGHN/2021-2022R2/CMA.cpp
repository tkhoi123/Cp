//3/4 subtask 
//Chua test
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
ll n,m,k,a[maxn],c[maxn],res=0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    //freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m>>k;
    map<ll,ll>cnt;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        ++cnt[a[i]];
    }
    if(m<k)
    {
        cout<<-1;
        return 0;
    }
    for(ll i=1;i<=m;++i)
    {
        cin>>c[i];
    }
    sort(c+1,c+m+1);
    while(sz(cnt)<k)
    {
        ll id_cur=-1,minn=INF,res_cur=-1,res_new=-1;
        for(ll i=1;i<=m;++i)
        {
            if(cnt[c[i]]>1)
            {
                id_cur=i;
            }
            if(id_cur!=-1&&cnt[c[i]]==0)
            {
                if(minn>c[i]-c[id_cur])
                {
                    minn=c[i]-c[id_cur];
                    res_cur=id_cur;
                    res_new=i;
                }
                id_cur=-1;
            }
        }
        res+=c[res_new]-c[res_cur];
        --cnt[c[res_cur]];
        ++cnt[c[res_new]];
    }
    cout<<res;
    return 0;
}

