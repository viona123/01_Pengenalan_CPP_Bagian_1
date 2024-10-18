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

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Nilai ditemukan
        }
        current = current->next;
    }
    return false; // Nilai tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int countLength(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
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

    // Mencari node dengan nilai tertentu
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        std::cout << "Node dengan nilai " << searchValue << " ditemukan." << std::endl;
    } else {
        std::cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << std::endl;
    }

    // Menghitung panjang linked list
    int length = countLength(head);
    std::cout << "Panjang linked list: " << length << std::endl;

    // Mencetak linked list
    std::cout << "Isi linked list: ";
    printList(head);

    // Menghapus semua node untuk menghindari memory leak
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}