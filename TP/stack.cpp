#include "stack.h"
#include <iostream>
using namespace std;

// Membuat stack kosong
void createStack_2311104008(stack &S) {
    S.Top = 0;
}

// Mengecek apakah stack kosong
bool isEmpty_2311104008(stack S) {
    return S.Top == 0;
}

// Mengecek apakah stack penuh
bool isFull_2311104008(stack S) {
    return S.Top == 15;
}

// Menambahkan elemen ke dalam stack
void push_2311104008(stack &S, infotype x) {
    if (!isFull_2311104008(S)) {
        S.info[S.Top] = x;
        S.Top++;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

// Mengeluarkan elemen dari stack
infotype pop_2311104008(stack &S) {
    if (!isEmpty_2311104008(S)) {
        S.Top--;
        return S.info[S.Top];
    } else {
        cout << "Stack kosong!" << endl;
        return '\0'; // Nilai kosong jika stack kosong
    }
}

// Menampilkan semua elemen dalam stack
void printInfo_2311104008(stack S) {
    if (isEmpty_2311104008(S)) {
        cout << "Stack kosong!" << endl;
    } else {
        for (int i = 0; i < S.Top; i++) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menguji stack dengan input yang diberikan
void testStack_2311104008(const char *input) {
    stack S;
    createStack_2311104008(S);

    // Push setiap karakter dalam input ke stack
    for (int i = 0; input[i] != '\0'; i++) {
        push_2311104008(S, input[i]);
    }

    // Menampilkan isi stack awal
    cout << "Isi stack awal -> ";
    printInfo_2311104008(S);

    // Melakukan pop hingga setengah elemen
    stack tempStack;
    createStack_2311104008(tempStack);
    int len = S.Top;
    for (int i = 0; i < len / 2; i++) {
        push_2311104008(tempStack, pop_2311104008(S));
    }

    // Menampilkan isi stack sesudah pop
    cout << "Isi stack sesudah pop -> ";
    printInfo_2311104008(S);
}

int main() {
    // Contoh berdasarkan digit terakhir NIM MOD 4
    int digitTerakhirNIM = 8; // Gantilah sesuai dengan digit terakhir NIM Anda
    int hasilMod = digitTerakhirNIM % 4;

    if (hasilMod == 0) {
        cout << "Digit terakhir NIM MOD 4 sisa 0:\n";
        testStack_2311104008("IFLABJAYA");
    } else if (hasilMod == 1) {
        cout << "Digit terakhir NIM MOD 4 sisa 1:\n";
        testStack_2311104008("HALOBANDUNG");
    } else if (hasilMod == 2) {
        cout << "Digit terakhir NIM MOD 4 sisa 2:\n";
        testStack_2311104008("PERCAYADIRI");
    } else if (hasilMod == 3) {
        cout << "Digit terakhir NIM MOD 4 sisa 3:\n";
        testStack_2311104008("STRUKTURDATA");
    }

    return 0;
}
