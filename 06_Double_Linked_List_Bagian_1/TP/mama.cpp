#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Pegawai {
    string nama;
    double gaji;
};

void tambahPegawai(vector<Pegawai>& pegawaiList) {
    Pegawai pegawaiBaru;
    cout << "Masukkan nama pegawai: ";
    cin >> pegawaiBaru.nama;
    cout << "Masukkan gaji pegawai: ";
    cin >> pegawaiBaru.gaji;
    pegawaiList.push_back(pegawaiBaru);
    cout << "Pegawai berhasil ditambahkan!\n";
}

void tampilkanPegawai(const vector<Pegawai>& pegawaiList) {
    cout << "\nDaftar Pegawai dan Gaji:\n";
    for (const auto& pegawai : pegawaiList) {
        cout << "Nama: " << pegawai.nama << ", Gaji: " << pegawai.gaji << endl;
    }
}

int main() {
    vector<Pegawai> pegawaiList;
    int pilihan;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Pegawai\n";
        cout << "2. Tampilkan Daftar Pegawai\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi (1-3): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahPegawai(pegawaiList);
                break;
            case 2:
                tampilkanPegawai(pegawaiList);
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}