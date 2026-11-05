#include <iostream>
using namespace std;

int main() {
    int arr[] = {35, 75, 90, 15, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Array setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//Struktur Program Bubble Sort

//for (int i = 0; i < n - 1; i++) {
//    for (int j = 0; j < n - i - 1; j++) {
//        if (harga[j] > harga[j + 1]) {
//            int simpan = harga[j];
//            harga[j] = harga[j + 1];
//            harga[j + 1] = simpan;
//        }
//    }
//}