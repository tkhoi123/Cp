#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 16;
int m, n, q, a[N][N], s[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("UDTBOARD.inp","r",stdin);
    freopen("UDTBOARD.out","w",stdout);

    cin >> m >> n >> q;
    while (q--)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        s[x1][y1]++;
        s[x2 + 1][y1]--;
        s[x1][y2 + 1]--;
        s[x2 + 1][y2 + 1]++; 
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + s[i][j];
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}