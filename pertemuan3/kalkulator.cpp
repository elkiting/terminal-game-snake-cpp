#include <iostream>
using namespace std;

int main() {
    double angka1, angka2, hasil;
    char op;

    cout << "Masukkan angka Pertama: ";
    cin >> angka1;

    cout << "Pilih operasi (+ [Tambah], - [Kurang], * [Kali], / [Bagi])" << endl;
    cout << "Masukkan pilihan: ";
    cin >> op;

    cout << "Masukkan angka Kedua: ";
    cin >> angka2;

    switch (op) {
        case '+' :
        hasil = angka1 + angka2;
        break;

        case '-' :
        hasil = angka1 - angka2;
        break;

        case '*' :
        hasil = angka1 * angka2;
        break;

        case '/' :
        if (angka2 !=0) {
            hasil = angka1 / angka2;
        }
        else {
            cout << "Error: Pembagian dengan Nol tidak diperbolehkan." << endl;
            return 1;
        }
        break;
    }
    cout << "Hasilnya adalah: " << hasil << endl;

    return 0;
}