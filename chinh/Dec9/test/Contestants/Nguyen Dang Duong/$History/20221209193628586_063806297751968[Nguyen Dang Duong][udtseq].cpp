#include <bits/stdc++.h>
//#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("udtseq.inp","r",stdin);
    freopen("udtseq.out","w",stdout);

    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    while(m--)
    {
        int i, j, k; cin >> i >> j >> k;
        a[i] += k;
        a[j + 1] -= k;
    }

    for(int i = 1; i <= n; i++)
    {
        a[i] = a[i] + a[i - 1];
        //cout << a[i] << ' ';
    }
    for(int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}
