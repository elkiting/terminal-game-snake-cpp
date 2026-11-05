#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama;
    char kelas;
    int umur;
    float nilai;
    double tinggi;
    bool lulus = true;

    cout << "Masukkan nama: ";
    getline(cin, nama);
    
    cout << "Masukkan kelas, umur, nilai, tinggi (dipisah spasi): ";
    cin >> kelas >> umur >> nilai >> tinggi;

    cout << nama << " " << kelas << " " << umur << " " 
         << nilai << " " << tinggi << " " << lulus << endl;

    return 0;
}