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

const int mxn = 1e6;

int n,a[mxn+1];
ll s;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("PS.INP","r",stdin); freopen("PS.OUT","w",stdout);
    cin >> n;
    ll s = 0;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s += a[i];
    }
    int l = 1; int r = n;
    while (l <= r){
        if (s > 0) break;
        if (a[l] < a[r]){
            s -= a[l];
            l++;
        }
        else{
            s -= a[r];
            r--;
        }
    }
    cout << l<<' '<<r;
    return 0;
}
