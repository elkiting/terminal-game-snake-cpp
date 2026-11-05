#include <iostream>
#include <string>
using namespace std;

double hitungSubtotal(double harga, int jumlah) {
    return harga * jumlah;
}

double hitungDiskon(double subtotal) {
    if (subtotal >= 50000) {
        return subtotal * 0.10;
    }
    return 0;
}

void cetakStruk(string pembeli, double subtotal, double diskon) {
    cout << "\n===== STRUK KANTIN =====" << endl;
    cout << "Pembeli  : " << pembeli << endl;
    cout << "Subtotal : Rp" << subtotal << endl;
    cout << "Diskon   : Rp" << diskon << endl;
    cout << "Bayar    : Rp" << subtotal - diskon << endl;
    cout << "========================" << endl;
}

int main() {
    string pembeli;
    double harga;
    int jumlah;

    cout << "Nama pembeli    : ";
    getline(cin, pembeli);
    cout << "Harga per porsi : ";
    cin >> harga;
    cout << "Jumlah porsi    : ";
    cin >> jumlah;

    double subtotal = hitungSubtotal(harga, jumlah);
    double diskon = hitungDiskon(subtotal);
    cetakStruk(pembeli, subtotal, diskon);

    return 0;
}