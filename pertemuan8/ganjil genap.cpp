#include <iostream>
using namespace std;

bool isGenap(int n) {
    return n % 2 == 0;
}

int main() {
    int angka;
    cout << "Masukkan sebuah angka: ";
    cin >> angka;

    if (isGenap(angka)) {
        cout << "Genap" << endl;
    } else {
        cout << "Ganjil" << endl;
    }

    return 0;
}