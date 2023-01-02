#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 16;
int n, a[N];
vector<int> odd, even;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SORTF.inp","r",stdin);
    freopen("SORTF.out","w",stdout);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
    {
        if(a[i] % 2 == 0)
            even.push_back(a[i]);
        else
            odd.push_back(a[i]);
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    for(int i = 0; i < even.size(); i++)
        cout << even[i] << ' ';
    for(int i = odd.size() - 1; i >= 0; i--)
        cout << odd[i] << ' ';
    
    return 0;
}