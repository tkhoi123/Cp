#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16, INF = 1e9 + 16;
int res = INF, n, k, cnt, a[N];
deque<int> q;
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DISTINC.INP","r",stdin);
    freopen("DISTINC.OUT","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        q.push_back(a[i]);
        if(mp[a[i]] == 0)
            cnt++;
        mp[a[i]]++;
        while (cnt > k && !q.empty())
        {
            int tmp = q.front();
            mp[tmp]--;
            if(mp[tmp] == 0)
                cnt--;
            q.pop_back();
        }

        while (!q.empty() && cnt == k)
        {
            int tmp = q.front();
            if(mp[tmp] == 1)
                break;
            else
            {   
                q.pop_back();
                mp[tmp]--;
            }
        }
        if(cnt == k)
            res = min(res, (int)q.size());
    }

    cout << (res == INF ? -1 : res);

    return 0;
}