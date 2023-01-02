#define taskname "MINFACT"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
using lli = long long;
const int maxA = 1e6;

int d[maxA + 1];

void Sieve()
{
    iota(d + 1, d + maxA + 1, 1);
    for (int i = 2; i * i <= maxA; ++i)
        if (d[i] == i)
            for (int j = i * i; j <= maxA; j += i)
                if (d[j] == j) d[j] = i;
}

lli FindN(lli p, lli e)
{
    lli Step = 1, cnt = 0;
    while (cnt * p + 1 <= e)
    {
        Step *= p;
        cnt = cnt * p + 1;
    }
    lli n = 0;
    for (; cnt > 0; cnt /= p)
    {
        lli loop = e / cnt;
        n += Step * loop;
        Step /= p;
        e %= cnt;
    }
    return n;
}

lli FindN2(lli p, lli e)
{
    lli low = 1, high = p * e;
    while (low <= high)
    {
        lli mid = (low + high) / 2;
        lli temp = mid;
        lli cnt = 0;
        for (; temp > 0; temp /= p)
            cnt += temp / p;
        if (cnt < e) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

lli Solve(lli a, lli k)
{
    lli n = 0;
    while (a > 1)
    {
        lli p = d[a], e = 0;
        for (; a % p == 0; a /= p) ++e;
        lli temp = FindN(p, e * k);
        if (temp > n) n = temp;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Sieve();
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli a, k;
        cin >> a >> k;
        cout << Solve(a, k) << '\n';
    }
}
