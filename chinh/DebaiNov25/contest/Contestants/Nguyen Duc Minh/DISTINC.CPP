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

const int mxn = 2e5+10;
const int INF = 1e9;

int n,k,res;
ll a[mxn];
map <ll,int> mm;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("DISTINC.INP","r",stdin); freopen("DISTINC.OUT","w",stdout);
    cin >> n >> k;
    if (k == 0){
        cout << 0;
        return 0;
    }
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }
    res = INF;
    int l,r; l = r = 1;
    int cnt = 1;
    mm[a[l]]++;
    while (r <= n){
        if (cnt < k){
            r++;
            mm[a[r]]++;
            if (mm[a[r]] == 1)
                cnt++;
        }
        else{
            res = min(res, r-l+1);
            mm[a[l]]--;
            if (mm[a[l]] == 0)
                cnt--;
            l++;
        }
    }
    if (res == INF) res = -1;
    cout << res;
    return 0;
}

