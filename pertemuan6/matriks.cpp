#include <iostream>
using namespace std;

int main() {
    // Mendeklarasikan array dua dimensi dengan batas maksimal 100x100
    int stokBuku[100][100];
    int jumlahCabang, jumlahKategori;
    
    cout << "Input jumlah cabang toko (baris matriks): ";
    cin >> jumlahCabang;
    cout << "Input jumlah kategori buku (kolom matriks): ";
    cin >> jumlahKategori;
    cout << endl;
    
    // Proses input array ke dalam bentuk matriks
    for (int x = 0; x < jumlahCabang; x++) {
        for (int y = 0; y < jumlahKategori; y++) {
            cout << "Input stok Cabang " << x + 1 << ", Kategori " << y + 1 << ": ";
            cin >> stokBuku[x][y];
        }
        cout << endl;
    }
    
    // Menampilkan array (Output Matriks)
    cout << "Rekap Stok Buku (Matriks):" << endl;
    for (int x = 0; x < jumlahCabang; x++) {
        for (int y = 0; y < jumlahKategori; y++) {
            cout << stokBuku[x][y] << "\t"; // Menggunakan \t agar rapi secara horizontal
        }
        cout << endl; // Turun ke baris baru setelah kolom habis
    }
    
    return 0;
}