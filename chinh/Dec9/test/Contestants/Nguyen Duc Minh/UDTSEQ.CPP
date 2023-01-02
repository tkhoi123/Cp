// vegnim
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setpre(n) fixed << setprecision(n)

const int mxn = 1e5;

int n,m;
ll a[mxn+10],b[mxn+10];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("UDTSEQ.INP","r",stdin); freopen("UDTSEQ.OUT","w",stdout);
    cin >> n >> m;
    while (m--){
        int i,j,k; cin >> i >> j >> k;
        b[i] += k; b[j+1] -= k;
    }
    for (int i=1; i<=n; i++){
        a[i] = b[i] + a[i-1];
        cout << a[i] << ' ';
    }
    return 0;
}
