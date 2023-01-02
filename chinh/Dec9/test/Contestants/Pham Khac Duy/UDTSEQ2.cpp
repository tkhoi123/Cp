#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
const long long MOD = 1e9;
int n, m;
long long a[N], s[N], b[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UDTSEQ2.inp","r",stdin);
    freopen("UDTSEQ2.out","w",stdout);

    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        long long l, r, k;
        cin >> l >> r >> k;

        a[l] = (a[l] + k) % MOD;
        a[r + 1] = (a[r + 1] - k) % MOD;
        a[r + 1] = (a[r + 1] - (r - l + 1) * k) % MOD;
        a[r + 2] = (a[r + 2] + (r - l + 1) * k) % MOD;
    }

    for(int i = 1; i <= n; i++)
        s[i] = (s[i - 1] + a[i]) % MOD;
    for(int i = 1; i <= n; i++)
        b[i] = (b[i - 1] + s[i] + MOD) % MOD;

    for(int i = 1; i <= n; i++)
        cout << b[i] << ' ';
    
    return 0;
}