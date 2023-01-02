#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int a[N], n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UDTSEQ.inp","r",stdin);
    freopen("UDTSEQ.out","w",stdout);

    cin >> n >> m;
    while (m--)
    {
        int i, j, k;
        cin >> i >> j >> k;

        a[i] += k;
        a[j + 1] -= k;
    }
    for(int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    
    return 0;
}