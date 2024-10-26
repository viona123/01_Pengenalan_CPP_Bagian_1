#include <iostream>
#include <string>

using namespace std;

// Struktur untuk node dalam linked list
struct Node {
    string nim; // Ubah nim menjadi string untuk menyimpan 10 digit
    string nama;
    Node* next;
};

// Kelas untuk Single Linked List
class SingleLinkedList {
private:
    Node* head;

public:
    // Konstruktor
    SingleLinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan data mahasiswa
    void tambahMahasiswa(const string& nim, const string& nama) {
        Node* newNode = new Node();
        newNode->nim = nim;
        newNode->nama = nama;
        newNode->next = head;
        head = newNode;
        cout << "Mahasiswa dengan NIM " << nim << " berhasil ditambahkan.\n";
    }

    // Fungsi untuk mencari mahasiswa berdasarkan NIM
    void cariMahasiswa(const string& nim) {
        Node* current = head;
        while (current != nullptr) {
            if (current->nim == nim) {
                cout << "Mahasiswa ditemukan: " << current->nama << endl;
                return;
            }
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan.\n";
    }

    // Destructor untuk membersihkan memori
    ~SingleLinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    SingleLinkedList list;
    int choice;
    string nim, nama;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Cari Mahasiswa\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                do {
                    cout << "Masukkan NIM (10 digit): ";
                    cin >> nim;
                    if (nim.length() != 10) {
                        cout << "NIM harus terdiri dari 10 digit. Silakan coba lagi.\n";
                    }
                } while (nim.length() != 10);
                
                cout << "Masukkan Nama: ";
                cin.ignore(); // Untuk membersihkan newline dari input sebelumnya
                getline(cin, nama);
                list.tambahMahasiswa(nim, nama);
                break;
            case 2:
                cout << "Masukkan NIM yang dicari: ";
                cin >> nim;
                if (nim.length() != 10) {
                    cout << "NIM harus terdiri dari 10 digit.\n";
                } else {
                    list.cariMahasiswa(nim);
                }
                break;
            case 3:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 3);

    return 0;
}