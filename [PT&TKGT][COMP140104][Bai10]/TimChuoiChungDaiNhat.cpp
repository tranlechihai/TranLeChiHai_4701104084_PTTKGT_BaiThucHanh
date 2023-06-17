//TimChuoiChungDaiNhat

/*

Cho hai dãy số nguyên:
a = (a1, a2, ..., am), b = (b1, b2, ..., bn)
Tìm dãy con chung có độ dài lớn nhất của dãy a  và b.
Lưu ý: dãy không có số nguyên nào là dãy con của mọi dãy và có độ dài bằng 0.

Input:
7
6
3 5 1 3 5 5 3
1 5 3 5 3 1

Output:
4
5 3 5 3

*/


#include <iostream>
#include <vector>
using namespace std;

pair<int, vector<int>> longestCommonSubsequence(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();

    // Khởi tạo ma trận L
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    // Tính toán ma trận L
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // Truy vết dãy con chung
    vector<int> lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--;
            j--;
        }
        else if (L[i - 1][j] >= L[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end()); // Đảo ngược dãy con chung

    return make_pair(L[m][n], lcs);
}

int main() {
    int m, n;
    cout << "Nhap so phan tu cua day a: ";
    cin >> m;
    cout << "Nhap so phan tu cua day b: ";
    cin >> n;

    vector<int> a(m);
    vector<int> b(n);

    cout << "Nhap day a: ";
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    cout << "Nhap day b: ";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    pair<int, vector<int>> result = longestCommonSubsequence(a, b);
    int length = result.first;
    vector<int> lcs = result.second;

    cout << "Do dai chuoi chung dai nhat: " << length << endl;
    cout << "Chuoi chung dai nhat: ";
    for (int i = 0; i < lcs.size(); i++) {
        cout << lcs[i] << " ";
    }
    cout << endl;

    return 0;
}
