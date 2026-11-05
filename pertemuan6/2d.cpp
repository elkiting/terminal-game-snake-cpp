#include <iostream>
using namespace std;

int main() {
    string barang[3][3] = {
        {"Buku", "Pulpen", "Tas"},
        {"Botol", "Pensil", "Penggaris"},
        {"Laptop", "Mouse", "Keyboard"}
    };
    
    cout << barang[0][2]; // Output: Tas
    
    return 0;
}