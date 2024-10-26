#include <iostream>

struct Node {
    int data;
    Node* next;
};

void bubbleSortList(Node* head) {
    if (head == NULL) return; 
    bool swapped;
    do {
        swapped = false;
        Node* current = head;

        while (current->next != NULL) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true; 
            }
            current = current->next; 
        }
    } while (swapped); 
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < 5; i++) {
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
    bubbleSortList(head);

    std::cout << "List setelah diurutkan: ";
    printList(head);

    return 0;
}