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
string s[mxn+1];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("MAXNUM.INP","r",stdin); freopen("MAXNUM.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> s[i];
    }
    sort(s+1, s+n+1, [&](string lo, string hi){
        return (lo + hi) > (hi + lo);
    });
    for (int i=1; i<=n; i++)
        cout << s[i];
    return 0;
}

