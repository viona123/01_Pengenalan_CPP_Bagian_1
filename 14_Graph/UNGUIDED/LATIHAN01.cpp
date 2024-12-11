#include <iostream>
#include <iomanip> // untuk format output
typedef unsigned int uint;
using namespace std;

void inputSimpul_2311104008(uint jumlahSimpul, string simpul[]) {
    cout << "Silahkan masukkan nama simpul" << endl;
    for (uint i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }
}

void inputBobot_2311104008(uint jumlahSimpul, string simpul[], int bobot[][100]) {
    cout << "Silahkan masukkan bobot antar simpul" << endl;
    for (uint i = 0; i < jumlahSimpul; ++i) {
        for (uint j = 0; j < jumlahSimpul; ++j) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }
}

void tampilkanMatriks_2311104008(uint jumlahSimpul, string simpul[], int bobot[][100]) {
    cout << "\n\t";
    for (uint i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;

    for (uint i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
        for (uint j = 0; j < jumlahSimpul; ++j) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }
}

int main() {
    uint jumlahSimpul;
    
    // Input jumlah simpul
    cout << "Silahkan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    string simpul[jumlahSimpul];
    int bobot[100][100]; // Asumsi maksimum simpul adalah 100

    inputSimpul_2311104008(jumlahSimpul, simpul);
    inputBobot_2311104008(jumlahSimpul, simpul, bobot);
    tampilkanMatriks_2311104008(jumlahSimpul, simpul, bobot);

    return 0;
}