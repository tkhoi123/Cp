#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define el cout<<"\n"
using namespace std;
using ll = long long;
const ll MOD=998244353;
vector<vector<ll>>base{{0,0,1},{1,1,0},{0,1,1}};
vector<vector<ll>>basec {{0,0,1},{1,1,0},{0,1,1}};
vector<vector<ll>>temp{{1,0,0},{0,1,0},{0,0,1}};
vector<vector<ll>>tempc{{1,0,0},{0,1,0},{0,0,1}};
vector<vector<ll>>ans{{1,0,0},{0,0,0},{1,0,0}};
vector<ll>a;
void mul(vector<vector<ll>>&a,vector<vector<ll>>&b)
{
    vector<vector<ll>>res(sz(a),vector<ll>(sz(a)));
    for(ll i=0; i<sz(a); ++i)
    {
        for(ll j=0; j<sz(a); ++j)
        {
            for(ll z=0; z<sz(a); ++z)
            {
                res[i][j]+=a[z][j]*b[i][z];
            }
        }
    }
    for(ll i=0; i<sz(a); ++i)
    {
        for(ll j=0; j<sz(a); ++j)
        {
            a[i][j]=res[i][j]%MOD;
        }
    }
}
void fibo(ll i,ll n)
{
    base=basec;
    temp=tempc;
    --i;
    n=(n-1)/2-(i-1)/2;
    while(n>0)
    {
        if(n&1)
        {
            mul(temp,base);
        }
        mul(base,base);
        n/=2;
    }
    mul(ans,temp);
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll n,m;
    cin>>n>>m;
    if(n<=2)
    {
        cout<<ans[n][0];
        return 0;
    }
    for(ll i=1; i<=m; ++i)
    {
        ll te;
        cin>>te;
        a.push_back(te);
    }
    sort(a.begin(),a.end(),greater<ll>());
    while(sz(a)&&a.back()<=2)
    {
        ans[a.back()][0]=0;
        a.pop_back();
    }
    ll i=3;
    while(sz(a))
    {
        fibo(i,a.back());
        if(a.back()%2==0)
        {
            ans[2][0]=0;
        }
        if(a.back()%2==1)
        {
            ans[1][0]=0;
        }
        i=a.back()+1;
        a.pop_back();
    }
    fibo(i,n);
    ll idx;
    (n&1)?idx=1:idx=2;
    cout<<ans[idx][0];
    return 0;
}
