#include <iostream>
using namespace std;

int hitungParkir(int jam) {
    if (jam <= 0) {
        return 0;
    }
    if (jam == 1) {
        return 3000;
    }
    return 3000 + (jam - 1) * 2000;
}

int main() {
    int jam;
    cout << "Masukkan lama parkir (jam): ";
    cin >> jam;

    cout << "Total tarif parkir untuk " << jam << " jam adalah: Rp" << hitungParkir(jam) << endl;

    return 0;
}