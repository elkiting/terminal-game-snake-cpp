#include <iostream>
using namespace std;

int main() {
    int umur = 20;

    if (umur < 5) {
        cout << "Balita";
    } else if (umur < 13) {
        cout << "Anak-anak";
    } else if (umur < 18) {
        cout << "Remaja";
    } else {
        cout << "Dewasa";
    }

    return 0;
}