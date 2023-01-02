#include <bits/stdc++.h>

using namespace std;
#define int long long
string s[300005];
main()
{
	freopen("BAGGER.INP", "r", stdin);
    freopen("BAGGER.OUT", "w", stdout);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n;i++)
        cin >> s[i];
   sort(s + 1, s + n + 1);
    s[n+1] = s[n] + 'a';

    int num  = 1,ans = 0;
    for(int i = 1; i <= n;i++)
    {
        if(s[i] != s[i+1])
        {
            ans += (num + k - 1)/k;
            num = 1;
        }
        else
            num++;
    }
    cout << ans;
}
