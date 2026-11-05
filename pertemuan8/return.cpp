#include <iostream>
using namespace std;

int kuadrat(int n) {
    return n * n;
}

int main() {
    int hasil = kuadrat(7);
    cout << "7 dikuadratkan = " << hasil << endl;
    cout << "12 dikuadratkan = " << kuadrat(12) << endl;

    return 0;
}