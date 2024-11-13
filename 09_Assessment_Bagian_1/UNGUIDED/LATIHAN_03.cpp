#include <iostream>
using namespace std;

// Program Binary Tree

// Deklarasi pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

// Inisialisasi
void init_2311104008() {
    root = NULL;
}

// Cek Node
bool isEmpty_2311104008() {
    return root == NULL;
}

// Buat node baru
void buatNode_2311104008(char data) {
    if (isEmpty_2311104008()) {
        root = new Pohon{data, NULL, NULL, NULL};
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat." << endl;
    }
}

// Tambah kiri
Pohon *insertLeft_2311104008(char data, Pohon *node) {
    if (isEmpty_2311104008()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->left != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->left = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
    return baru;
}

// Tambah kanan
Pohon *insertRight_2311104008(char data, Pohon *node) {
    if (isEmpty_2311104008()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    if (node->right != NULL) {
        cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
        return NULL;
    }
    Pohon *baru = new Pohon{data, NULL, NULL, node};
    node->right = baru;
    cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
    return baru;
}

// Fungsi rekursif untuk menghitung jumlah simpul daun
int cari_simpul_daun(Pohon *node) {
    if (!node) { // Jika node adalah null
        return 0;
    }
    if (!node->left && !node->right) { // Jika node tidak memiliki anak kiri dan kanan
        return 1;
    }
    // Hitung jumlah simpul daun pada subtree kiri dan kanan
    return cari_simpul_daun(node->left) + cari_simpul_daun(node->right);
}

// Fungsi menampilkan menu
void menu_2311104008() {
    int choice;
    char data;
    Pohon *node = NULL;

    do {
        cout << "\n=== Menu Binary Tree ===\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Child Kiri\n";
        cout << "3. Tambah Child Kanan\n";
        cout << "4. Hitung Simpul Daun\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode_2311104008(data);
                break;
            case 2:
                cout << "Masukkan data untuk child kiri: ";
                cin >> data;
                node = root;
                insertLeft_2311104008(data, node);
                break;
            case 3:
                cout << "Masukkan data untuk child kanan: ";
                cin >> data;
                node = root;
                insertRight_2311104008(data, node);
                break;
            case 4:
                cout << "Jumlah simpul daun: " << cari_simpul_daun(root) << endl;
                break;
            case 5:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 5);
}

int main() {
    init_2311104008();
    menu_2311104008();
    return 0;
}
