#include <iostream>
using namespace std;

int main() {
    int kodeBarang[] = {102, 115, 108, 120, 105, 113};
    int size = sizeof(kodeBarang) / sizeof(kodeBarang[0]);
    int target;

    cout << "Masukkan kode barang yang ingin dicari: ";
    cin >> target;

    bool ditemukan = false;
    for (int i = 0; i < size; i++) {
        if (kodeBarang[i] == target) {
            cout << "Kode barang ditemukan pada index ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}