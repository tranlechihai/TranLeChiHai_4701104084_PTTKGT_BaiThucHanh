//8ConHau

/*

Bài toán tám quân hậu là bài toán đặt tám quân hậu trên bàn cờ vua kích thước 8×8 sao cho không có 
quân hậu nào có thể "ăn" được quân hậu khác, hay nói khác đi không quân hậu nào có để di chuyển theo quy tắc cờ vua.
lời giải của bài toán là một cách xếp tám quân hậu trên bàn cờ sao cho không có hai quân nào đứng trên cùng hàng, 
hoặc cùng cột hoặc cùng đường chéo. Bài toán tám quân hậu có thể tổng quát hóa thành bài toán đặt n quân hậu trên bàn cờ n×n(n ≥ 4).

Input:
n = 8 

Output:
Cách sắp xếp quân hậu thỏa yêu cầu.
Xuất 0 và 1.

*/


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 8; 

// Hàm kiểm tra xem có thể đặt quân hậu tại vị trí (row, col) không
bool isSafe(int board[N][N], int row, int col) {
    // Kiểm tra cột trong hàng hiện tại
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return false;
    }

    // Kiểm tra đường chéo chính phía trên
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Kiểm tra đường chéo phụ phía trên
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Đệ quy quay lui
bool solveNQueens(int board[N][N], int col) {
    // Nếu đã đặt được 8 quân hậu, trả về true
    if (col >= N) {
        return true;
    }

    // Tạo một mảng chứa các vị trí hàng
    int rowPositions[N];
    for (int i = 0; i < N; i++) {
        rowPositions[i] = i;
    }

    // Xáo trộn các vị trí hàng
    srand(time(NULL));
    for (int i = N - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(rowPositions[i], rowPositions[j]);
    }

    // Thử từng vị trí hàng trong mảng đã xáo trộn
    for (int i = 0; i < N; i++) {
        int row = rowPositions[i];

        // Kiểm tra xem có thể đặt quân hậu tại vị trí (row, col) không
        if (isSafe(board, row, col)) {
            // Đặt quân hậu tại vị trí (row, col)
            board[row][col] = 1;

            // Gọi đệ quy để đặt các quân hậu tiếp theo
            if (solveNQueens(board, col + 1)) {
                return true; // Trả về true nếu tìm thấy một cách sắp xếp
            }

            // Nếu không tìm được cách sắp xếp, quay lui và thử vị trí hàng khác
            board[row][col] = 0;
        }
    }

    return false;
}


void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int board[N][N] = { 0 };

    if (solveNQueens(board, 0)) {
        cout << "Mot trong nhung cach sap xep cac quan hau:" << endl;
        printBoard(board);
    }
    else {
        cout << "Khong tim thay cach sap xep cac quan hau." << endl;
    }

    return 0;
}


