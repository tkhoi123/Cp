#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 1e5 + 1;
int n;
int a[maxn], b[maxn], cs[maxn];
bool cmp(int i, int j)
{
  long long Ti = b[i] - a[i];
  long long Tj = b[j] - a[j];
  if(Ti * Tj < 0) return Ti > Tj;
  if(Ti * Tj > 0)
    if(Ti > 0) return a[i] < a[j];
    else return b[i] > b[j];
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        cs[i] = i;
    }
    sort(cs+1, cs + n + 1, cmp);

    long long Chi = 0, Von = 0;
    for (int i = 1; i <= n; ++i)
    {
        int j = cs[i];
        Chi -= a[j];
        if (Chi < 0)
        {
            Von -= Chi;
            Chi = 0;
        }
        Chi += b[j];
    }
    cout << Von << endl;
    for(int i = 1; i<= n; i++)
        cout << cs[i] << " ";
}
