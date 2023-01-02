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

const int mxn = 2e6+10;

int k,a[mxn];
ll res;
string s;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("COUNTSEQ.INP","r",stdin); freopen("COUNTSEQ.OUT","w",stdout);
    cin >> k;
    cin >> s;
    int n = s.length();
    s = '!'+s;
    for (int i=1; i<=n; i++){
        a[i] = a[i-1];
        if (s[i] == '1') a[i]++;
    }
    res = 0;
    for (int i=1; i<=n; i++){
        int p1 = lower_bound(a+i, a+n+1, a[i-1] + k) - a;
        int p2 = upper_bound(a+i, a+n+1, a[i-1] + k) - a; p2--;
        res += max(p2-p1+1, 0);
    }
    cout << res;
    return 0;
}
