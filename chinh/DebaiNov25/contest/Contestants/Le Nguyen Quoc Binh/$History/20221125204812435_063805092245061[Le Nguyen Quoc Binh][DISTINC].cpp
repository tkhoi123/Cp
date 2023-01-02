#include <bits/stdc++.h>
#define ll long long
#define mii map<long long,int>
using namespace std;

const int maxN = 3*1e5+2;
int n,k,res = INT_MAX;
ll a[maxN];
bool flag = false;
mii m;

void init()
{
    freopen("DISTINC.INP","r",stdin); freopen("DISTINC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int i = 0,cnt=0;
    for(int j=0;j<n;j++)
    {
        if(cnt == k)
        {
            if(m[a[j]] == 0) cnt++;
            m[a[j]]++;
            m[a[i]]--;
            if(m[a[i]] == 0) cnt--;
            i++;
            if(cnt == k) res = min(res,j-i+1);
        }
        else
        {
            if(m[a[j]] == 0) cnt++;
            m[a[j]]++;
            if(cnt == k)
            {
                res = min(res,j-i+1);
            }
        }
    }
    if(res == INT_MAX) cout << -1;
    else cout << res;
}

int main()
{
    init();
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    solve();
}


