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

// Ubah Data Tree
void update_2311104008(char data, Pohon *node) {
    if (isEmpty_2311104008()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ingin diganti tidak ada!" << endl;
        return;
    }
    char temp = node->data;
    node->data = data;
    cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

// Lihat isi Data Tree
void retrieve_2311104008(Pohon *node) {
    if (isEmpty_2311104008()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData node: " << node->data << endl;
}

// Cari Data Tree
void find_2311104008(Pohon *node) {
    if (isEmpty_2311104008()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return;
    }
    if (!node) {
        cout << "\nNode yang ditunjuk tidak ada!" << endl;
        return;
    }
    cout << "\nData Node: " << node->data << endl;
    cout << "Root: " << root->data << endl;
    cout << "Parent: " << (node->parent ? string(1, node->parent->data) : "tidak punya parent") << endl;


    if (node->parent) {
        if (node->parent->left == node && node->parent->right)
            cout << "Sibling: " << node->parent->right->data << endl;
        else if (node->parent->right == node && node->parent->left)
            cout << "Sibling: " << node->parent->left->data << endl;
        else
            cout << "Sibling: (tidak ada sibling)" << endl;
    }
}

// Fungsi untuk menampilkan child
void showChildren_2311104008(Pohon *node) {
    if (!node) {
        cout << "Node tidak ada!" << endl;
        return;
    }
    cout << "Child dari node " << node->data << ": ";
    if (node->left) {
        cout << node->left->data << " (kiri) ";
    }
    if (node->right) {
        cout << node->right->data << " (kanan) ";
    }
    cout << endl;
}

// Fungsi untuk menampilkan semua descendant
void showDescendants_2311104008(Pohon *node) {
    if (!node) return;
    if (node->left) {
        cout << node->left->data << " ";
        showDescendants_2311104008(node->left);
    }
    if (node->right) {
        cout << node->right->data << " ";
        showDescendants_2311104008(node->right);
    }
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
        cout << "4. Ubah Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Cari Node\n";
        cout << "7. Tampilkan Child Node\n";
        cout << "8. Tampilkan Descendant Node\n";
        cout << "9. Keluar\n";
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
                cout << "Masukkan data baru: ";
                cin >> data;
                update_2311104008(data, root);
                break;
            case 5:
                retrieve_2311104008(root);
                break;
            case 6:
                find_2311104008(root);
                break;
            case 7:
                showChildren_2311104008(root);
                break;
            case 8:
                cout << "Descendant dari node: ";
                showDescendants_2311104008(root);
                cout << endl;
                break;
            case 9:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 9);
}

int main() {
    init_2311104008();
    menu_2311104008();
    return 0;
}


