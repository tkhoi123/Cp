#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, res;
long long a[N];
pair<long long, int> s[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SZERO.inp","r",stdin);
    freopen("SZERO.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i].first = s[i - 1].first + a[i];
        s[i].second = i;
    }

    sort(s + 1, s + 1 + n, [&] (const pair<long long, int>& me, const pair<long long, int>& her)
    {
        return me.first < her.first || (me.first == her.first && me.second < her.second);
    });

    int l = 1, r = l;
    while (l <= n)
    {
        while (s[l].first == s[r].first)
            r++;
        
        res = max(res, s[r - 1].second - s[l].second);
        l = r;
    }
    
    cout << res;

    return 0;
}