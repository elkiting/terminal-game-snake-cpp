#include <iostream>
using namespace std;

int main() {
    float nilai;

    cout << "Masukkan nilai akhir mahasiswa: ";
    cin >> nilai;

    if (nilai < 0 || nilai > 100) {
        cout << "Nilai tidak valid" << endl;
    } 
    else if (nilai >= 80) {
        cout << "Kategori nilai: A" << endl;
    } 
    else if (nilai >= 70) {
        cout << "Kategori nilai: B" << endl;
    } 
    else if (nilai >= 60) {
        cout << "Kategori nilai: C" << endl;
    } 
    else if (nilai >= 50) {
        cout << "Kategori nilai: D" << endl;
    } 
    else {
        cout << "Kategori nilai: E" << endl;
    }

    return 0;
}