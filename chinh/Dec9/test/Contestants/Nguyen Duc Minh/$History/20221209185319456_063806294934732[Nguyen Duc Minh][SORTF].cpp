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

int n,a[mxn+1];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("SORTF.INP","r",stdin); freopen("SORTF.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i<=n; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1, [&](int lo, int hi){
        if ((lo + hi) % 2 != 0)
            return (lo % 2 == 0);

        else{
            if (lo % 2 == 0) return (lo <= hi);
            return (lo >= hi);
        }
    });
    for (int i=1; i<=n; i++){
        cout << a[i] << ' ';
    }
    return 0;
}
