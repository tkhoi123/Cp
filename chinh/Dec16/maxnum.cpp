///cần xác định một trật tự giữa các số sao cho số mà ghép của các số là lớn nhất
///xét hai số x và y:
///    xy > yx x cần đứng trước y và ngược lại
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int n;
string a[1000000];
bool cmp(string x, string y)
{
  return x + y > y + x;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++) cout << a[i];
}
