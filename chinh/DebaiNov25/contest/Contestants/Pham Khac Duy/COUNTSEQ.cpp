#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6 + 16;
string s;
long long res, cnt[N], k;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("COUNTSEQ.INP","r",stdin);
    freopen("COUNTSEQ.OUT","w",stdout);

    cin >> k >> s;
    s = ' ' + s;
    for(int i = 1; i < s.size(); i++)
    {
        cnt[i] = cnt[i - 1];
        cnt[i] += (s[i] == '1');
    }

    long long idx = 1;
    for(int i = 1; i < s.size(); i++)
    {
        if(idx < i)
            idx = i;
        while (cnt[idx] - cnt[i - 1] < k && idx < s.size())
            idx++;

        long long curPos = idx;
        while (cnt[curPos] - cnt[i - 1] == k && curPos < s.size())
        {   
            res++;
            curPos++;
        }
    }
    
    cout << res;

    return 0;
}