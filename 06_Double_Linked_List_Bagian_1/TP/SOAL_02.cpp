#include <iostream>

using namespace std;

// Struktur Node untuk menyimpan data
struct Node {
    int data;         
    Node* prev;       
    Node* next;     
};

// Kelas untuk mengelola Doubly Linked List
class DoublyLinkedList {
private:
    Node* head;       
    Node* tail;     

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Fungsi untuk menambahkan elemen di akhir list
    void insertLast_2311104008(int value) { 
        Node* newNode = new Node{value, nullptr, nullptr};
        if (tail == nullptr) { 
            head = newNode;
            tail = newNode;
        } else { 
            tail->next = newNode;
            newNode->prev = tail; 
            tail = newNode;       
        }
    }

    // Fungsi untuk menghapus elemen pertama
    void deleteFirst_2311104008() {
        if (head == nullptr) { 
            cout << "List kosong, tidak ada elemen yang dapat dihapus." << endl;
            return;
        }
        Node* temp = head; 
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp; 
    }

    // Fungsi untuk menghapus elemen terakhir
    void deleteLast_2311104008() { 
        if (tail == nullptr) {
            cout << "List kosong, tidak ada elemen yang dapat dihapus." << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr; 
        }
        delete temp; 
    }

    // Fungsi untuk menampilkan seluruh elemen dalam list dari depan ke belakang
    void display_2311104008() { 
        Node* current = head;
        cout << "";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> ";
            }
            current = current->next;
        }
        cout << endl;
    }

    // Destructor untuk membersihkan memori
    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dll;

    // Input dari pengguna
    int elemenPertama, elemenKedua, elemenKetiga;
    cout << "Masukkan elemen pertama = ";
    cin >> elemenPertama;
    dll.insertLast_2311104008(elemenPertama); 

    cout << "Masukkan elemen kedua di akhir = ";
    cin >> elemenKedua;
    dll.insertLast_2311104008(elemenKedua); 

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemenKetiga;
    dll.insertLast_2311104008(elemenKetiga); 

    // Menghapus elemen pertama dan terakhir
    dll.deleteFirst_2311104008();
    dll.deleteLast_2311104008();

    // Menampilkan seluruh elemen dalam list setelah penghapusan
    cout << "DAFTAR ANGGOTA LIST SETELAH PENGHAPUSAN: ";
    dll.display_2311104008();

    return 0;
}