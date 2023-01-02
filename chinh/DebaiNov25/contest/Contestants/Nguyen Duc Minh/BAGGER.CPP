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

int n,res;
ll k;
map <string,int> mm;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("BAGGER.INP","r",stdin); freopen("BAGGER.OUT","w",stdout);
    cin >> n >> k;
    while (n--){
        string s; cin >> s;
        mm[s]++;
    }
    res = 0;
    for (auto p : mm){
        res += (1LL*p.se+k-1)/k;
    }
    cout << res;
    return 0;
}
