//Balo1

/* 

Cho n món hàng có khối lượng lần lượt là a[0], a[1], ..., a[n - 1](đơn vị là kg) và 1 balô có khả năng chứa là w(kg).

yêu cầu chọn những món hàng nào bỏ vào balô sao cho tổng khối lượng là lớn nhất và không vượt quá w

dữ liệu vào : gồm 2 dòng
- dòng 1 : chứa 2 số n và w
- dòng 2 : chứa n số nguyên a[0], a[1], ..., a[n - 1]

dữ liêu ra : gồm 2 dòng
- dòng 1 : khối lượng tối ưu của balo sau khi chọn các món hàng
- dòng 2 : thứ tự các món hàng được chọn(số nhỏ ghi trước số lớn ghi sau)

ví dụ
input :
3 10
3 5 7

output :
10
0 2

*/



#include <iostream>
#include <algorithm>
using namespace std;
int f[10000][10000];
int main()
{
    int n, w;
    cin >> n >> w;
    int a[100] = { 0 };
    //int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int j = 1; j <= w; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] <= j)
            {
                f[i][j] = max(f[i - 1][j], a[i] + f[i - 1][j - a[i]]);
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << f[n][w] << endl;
    //truy vết
    int x = 0;
    int b[100];
    for (int i = n; i > 0; i--)
    {
        if (f[i][w] != f[i - 1][w])
        {
            b[x++] = i - 1;
            w = w - a[i];
        }
    }


    for (int i = x - 1; i >= 0; i--)
    {
        cout << b[i] << " ";
    }
    return 0;
}