#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// --- MODUL 8: FUNCTION ---
// 1. Fungsi dengan return value untuk kuadrat
int kuadrat(int n) {
    return n * n;
}

// 2. Fungsi void untuk mencetak banner
void tampilkanBanner() {
    cout << "========================================\n";
    cout << "   PROGRAM RANGKUMAN MATERI MODUL 2 - 8\n";
    cout << "========================================\n";
}

// 3. Fungsi Sequential Search (Modul 7)
int sequentialSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Mengembalikan indeks jika ditemukan
        }
    }
    return -1; // Jika tidak ditemukan
}

// 4. Fungsi Bubble Sort (Modul 7) secara Ascending
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    tampilkanBanner();

    // --- MODUL 2 & 3: TIPE DATA, VARIABEL, & OPERATOR ---
    cout << "\n[DEMO MODUL 2 & 3: Tipe Data, Variabel, & Operator]\n";
    string namaMahasiswa = "Praktikan DPA";
    int angka1 = 10, angka2 = 3;
    double desimal = 5.5;
    bool statusAktif = true;

    cout << "Nama (String)     : " << namaMahasiswa << endl;
    cout << "Angka 1 (Int)     : " << angka1 << endl;
    cout << "Angka 2 (Int)     : " << angka2 << endl;
    cout << "Hasil Aritmatika  : " << angka1 << " + " << angka2 << " = " << (angka1 + angka2) << endl;
    cout << "Sisa Bagi (Mod)   : " << angka1 << " % " << angka2 << " = " << (angka1 % angka2) << endl;
    cout << "Status (Bool)     : " << (statusAktif ? "Aktif" : "Tidak Aktif") << endl;


    // --- MODUL 3: PERCABANGAN (BRANCHING) ---
    cout << "\n[DEMO MODUL 3: Percabangan (If-Else & Switch-Case)]\n";
    int nilaiUjian = 85;
    cout << "Nilai Ujian Anda  : " << nilaiUjian << endl;
    
    // If-Else-If
    if (nilaiUjian >= 80) {
        cout << "Kategori Grade    : A (Lulus dengan Sangat Baik)\n";
    } else if (nilaiUjian >= 70) {
        cout << "Kategori Grade    : B (Lulus)\n";
    } else {
        cout << "Kategori Grade    : C (Remedial)\n";
    }


    // --- MODUL 4: PERULANGAN (LOOPING) ---
    cout << "\n[DEMO MODUL 4: Perulangan (For Loop)]\n";
    cout << "Mencetak angka 1 sampai 5 menggunakan For Loop: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;


    // --- MODUL 6: ARRAY & sizeof() ---
    cout << "\n[DEMO MODUL 6: Array 1 Dimensi & sizeof]\n";
    int nilaiArray[] = {78, 65, 90, 55, 82, 70};
    // Menghitung panjang array secara otomatis menggunakan sizeof()
    int ukuranArray = sizeof(nilaiArray) / sizeof(nilaiArray[0]);

    cout << "Array sebelum diurutkan: ";
    for (int i = 0; i < ukuranArray; i++) {
        cout << nilaiArray[i] << " ";
    }
    cout << endl;


    // --- MODUL 7: BUBBLE SORT & SEQUENTIAL SEARCH ---
    cout << "\n[DEMO MODUL 7: Sorting & Searching]\n";
    
    // Menjalankan Bubble Sort (Mengurutkan array dari terkecil ke terbesar)
    bubbleSort(nilaiArray, ukuranArray);
    
    cout << "Array setelah Bubble Sort (Ascending): ";
    for (int i = 0; i < ukuranArray; i++) {
        cout << nilaiArray[i] << " ";
    }
    cout << endl;

    // Menjalankan Sequential Search mencari angka 82
    int targetCari = 82;
    int hasilCari = sequentialSearch(nilaiArray, ukuranArray, targetCari);
    if (hasilCari != -1) {
        cout << "Pencarian: Nilai " << targetCari << " ditemukan pada indeks ke-" << hasilCari << endl;
    } else {
        cout << "Pencarian: Nilai " << targetCari << " tidak ditemukan." << endl;
    }


    // --- MODUL 8: FUNCTION ---
    cout << "\n[DEMO MODUL 8: Function dengan Return Value]\n";
    int angkaKuart = 7;
    cout << "Memanggil fungsi kuadrat(" << angkaKuart << ") = " << kuadrat(angkaKuart) << endl;

    cout << "\n========================================\n";
    cout << "       PROGRAM SELESAI DENGAN BAIK      \n";
    cout << "========================================\n";

    return 0;
}