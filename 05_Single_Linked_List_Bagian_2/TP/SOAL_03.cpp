#include <iostream>

struct Node {
    int data;
    Node* next;
};

void insertSorted(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr || head->data >= value) {
        newNode->next = head; 
        head = newNode;
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data < value) {
        prev = current; 
        current = current->next; 
    }
    newNode->next = current; 
    prev->next = newNode; 
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;

    for (int i = 0; i < 4; i++) {
        int num;
        std::cout << "Masukkan elemen integer ke-" << i + 1 << ": ";
        std::cin >> num;

        insertSorted(head, num);
    }
    std::cout << "List setelah memasukkan 4 elemen: ";
    printList(head);

    int additionalValue;
    std::cout << "Masukkan elemen tambahan yang ingin dimasukkan: ";
    std::cin >> additionalValue;

    insertSorted(head, additionalValue);

    std::cout << "List setelah elemen tambahan dimasukkan: ";
    printList(head);

    return 0;
}