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

const int mxn = 500;

int m,n,q,a[mxn+2][mxn+2],h[mxn+2][mxn+2];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("UDTBOARD.INP","r",stdin); freopen("UDTBOARD.OUT","w",stdout);
    cin >> m >> n >> q;
    while (q--){
        int a,b,c,d; cin >> a >> b >> c >> d;
        for (int i=a; i<=c; i++){
            h[i][b]++; h[i][d+1]--;
        }
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            a[i][j] = h[i][j] + a[i][j-1];
            cout << a[i][j]<<' ';
        }
        cout << '\n';
    }
    return 0;
}

