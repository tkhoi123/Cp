#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("udtseq2.inp","r",stdin);
    freopen("udtseq2.out","w",stdout);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0), b(n + 1, 0), s(n + 1, 0);
    while(m--)
    {
        int i, j, k; cin >> i >> j >> k;
        a[i] = (a[i] + k) % MOD;
        a[j + 1] = (a[j + 1] - k)% MOD;
        a[j + 1] = (a[j + 1] - (j - i + 1)* k) % MOD;
        a[j + 2] = (a[j + 2] + (j - i + 1)* k) % MOD;
    }

    for(int i = 1; i <= n; i++)
        b[i] = (b[i-1] + a[i])% MOD;
    for(int i = 1; i <= n; i++)
        s[i] = (s[i-1] + b[i] + MOD) % MOD;
    for(int i = 1; i <= n; i++)
        cout << s[i] << " ";

    return 0;
}
