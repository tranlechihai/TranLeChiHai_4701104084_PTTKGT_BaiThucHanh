//QuickSort

/*
* 
Thuật toán Quick Sort là một thuật toán sắp xếp đệ quy dựa trên phân hoạch (partitioning). 
Thuật toán này chia một mảng thành hai phần, đảm bảo rằng một phần tử được chọn làm "pivot" nằm ở 
đúng vị trí cuối cùng của nó trong mảng đã được sắp xếp. Các phần tử nhỏ hơn pivot được đặt bên trái pivot, 
trong khi các phần tử lớn hơn pivot được đặt bên phải pivot. Sau đó, thuật toán được áp dụng đệ quy cho hai phần mảng đã được chia.

Input:
7 2 8 1 6 3

Output:
1 2 3 6 7 8

*/

#include <iostream>
using namespace std;

// Hàm hoán đổi hai phần tử
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm phân hoạch
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Chọn pivot là phần tử cuối cùng của mảng
    int i = low - 1; // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j <= high - 1; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Hoán đổi phần tử arr[i] và arr[j]
        }
    }

    swap(arr[i + 1], arr[high]); // Hoán đổi pivot vào đúng vị trí

    return i + 1; // Trả về vị trí của pivot
}

// Hàm Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Chia mảng và lấy vị trí pivot

        quickSort(arr, low, pi - 1); // Áp dụng đệ quy cho nửa mảng trước pivot
        quickSort(arr, pi + 1, high); // Áp dụng đệ quy cho nửa mảng sau pivot
    }
}

// Hàm in ra mảng
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n = 0;

    int arr[100];
    cout << "Nhap cac phan tu cua mang: ";

    while (cin >> arr[n])
    {
        n++;
    }

    cout << "Mang ban dau: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Mang sau khi sap xep: ";
    printArray(arr, n);

    return 0;
}



