#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define sqr(x) ((x) * (x))
#define NAME "GOLF"
using namespace std;
using ll = int;
using ld = long double;
const ll INF=1000000000;
typedef vector<pair<ll,ll>> vii;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
const ll maxn=100001;
ll n,m,k;
pii st,ed;
vector<vector<char>>G;
vector<vi>d;
queue<pii>qu;
void bmove(ll i,ll j,ll dx,ll dy)
{
    ll i1=i,j1=j;
    for(ll z=1;z<=k;++z)
    {
        i1+=dx;
        j1+=dy;
        if(i1>=n||j1>=m||i1<0||j1<0||d[i1][j1]<d[i][j]+1||G[i1][j1]=='#')break;
        if(d[i1][j1]>d[i][j]+1)
        {
            qu.push({i1,j1});
        }
        d[i1][j1]=d[i][j]+1;
    }
}
void dfs(ll i,ll j)
{
    d[i][j]=0;
    qu.push({i,j});
    while(sz(qu))
    {
        ll i1=qu.front().first,j1=qu.front().second;qu.pop();
        bmove(i1,j1,0,-1);
        bmove(i1,j1,0,1);
        bmove(i1,j1,-1,0);
        bmove(i1,j1,1,0);
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>n>>m>>k;
    vector<char>temp(m);
    d.assign(n,vector<ll>(m,INF));
    for(ll i=0;i<n;++i)
    {
        for(ll j=0;j<m;++j)
        {
            cin>>temp[j];
            if(temp[j]=='S')
            {
                ed.first=i;ed.second=j;
            }
            if(temp[j]=='G')
            {
                st.first=i,st.second=j;
            }
        }
        G.pb(temp);
    }
    dfs(ed.first,ed.second);
    cout<<d[st.first][st.second];
    return 0;
}
