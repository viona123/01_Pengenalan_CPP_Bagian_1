#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di depan
void addFront(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambahkan node di belakang
void addBack(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node*& head, int value) {
    if (head == nullptr) return;

    // Jika node yang ingin dihapus adalah head
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr && current->data != value) {
        previous = current;
        current = current->next;
    }

    // Jika node tidak ditemukan
    if (current == nullptr) return;

    previous->next = current->next;
    delete current;
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data;
        if (temp->next != nullptr) {
            std::cout << " -> ";
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Fungsi utama
int main() {
    Node* head = nullptr;

    // Menambahkan node
    addFront(head, 10);
    addBack(head, 20);
    addFront(head, 5);

    // Menghapus node dengan nilai tertentu
    deleteNode(head, 10);

    // Mencetak linked list
    std::cout << "Linked List setelah penghapusan: ";
    printList(head);

    // Menghapus semua node untuk menghindari memory leak
    while (head != nullptr) {
        deleteNode(head, head->data);
    }

    return 0;
}