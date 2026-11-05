#include <iostream>
using namespace std;

int main() {
    int angka = 2;

    switch (angka) {
        case 1:
            cout << "Angka adalah 1" << endl;
            break;
        case 2:
            cout << "Angka adalah 2" << endl;
            break;
        case 3:
            cout << "Angka adalah 3" << endl;
            break;
        default:
            cout << "Angka tidak dikenal" << endl;
    }

    return 0;
}