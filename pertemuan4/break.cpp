#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            break; // hentikan loop jika sama dengan 5
        }
        cout << i << " ";
    }
    cout << "\nLooping Selesai";
    // output:
    // 1 2 3 4 
    // Looping Selesai
    
    return 0;
}