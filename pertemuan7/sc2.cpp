#include <iostream>
using namespace std;

int main() {

    int harga[] = {40, 34, 33, 90, 70};
    int n = sizeof(harga) / sizeof(harga[0]);

    cout << "Harga sebelum diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << harga[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (harga[j] > harga[j + 1]) {

                int simpan = harga[j];
                harga[j] = harga[j + 1];
                harga[j + 1] = simpan;
            }
        }
    }

    cout << "Harga setelah diurutkan: ";
    for (int i = 0; i < n; i++) {
        cout << harga[i] << " ";
    }
    cout << endl;
    
    return 0;
}