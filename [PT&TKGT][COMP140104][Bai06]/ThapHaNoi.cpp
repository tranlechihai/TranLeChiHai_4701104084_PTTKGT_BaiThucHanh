//ThapHaNoi

/* 

Bài toán gồm 3 cọc (được đánh số từ 1 đến 3) và n đĩa có kích thước khác nhau. 
Ban đầu, tất cả các đĩa được xếp chồng trên cọc 1 theo thứ tự từ đĩa nhỏ nhất đến đĩa lớn nhất. 
Mục tiêu là di chuyển tất cả các đĩa từ cọc 1 sang cọc 3, sao cho đĩa nhỏ nhất luôn nằm trên đĩa lớn hơn. 
Trong quá trình di chuyển, chỉ được di chuyển một đĩa mỗi lần và không được đặt đĩa lớn hơn lên đĩa nhỏ hơn.

Input:
3

Output:


*/

#include <iostream>
using namespace std;

int totalSteps = 0;

void moveDisk(int disk, int nguon, int trungGian, int dich) {
    totalSteps++;
    cout << "Di chuyen dia " << disk << " tu coc " << nguon << " sang coc " << dich << endl;
}

void hanoiTower(int n, int nguon, int trungGian, int dich) {
    if (n == 1) {
        moveDisk(n, nguon, dich, trungGian);
        return;
    }
    hanoiTower(n - 1, nguon, dich, trungGian);
    moveDisk(n, nguon, dich, trungGian);
    hanoiTower(n - 1, trungGian, nguon, dich);
}

int main() {
    int n;
    cout << "Nhap so luong dia: ";
    cin >> n;
    cout << "Cac buoc giai quyet bai toan Thap Ha Noi:" << endl;
    hanoiTower(n, 1, 2, 3);
    cout << "Tong so buoc can thuc hien la: " << totalSteps << endl;
    return 0;
}
