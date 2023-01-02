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

const int mxn = 1e5+10;

int n,k,a[mxn];
vector <ll> v;
ll res;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("DARR.INP","r",stdin); freopen("DARR.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    ll s = a[n];
    for (int i=n-1; i>1; i--){
        s += a[i];
        v.pb(s);
    }
    s += a[1];
    sort(v.begin(), v.end(), greater<ll>());
    res = s;
    for (int i=0; i<k-1; i++){
        res += v[i];
    }
    cout << res;
    return 0;
}
