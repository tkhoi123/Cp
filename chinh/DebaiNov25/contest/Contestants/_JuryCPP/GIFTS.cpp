#define taskname "GIFTS"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxN = 1e5 + 1;

int n;
int b[maxN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        b[a] = i;
    }
    for (int i = 1; i <= n; ++i)
        cout << b[i] << ' ';
}
