#include <iostream>
using namespace std;

int main() {
    string kategoriBuku[3] = {"Fiksi", "Edukasi", "Sejarah"};
    
    // Mencari panjang atau jumlah elemen dalam array secara dinamis
    int panjangArray = sizeof(kategoriBuku) / sizeof(kategoriBuku[0]);
    cout << "Jumlah kategori buku yang tersedia: " << panjangArray << endl;
    
    return 0;
}