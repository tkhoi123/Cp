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

int n,a[mxn+1],res;
ll s[mxn+1];
vector < pair <ll,int> > v;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("SZERO.INP","r",stdin); freopen("SZERO.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        v.pb({s[i], i});
    }
    sort(v.begin(), v.end(), [&](pair <ll,int> lo, pair <ll,int> hi){
        if (lo.fi != hi.fi) return (lo.fi < hi.fi);
        return (lo.se > hi.se);
    });
    res = 0;
    for (int i=1; i<=n; i++){
        pair <ll,int> temp = {s[i-1], 0};
        int pos = lower_bound(v.begin(), v.end(), temp) - v.begin();
        if (pos < (int)v.size() && v[pos].fi == s[i-1] && v[pos].se >= i){
            res = max(res, v[pos].se-i+1);
        }
    }
    cout << res;
    return 0;
}
