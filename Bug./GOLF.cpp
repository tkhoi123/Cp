//https://hnoj.edu.vn/problem/hnoi2022_r2_golf
#include <bits/stdc++.h>
#define el cout<<"\n"
#define pb push_back
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define NAME "GOLF"
using namespace std;
using ll = long long;
const ll INF=1000000000;
ll r,c,k,ey,ex;
vector<vector<char>>a;
void bfs(ll xx,ll yy)
{
    vector<vector<ll>>d(r,vector<ll>(c,INF));
    queue<pair<ll,ll>>q;
    q.push({xx,yy});
    d[xx][yy]=0;
    while(sz(q))
    {
        ll x=q.front().fi,y=q.front().se;
        q.pop();
        ll i=x+1,j=y;
        while(i>=0&&i<r&&j>=0&&j<c&&a[i][j]!='#'&&d[i][j]==INF&&x+k>=i)
        {
            q.push({i,j});
            d[i][j]=d[x][y]+1;
            ++i;
        }
        i=x-1,j=y;
        while(i>=0&&i<r&&j>=0&&j<c&&a[i][j]!='#'&&d[i][j]==INF&&x-k<=i)
        {
            q.push({i,j});
            d[i][j]=d[x][y]+1;
            --i;
        }
        i=x,j=y+1;
        while(i>=0&&i<r&&j>=0&&j<c&&a[i][j]!='#'&&d[i][j]==INF&&y+k>=j)
        {

            q.push({i,j});
            d[i][j]=d[x][y]+1;
            ++j;
        }
        i=x,j=y-1;
        while(i>=0&&i<r&&j>=0&&j<c&&a[i][j]!='#'&&d[i][j]==INF&&y-k<=j)
        {
            q.push({i,j});
            d[i][j]=d[x][y]+1;
            --j;
        }

    }
    cout<<d[ex][ey];
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    freopen(NAME".INP","r",stdin);freopen(NAME".OUT","w",stdout);
    cin>>r>>c>>k;
    a.resize(r);
    ll stx,sty;
    for(ll i=0;i<r;++i)
    {
        for(ll j=0;j<r;++j)
        {
            char te;
            cin>>te;
            a[i].pb(te);
            if(te=='S')
            {
                stx=i;
                sty=j;
            }
            if(te=='G')
            {
                ex=i;
                ey=j;
            }
        }
    }
    bfs(stx,sty);
    return 0;
}
