#include <iostream>
using namespace std;

int main() {

    int nilai[] = {78, 65, 90, 55, 82, 70};
    int n = sizeof(nilai) / sizeof(nilai[0]);

    cout << "Array sebelum diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (nilai[j] > nilai[j + 1]) {
                int temp = nilai[j];
                nilai[j] = nilai[j + 1];
                nilai[j + 1] = temp;
            }
        }
    }

    cout << "Array setelah diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << nilai[i] << " ";
    }
    cout << endl;

    return 0;
}