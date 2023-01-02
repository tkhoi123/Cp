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
ll a[mxn+10],b[mxn+10],s[mxn+10];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("UDTSEQ2.INP","r",stdin); freopen("UDTSEQ2.OUT","w",stdout);
    cin >> n >> m;
    while (m--){
        int i,j,k; cin >> i >> j >> k;
        a[i] += k; a[j+1] -= (j-i+2) * k; a[j+2] += (j-i+1) * k;
    }
    for (int i=1; i<=n; i++){
        b[i] = a[i] + b[i-1];
        s[i] = b[i] + s[i-1];
        cout << s[i] << ' ';
    }
    return 0;
}

