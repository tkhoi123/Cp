#define taskname "BINTOCT"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
const int maxN = 1e5 + 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    string s;
    getline(cin, s);
    int n = s.length();
    int k = (n - 1) % 3;
    int Digit = 0;
    for (int i = 0; i < n; ++i)
    {
        Digit = Digit * 2 + s[i] - '0';
        if (i % 3 == k)
        {
            cout << Digit;
            Digit = 0;
        }
    }
}
