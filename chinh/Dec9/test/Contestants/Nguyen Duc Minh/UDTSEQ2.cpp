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
const ll MOD = 1e9;

int n,m;
ll a[mxn+10],b[mxn+10],s[mxn+10];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("inp.txt","r",stdin);
    freopen("UDTSEQ2.INP","r",stdin); freopen("UDTSEQ2.OUT","w",stdout);
    cin >> n >> m;
    while (m--){
        ll i,j,k; cin >> i >> j >> k;
        a[i] = (a[i] + k) % MOD;
        a[j+1] = (a[j+1] - (j-i+2) * k) % MOD;
        a[j+2] = (a[j+2] + (j-i+1) * k) % MOD;
    }
    for (int i=1; i<=n; i++){
        b[i] = (a[i] + b[i-1]) % MOD;
        s[i] = (b[i] + s[i-1]) % MOD;
        if (s[i] >= 0)
            cout << s[i];
        else
            cout << (MOD + s[i]) % MOD;
        cout << ' ';
    }
    return 0;
}

