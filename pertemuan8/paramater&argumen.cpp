#include <iostream>
#include <string>
using namespace std;

void sapa(string nama, int semester) {
    cout << nama << " sedang di semester " << semester << endl;
}

int main() {
    sapa("Dzen", 1);
    sapa("Rani", 3);

    return 0;
}