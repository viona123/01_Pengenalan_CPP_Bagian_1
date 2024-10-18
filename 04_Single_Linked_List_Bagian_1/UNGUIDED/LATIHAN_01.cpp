#include <iostream>

using namespace std;

// Definisi struct Node
struct Node {
    int data;       // Data yang disimpan dalam node
    Node* next;     // Pointer ke node berikutnya

    // Konstruktor untuk inisialisasi node
    Node(int value) {
        data = value;
        next = nullptr; // Node berikutnya diinisialisasi ke null
    }
};

// Kelas LinkedList
class LinkedList {
private:
    Node* head; // Pointer ke node pertama

public:
    // Konstruktor
    LinkedList() {
        head = nullptr; // Linked list kosong
    }

    // Fungsi untuk menambah node di depan
    void insertAtFront(int value) {
        Node* newNode = new Node(value); // Membuat node baru
        newNode->next = head; // Menghubungkan node baru dengan head saat ini
        head = newNode; // Memperbarui head ke node baru
    }

    // Fungsi untuk menambah node di belakang
    void insertAtBack(int value) {
        Node* newNode = new Node(value); // Membuat node baru
        if (head == nullptr) { // Jika linked list kosong
            head = newNode; // Node baru menjadi head
            return;
        }

        Node* temp = head; // Menggunakan pointer sementara untuk traversing
        while (temp->next != nullptr) { // Mencari node terakhir
            temp = temp->next;
        }
        temp->next = newNode; // Menambahkan node baru di belakang
    }

    // Fungsi untuk mencetak seluruh isi linked list
    void printList() {
        Node* temp = head; // Menggunakan pointer sementara untuk traversing
        while (temp != nullptr) {
            cout << temp->data; // Mencetak data dari node
            if (temp->next != nullptr) {
                cout << " -> "; // Menambahkan panah jika bukan node terakhir
            }
            temp = temp->next; // Melanjutkan ke node berikutnya
        }
        cout << endl;
    }

    // Destruktor untuk menghapus semua node saat linked list dihapus
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->next; // Menyimpan node berikutnya
            delete current; // Menghapus node saat ini
            current = nextNode; // Melanjutkan ke node berikutnya
        }
    }
};

// Fungsi utama
int main() {
    LinkedList list; // Membuat objek linked list

    // Operasi sesuai dengan contoh
    list.insertAtFront(10); // Tambah node di depan (nilai: 10)
    list.insertAtBack(20); // Tambah node di belakang (nilai: 20)
    list.insertAtFront(5); // Tambah node di depan (nilai: 5)

    // Cetak linked list
    cout << "Isi Linked List: ";
    list.printList(); // Output: 5 -> 10 -> 20

    return 0;
}