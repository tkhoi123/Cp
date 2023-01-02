#include <bits/stdc++.h>
using namespace std;

int n;
map<string, long long> mp;
long long res, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BAGGER.INP","r",stdin);
    freopen("BAGGER.OUT","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;

        mp[s]++;
    }

    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        res += (*it).second / k;
        if((*it).second % k != 0)
            res++;
    }

    cout << res;

    return 0;
}