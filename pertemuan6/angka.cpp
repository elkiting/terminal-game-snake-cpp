#include <iostream>
using namespace std;

int main(){
    int angka[3];

    angka[0] = 2;
    angka[1] = 4;
    angka[2] = 6;

    for (int i = 0; i < 3; i++){
        cout << "Nilai ke " << i + 1 <<": " << angka[i] << endl;
    }
    return 0;
}