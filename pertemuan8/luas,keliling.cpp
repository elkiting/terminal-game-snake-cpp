#include <iostream>
using namespace std;

double luasLingkaran(double r) {
    return 3.14 * r * r;
}

double kelilingLingkaran(double r) {
    return 2 * 3.14 * r;
}

int main() {
    double r;
    cout << "Masukkan jari-jari lingkaran: ";
    cin >> r;

    cout << "Luas lingkaran     : " << luasLingkaran(r) << endl;
    cout << "Keliling lingkaran : " << kelilingLingkaran(r) << endl;

    return 0;
}