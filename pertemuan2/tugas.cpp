#include <iostream>
using namespace std;

int main(){
    string nama, npm, kelas, jurusan, angkatan;

    cout << "Masukkan nama    : ";
    getline(cin, nama);

    cout << "Masukkan NPM     : ";
    getline(cin, npm);

    cout << "Masukkan kelas   : ";
    getline(cin, kelas);

    cout << "Masukkan jurusan : ";
    getline(cin, jurusan);

    cout << "Masukkan angkatan: ";
    getline(cin, angkatan);

    cout << endl;

    cout << "=== DATA PRAKTIKAN ===" << endl;
    cout << "Nama     : " << nama << endl;
    cout << "NPM      : " << npm << endl;
    cout << "Kelas    : " << kelas << endl;
    cout << "Jurusan  : " << jurusan << endl;
    cout << "Angkatan : " << angkatan << endl;

    return 0;
}