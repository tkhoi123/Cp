#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
ll n,m,a[LIMIT],i,j,k;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(a,0,sizeof(a));
    freopen("UDTSEQ.INP","r",stdin);
    freopen("UDTSEQ.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n >> m;
    while(m--)
    {
        cin >> i >> j >> k;
        a[i] += k;
        a[j+1] -= k;
    }
    for(int i=1;i<=n;i++)
    {
        a[i] = a[i] + a[i-1];
    }
    for(int i=1;i<=n;i++) cout << a[i] << " ";
}
