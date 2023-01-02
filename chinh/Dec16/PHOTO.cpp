///x đứng trước y trong dãy chuẩn khi nào?
///Giả sử ban đầu x < y
///mỗi 1 người chỉ rời hàng 1 ảnh
///x và y thay đổi trật tự chuẩn chỉ khi tự x hoặc tự y rời hàng
///Bức ảnh 1: x đi ra và chèn vào sau y: trật tự x <y là sai
///Bức ảnh khác: y đi ra vào chèn vào trước x: trật tự x < y cũng sai
#include<iostream>
#include<algorithm>
using namespace std;
int n, k, a[100001], p[5][100001];
bool cmp(int x, int y)
{
    ///x đứng trước y khi và chỉ khi x < y trong ít nhất 3 bức ảnh
    ///trở lên
    int cnt = 0;
    for(int i = 0; i < 5; i++)
    {
       if(p[i][x] < p[i][y]) cnt++;
       if(cnt >= 3) break;
    }
    return cnt >= 3;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = i;
    ///đây là trật tự cần sx lại theo các bức ảnh
    for(int i = 0; i < 5; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> k; p[i][k] = j;
        }
    }
    sort(a+ 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) cout << a[i] <<" ";
}
