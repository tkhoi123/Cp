#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxLen = 2*1e6+2;
ll k,cnt[maxLen],len,res=0;
string s;

void init()
{
    freopen("COUNTSEQ.INP","r",stdin); freopen("COUNTSEQ.OUT","w",stdout);
    memset(cnt,0,sizeof(maxLen));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    len = s.length();
    cnt[0] = 0;
    if(s[0] == '1') cnt[1]++;
    for(int i=1;i<len;i++)
    {
        cnt[i+1] = cnt[i] + 1LL*int(s[i]-48);
    }
    len++;
    for(int i=0;i<len;i++)
    {
        res += 1LL * ( (upper_bound(cnt+i+1,cnt+len,cnt[i]+k)-cnt) - (lower_bound(cnt+i+1,cnt+len,cnt[i]+k)-cnt) );
    }
    cout << res;
}

int main()
{
    init();
    cin >> k >> s;
    solve();
}
