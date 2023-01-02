#include<iostream>
#include<algorithm>
using namespace std;
int n, a[1000000];
bool cmp(int x, int y)
{
   ///nếu x chẵn, y lẻ: x đứng trước y là đúng
   ///nếu x lẻ, y chẵn: y đứng trước y là sai
   ///nếu x y cùng chẵn: x < y
   ///x và y cùng lẻ: x > y
   if(x % 2 == 0 and y % 2 != 0) return true;
   if(x % 2 != 0 and y % 2 == 0) return false;
   if(x % 2 == 0 and y % 2 == 0) return x< y;
   if(x % 2 != 0 and y % 2 != 0) return x > y;
}
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, cmp);
    for(int i = 0; i < n; i++) cout << a[i] << " ";
}
