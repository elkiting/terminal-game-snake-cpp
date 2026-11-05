#include <iostream>
#include <string>
using namespace std;

int main() {
    string arr[] = {"Nain", "rahul", "Bunga", "zacky", "maul", "senja"};
    int size = 6;
    string target = "Bunga";

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            cout << "Data ditemukan pada index ke-" << i << endl;
            break;
        }
    }
    return 0;
}

//Struktur Program Sequential Search

//for (int i = 0; i < size; i++) {
//    if (arr[i] == target) {
//        cout << i;
//        break;
//    }
//}