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

int n;
vector <int> o,e;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("SORTF.INP","r",stdin); freopen("SORTF.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i<=n; i++){
        int a; cin >> a;
        if (a % 2 == 0)
            e.pb(a);
        else
            o.pb(a);
    }
    sort(e.begin(), e.end()); sort(o.begin(), o.end());
    for (int i=0; i<(int)e.size(); i++) cout << e[i]<<' ';
    for (int i=(int)o.size()-1; i>=0; i--) cout << o[i]<<' ';
    return 0;
}
