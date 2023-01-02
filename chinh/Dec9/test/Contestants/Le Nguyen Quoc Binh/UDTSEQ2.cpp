#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5,MOD = 1e9;
ll n,m,a[LIMIT],b[LIMIT],s[LIMIT],i,j,k;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    freopen("UDTSEQ2.INP","r",stdin);
    freopen("UDTSEQ2.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> i >> j >> k;

        // Truy van 1
        a[i] = (a[i]+k) % MOD;
        a[j+1] = (a[j+1] - k) % MOD;

        // Truy van 2
        a[j+1] = (a[j+1] - (j-i+1)*k) % MOD;
        a[j+2] = (a[j+2] + (j-i+1)*k) % MOD;
    }
    for(int i=1;i<=n;i++)
    {
        b[i] = (b[i-1] + a[i]) % MOD;
        s[i] = (s[i-1] + b[i] + MOD) % MOD;
    }
    for(int i=1;i<=n;i++)
        cout << s[i] << " ";
}
