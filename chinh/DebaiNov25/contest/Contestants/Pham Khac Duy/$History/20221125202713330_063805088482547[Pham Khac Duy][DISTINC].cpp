#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 16, INF = 1e9 + 16;
int cnt[N], n, k, res = INF;
set<int> TypeOfSushi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DISTINC.INP","r",stdin);
    freopen("DISTINC.OUT","w",stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;

        TypeOfSushi.insert(x);
        cnt[i] = TypeOfSushi.size();
    }


    if(cnt[n] < k)
    {
        cout << -1;
        
        return 0;
    }
    
    int idx = 1;
    for(int i = 1; i <= n; i++)
    {
        while (idx <= n && cnt[idx] - cnt[i - 1] < k)
            idx++;

        if(cnt[idx] - cnt[i - 1] == k)
            res = min(res, idx - i + 1);
    }

    cout << res;

    return 0;
}