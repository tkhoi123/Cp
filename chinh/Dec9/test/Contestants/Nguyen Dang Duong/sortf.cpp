#include <bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("sortf.inp","r", stdin);
    freopen("sortf.out","w",stdout);

    int n; cin >> n;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int>> even;
    priority_queue<int> odd;
    for(auto &x : a)
    {
        cin >> x;
    }

    for(auto x : a)
    {
        if(x % 2 == 0)
        {
            even.push(x);
        }
        else odd.push(x);
    }

    while(!even.empty())
    {
        cout << even.top() << ' ';
        even.pop();
    }
    while(!odd.empty())
    {
        cout << odd.top() << ' ';
        odd.pop();
    }


    return 0;
}
