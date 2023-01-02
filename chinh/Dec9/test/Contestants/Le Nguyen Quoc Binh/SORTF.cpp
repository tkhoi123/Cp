#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int LIMIT = 1e5+5;
ll n,a;
vector<ll> even,odd;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SORTF.INP","r",stdin);
    freopen("SORTF.OUT","w",stdout);
}

int main()
{
    init();
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a % 2 == 0) even.push_back(a);
        else odd.push_back(a);
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end(),greater<ll>());
    for(int i=0;i<even.size();i++) cout << even[i] << " ";
    for(int i=0;i<odd.size();i++) cout << odd[i] << " ";
}

