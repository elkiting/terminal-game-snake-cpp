#include <iostream>
#include <string>
using namespace std;

int main() {

    string arr[] = {"Nain", "rahul", "Bunga", "zacky", "maul", "senja"};
    int size = 6;
    string target = "Bunga";

    cout << "Daftar nama di buku telepon:\n";
    for (int i = 0; i < size; i++) {
        cout << "- " << arr[i] << endl;
    }
    cout << endl;

    bool ditemukan = false;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Data \"" << target << "\" ditemukan pada index ke-" << i << endl;
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Data \"" << target << "\" tidak ditemukan." << endl;
    }

    return 0;
}