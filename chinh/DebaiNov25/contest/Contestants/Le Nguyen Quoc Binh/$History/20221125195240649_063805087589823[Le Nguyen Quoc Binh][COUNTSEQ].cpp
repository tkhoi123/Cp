#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

const int maxLen = 2*1e6+2;
int k;
string s;
bool check[maxLen];

void init()
{
    freopen("COUNTSEQ.INP","r",stdin); freopen("COUNTSEQ.OUT","w",stdout);
    memset(check,false,sizeof(check));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    int i=0,j=0,cnt=0,len = s.length(),res=0,pos=0;
    while(i <= j)
    {
        if(s[j] == '1')
        {
            if(check[j] == false)
            {
                cnt++;
                check[j] = true;
            }
            if(cnt == k) pos = j;
        }
        if(cnt == k) res++;
        //cout << i << " " << j << " " << cnt << endl;
        if(j < len-1 && cnt <= k)
        {
            j++;
        }
        else
        {
            if(s[i] == '1') cnt--;
            i++;
            j = pos;
        }
        //if(cnt == k) res++;
        //cout << i << " " << j << " " << cnt << endl;
    }
    cout << res;
}

int main()
{
    init();
    cin >> k >> s;
    solve();
}
