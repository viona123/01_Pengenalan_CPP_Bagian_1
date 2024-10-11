#include <iostream>
using namespace std;

int main() {
    int var = 50;   // Deklarasi variabel biasa
    int *ptr;       // Deklarasi pointer (penyimpan alamat untuk variabel int)

    ptr = &var;     // Inisialisasi pointer dengan alamat variabel 'var'

    // Menampilkan nilai variabel variabel
    cout << "Nilai variabel: " << var << endl;

    // Menampilkan alamat memori variabel var (melalui pointer)
    cout << "Alamat memori variabel : " << ptr << endl;

    // Menampilkan nilai yang tersimpan di alamat memori yang ditunjuk oleh pointer
    cout << "Nilai yang ditunjuk oleh pointer : " << *ptr << endl;

    return 0;
}
