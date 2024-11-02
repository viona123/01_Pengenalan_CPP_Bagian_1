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

    // Fungsi untuk menambahkan elemen di awal list
    void insertFirst_2311104008(int value) { 
        Node* newNode = new Node{value, nullptr, nullptr};
        if (head == nullptr) { 
            head = newNode;
            tail = newNode;
        } else { 
            newNode->next = head; 
            head->prev = newNode; 
            head = newNode;       
        }
    }

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

  
    void display_2311104008() { 
        Node* current = head;
        cout << "DAFTAR ANGGOTA LIST: ";
        while (current != nullptr) {
            cout << current->data;
            if (current->next != nullptr) {
                cout << " <-> "; 
            }
            current = current->next;
        }
        cout << endl;
    }

    Node* searchNode_2311104008(int value) { 
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr; 
    }

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

    cout << "Masukkan elemen kedua di awal = ";
    cin >> elemenKedua;
    dll.insertFirst_2311104008(elemenKedua); 

    cout << "Masukkan elemen ketiga di akhir = ";
    cin >> elemenKetiga;
    dll.insertLast_2311104008(elemenKetiga); 

    // Menampilkan seluruh elemen dalam list
    dll.display_2311104008();

    return 0;
}