#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 16;
string s;
long long res, cnt[N], k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("COUNTSEQ.INP","r",stdin);
    //freopen("COUNTSEQ.OUT","w",stdout);

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
        while (cnt[idx] - cnt[i - 1] < k && idx < s.size())
            idx++;

        long long leftPos = idx;
        while (cnt[idx + 1] - cnt[i - 1] == k && idx + 1 < s.size())
            idx++;
        
        if(cnt[idx] - cnt[i - 1] == k)
            res += idx - leftPos + 1;
        idx = leftPos;
    }
    
    cout << res;

    return 0;
}