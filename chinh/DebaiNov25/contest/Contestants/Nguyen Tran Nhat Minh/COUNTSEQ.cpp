/*#include <bits/stdc++.h>

using namespace std;
#define int long long
char s[300005];
main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n;i++)
        cin >> s[i];
    s[n+1] = 'a';
    int num  = 1,ans = 0;
    for(int i = 1; i <= n;i++)
    {
        if(s[i] != s[i+1])
        {
            ans += (num/k);
            if(num%k != 0)
                ans++;
            num = 1;
        }
        else
            num++;
    }
    cout << ans;
}*/
#include <bits/stdc++.h>

using namespace std;
#define int long long
int a[2000005],f[2000005];
main()
{
    freopen("COUNTSEQ.INP", "r", stdin);
    freopen("COUNTSEQ.OUT", "w", stdout);
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size(),ans = 0;
    for(int i = 1; i <= n;i++)
    {
        a[i] = s[i-1] - '0';
        f[i] = f[i-1] + a[i];
    }
    for(int i = 1; i <= n;i++)
    {
        int lo = i,hi = n,res1 = 0,res2 = 0;
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(f[mid]-f[i-1] < k)
            {
                res1 = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        lo = i,hi = n;// 1 1 2 2 3 3 4 4 5 5
        while(lo <= hi)
        {
            int mid = (lo+hi)/2;
            if(f[mid]-f[i-1] <= k)
            {
                res2 = mid;
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        if(res2 == 0)
            continue;
        ans += res2-res1;
    }
    cout << ans;
}
