#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    string name; // Student's name
    string nim;  // Student's NIM
    Node* next;  // Pointer to the next node
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* back;

public:
    Queue() : front(nullptr), back(nullptr) {}

    ~Queue() {
        clearQueue();
    }

    bool isFull() {
        // A linked list is never full unless memory runs out
        return false;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueueAntrian(string name, string nim) {
        Node* newNode = new Node();
        newNode->name = name;
        newNode->nim = nim;
        newNode->next = nullptr;

        if (isEmpty()) {
            front = newNode;
        } else {
            back->next = newNode;
        }
        back = newNode;
    }

    void dequeueAntrian() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) { // If the queue is now empty
            back = nullptr;
        }
    }

    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    void viewQueue() {
        cout << "Data antrian mahasiswa :" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". Nama: " << current->name << ", NIM: " << current->nim << endl;
            current = current->next;
        }
        while (index <= 5) { // Display empty slots if less than 5
            cout << index++ << ". (kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;

    // Enqueue students with their names and NIMs
    queue.enqueueAntrian("Andi", "123456789");
    queue.enqueueAntrian("Maya", "987654321");
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}