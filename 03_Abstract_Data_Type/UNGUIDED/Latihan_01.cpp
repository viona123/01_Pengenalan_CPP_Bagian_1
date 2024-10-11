// Tugas Nomer 01

/* #include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double uts;
    double uas;
    double tugas;
    double nilaiAkhir;
};

double hitungNilaiAkhir(double uts, double uas, double tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    const int maxMahasiswa = 10;
    Mahasiswa mahasiswa[maxMahasiswa];

    int jumlahMahasiswa;
    cout << "Masukkan jumlah mahasiswa (max. 10): ";
    cin >> jumlahMahasiswa;

    if (jumlahMahasiswa > maxMahasiswa) {
        cout << "Jumlah mahasiswa melebihi batas maksimum!" << endl;
        return 1;
    }

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Nilai UTS: ";
        cin >> mahasiswa[i].uts;
        cout << "Nilai UAS: ";
        cin >> mahasiswa[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mahasiswa[i].tugas;

        mahasiswa[i].nilaiAkhir = hitungNilaiAkhir(mahasiswa[i].uts, mahasiswa[i].uas, mahasiswa[i].tugas);
    }

    cout << "Data Mahasiswa:" << endl;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Nama: " << mahasiswa[i].nama << endl;
        cout << "NIM: " << mahasiswa[i].nim << endl;
        cout << "Nilai UTS: " << mahasiswa[i].uts << endl;
        cout << "Nilai UAS: " << mahasiswa[i].uas << endl;
        cout << "Nilai Tugas: " << mahasiswa[i].tugas << endl;
        cout << "Nilai Akhir: " << mahasiswa[i].nilaiAkhir << endl;
        cout << endl;
    }

    return 0;
}*/


// Tugas Nomor 03
/*#include <iostream>

using namespace std;

// Fungsi untuk menampilkan isi array 2D
void printArray(int array[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

// Fungsi untuk menukarkan isi array 2D pada posisi tertentu
void swapArray(int array1[][3], int array2[][3], int row, int col) {
    int temp = array1[row][col];
    array1[row][col] = array2[row][col];
    array2[row][col] = temp;
}

// Fungsi untuk menukarkan isi pointer
void swapPointer(int* pointer1, int* pointer2) {
    int temp = *pointer1;
    *pointer1 = *pointer2;
    *pointer2 = temp;
}

int main() {
    // Deklarasi array 2D
    int array1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int array2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

    // Deklarasi pointer integer
    int pointer1 = 20;
    int pointer2 = 30;

    int* pPointer1 = &pointer1;
    int* pPointer2 = &pointer2;

    // Menampilkan isi array 2D
    cout << "Isi array1:" << endl;
    printArray(array1, 3);
    cout << "Isi array2:" << endl;
    printArray(array2, 3);

    // Menukarkan isi array 2D pada posisi tertentu
    swapArray(array1, array2, 1, 1);

    // Menampilkan isi array 2D setelah swap
    cout << "Isi array1 setelah swap:" << endl;
    printArray(array1, 3);
    cout << "Isi array2 setelah swap:" << endl;
    printArray(array2, 3);

    // Menukarkan isi pointer
    swapPointer(pPointer1, pPointer2);

    // Menampilkan isi pointer setelah swap
    cout << "Isi pointer1 setelah swap: " << pointer1 << endl;
    cout << "Isi pointer2 setelah swap: " << pointer2 << endl;

    return 0;
}*/