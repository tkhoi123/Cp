#include <bits/stdc++.h>
#define int long long
#define TASK "szero"

using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);

    int n; cin >> n;
    vector<int> a(n + 1);
    map<int,int> s;
    int sum = 0;
    int len = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++)
    {
        sum += a[i];
        if(sum == 0)
        {
            len = i;
        }
        if(s.find(sum) != s.end())
        {
            len = max(len, i - s[sum]);
        }
        else s[sum] = i;
    }

    cout << len;

    return 0;
}
