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
const int INF = 1e9;

vector <int> pr;
int lp[mxn+10],a,k;
vector <pii> num;

void sieve()
{
    for (int i=2; i<=mxn; i++){
        if (lp[i] == 0){
            lp[i] = i;
            pr.pb(i);
        }
        for (int j=0; 1LL*i*pr[j] <= mxn; j++){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

void calc_pow()
{
    num.clear();
    while (a > 1){
        int d = lp[a];
        int cnt = 0;
        while (a % d == 0){
            cnt++;
            a /= d;
        }
        num.pb(mp(d, cnt*k));
    }
}

bool check(ll f)
{
    for (auto p : num){
        ll u = p.fi; ll v = p.se;
        ll cnt = 0;
        for (; f/u >= 1; u*=p.fi){
            cnt += f/u;
        }
        if (cnt < v) return 0;
    }
    return 1;
}

ll chop(ll lo, ll hi)
{
    ll res = -1;
    while (lo <= hi){
        ll mid = (lo + hi)/2;
        if (check(mid)){
            res = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return res;
}

void solve()
{
    cin >> a >> k;
    calc_pow();
    cout << chop(0LL, (ll)1e18);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("MINFACT.INP","r",stdin); freopen("MINFACT.OUT","w",stdout);
    sieve();
    int t; cin >> t;
    while (t--){
        solve();
        cout << '\n';
    }
    return 0;
}

