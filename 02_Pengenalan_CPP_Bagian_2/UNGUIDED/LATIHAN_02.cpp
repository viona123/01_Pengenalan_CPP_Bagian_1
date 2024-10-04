//Soal nomor 1

/* #include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Data Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    return 0;
} */





// Soal nomor 2
#include <iostream>

using namespace std;

int main() {
    int baris, kolom, lapis;

    // Input ukuran array
    cout << "Masukkan jumlah baris: ";
    cin >> baris;
    cout << "Masukkan jumlah kolom: ";
    cin >> kolom;
    cout << "Masukkan jumlah lapis: ";
    cin >> lapis;

    // Inisialisasi array tiga dimensi
    int ***array_3d = new int**[lapis];
    for (int i = 0; i < lapis; i++) {
        array_3d[i] = new int*[baris];
        for (int j = 0; j < baris; j++) {
            array_3d[i][j] = new int[kolom];
        }
    }

    // Input nilai array
    for (int i = 0; i < lapis; i++) {
        for (int j = 0; j < baris; j++) {
            for (int k = 0; k < kolom; k++) {
                cout << "Masukkan nilai untuk lapis " << i+1 << ", baris " << j+1 << ", kolom " << k+1 << ": ";
                cin >> array_3d[i][j][k];
            }
        }
    }

    // Print array tiga dimensi
    for (int i = 0; i < lapis; i++) {
        cout << "Lapis " << i+1 << ":" << endl;
        for (int j = 0; j < baris; j++) {
            for (int k = 0; k < kolom; k++) {
                cout << array_3d[i][j][k] << " ";
            }
            cout << endl;
        }
    }

    // Deallocate memory
    for (int i = 0; i < lapis; i++) {
        for (int j = 0; j < baris; j++) {
            delete[] array_3d[i][j];
        }
        delete[] array_3d[i];
    }
    delete[] array_3d;

    return 0;
} 


// Soal nomor 3
/* #include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan elemen array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max = arr[0], min = arr[0], sum = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
        sum += arr[i];
    }
    sum += arr[0];

    cout << "Nilai Maksimum: " << max << endl;
    cout << "Nilai Minimum: " << min << endl;
    cout << "Nilai Rata-Rata: " << (double)sum / n << endl;

    return 0;
}*/

