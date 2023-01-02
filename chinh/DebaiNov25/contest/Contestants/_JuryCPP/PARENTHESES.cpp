#define taskname "PARENTHESES"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    getline(cin, s);
    int n = s.length(), cnt = 0, mincnt = 0, res = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == '(') ++cnt;
        else
        {
            --cnt;
            if (cnt < mincnt)
            {
                mincnt = cnt;
                res = i + 1;
            }
        }
    if (cnt != 0) res = -1;
    cout << res;
}
