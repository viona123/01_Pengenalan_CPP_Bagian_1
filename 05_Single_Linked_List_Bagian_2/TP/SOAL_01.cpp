#include <iostream>

struct Node {
    int data;
    Node* next;
};
void searchElement(Node* head, int i) {
    Node* current = head;
    int position = 1;

    while (current != NULL) {
        // Jika elemen ditemukan
        if (current->data == i) {
            std::cout << "Elemen ditemukan pada posisi ke-" << position << " dengan alamat " << current << std::endl;
            return;
        }
        position++;
        current = current->next;
    }
    std::cout << "Elemen tersebut tidak ada dalam list." << std::endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 6; i++) {
        int num;
        std::cout << "Masukkan elemen integer ke-" << i + 1 << ": ";
        std::cin >> num;

        Node* newNode = new Node();
        newNode->data = num;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int searchValue;
    std::cout << "Masukkan nilai yang ingin dicari: ";
    std::cin >> searchValue;
    
    searchElement(head, searchValue);

    return 0;
}