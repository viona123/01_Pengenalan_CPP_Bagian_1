#include <iostream>
#include <string>

using namespace std;

// Struktur Node untuk menyimpan data buku
struct Node {
    int idBuku;               // ID Buku
    string judulBuku;        // Judul Buku
    string penulisBuku;      // Penulis Buku
    Node* prev;              // Pointer ke node sebelumnya
    Node* next;              // Pointer ke node berikutnya
};

// Kelas untuk mengelola Double Linked List
class DaftarBuku {
private:
    Node* head;              // Pointer ke node pertama
    Node* tail;              // Pointer ke node terakhir

public:
    // Konstruktor
    DaftarBuku() : head(nullptr), tail(nullptr) {}

    // Fungsi untuk menambahkan buku di akhir list
    void tambahBuku(int id, const string& judul, const string& penulis) {
        Node* newNode = new Node{id, judul, penulis, nullptr, nullptr};
        if (head == nullptr) { // Jika list kosong
            head = newNode;
            tail = newNode;
        } else { // Jika list tidak kosong
            tail->next = newNode; // Menghubungkan node terakhir dengan node baru
            newNode->prev = tail; // Menghubungkan node baru dengan node terakhir
            tail = newNode; // Memperbarui tail ke node baru
        }
    }

    // Fungsi untuk menampilkan daftar buku dari awal ke akhir
    void tampilkanDariAwal() {
        Node* current = head;
        cout << "Daftar Buku (Dari Awal):" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->idBuku << ", Judul: " << current->judulBuku << ", Penulis: " << current->penulisBuku << endl;
            current = current->next;
        }
    }

    // Fungsi untuk menampilkan daftar buku dari akhir ke awal
    void tampilkanDariAkhir() {
        Node* current = tail;
        cout << "Daftar Buku (Dari Akhir):" << endl;
        while (current != nullptr) {
            cout << "ID: " << current->idBuku << ", Judul: " << current->judulBuku << ", Penulis: " << current->penulisBuku << endl;
            current = current->prev;
        }
    }

    // Destructor untuk membersihkan memori
    ~DaftarBuku() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DaftarBuku daftar;

    // Menambahkan beberapa buku
    daftar.tambahBuku(1, "The Fault in Our Stars", "Scott Neustadter dan Michael H.Weber");
    daftar.tambahBuku(2, "Harry Potter", "Joanne Rowling");
    daftar.tambahBuku(3, "Laut Bercerita", "Leila Salikha Chudori");

    // Menampilkan daftar buku
    daftar.tampilkanDariAwal();
    cout << endl;
    daftar.tampilkanDariAkhir();

    return 0;
}