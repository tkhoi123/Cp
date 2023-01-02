#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxN = 1e5+2;
int n,k,res=1;
string a[maxN];

void init()
{
    freopen("BAGGER.INP","r",stdin); freopen("BAGGER.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    sort(a,a+n);
    int cnt = 1;
    for(int i=0;i<n-1;i++)
    {
        if(i < n-1)
        {
            if(a[i] == a[i+1]) {
                cnt++;
            }
            else
            {
                res++;
                cnt = 1;
            }
            if(cnt > k)
            {
                res++;
                cnt = 1;
            }
        }
    }
    cout << res;
}

int main()
{
    init();
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    solve();
}
