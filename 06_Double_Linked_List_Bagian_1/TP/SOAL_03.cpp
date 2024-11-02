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
    // Konstruktor
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

    // Fungsi untuk menampilkan elemen dari depan ke belakang
    void displayForward_2311104008() { 
        Node* current = head;
        cout << "Daftar elemen dari depan ke belakang: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> "; 
            }
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menampilkan elemen dari belakang ke depan
    void displayBackward_2311104008() {
        Node* current = tail;
        cout << "Daftar elemen dari belakang ke depan: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->prev != nullptr) {
                cout << " <-> ";
            }
            current = current->prev;
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
    int elemen;
    cout << "Masukkan 4 elemen secara berurutan: " << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Elemen " << (i + 1) << ": ";
        cin >> elemen;
        dll.insertLast_2311104008(elemen); 
    }

    // Menampilkan elemen dari depan ke belakang
    dll.displayForward_2311104008();

    // Menampilkan elemen dari belakang ke depan
    dll.displayBackward_2311104008();

    return 0;
}