#define taskname "DARR"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1e5;

int n, k;
long long a[maxN];

void ReadInput()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = n - 1; i >= 0; --i)
        a[i] += a[i + 1];
}

void Solve()
{
    sort(a + 1, a + n);
    long long res = a[0];
    for (int i = n - 1; i > n - k; --i)
        res += a[i];
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    Solve();
}
