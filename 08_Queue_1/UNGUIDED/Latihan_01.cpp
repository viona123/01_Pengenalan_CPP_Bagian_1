#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    string data;
    Node* next;
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

    void enqueueAntrian(string data) {
        Node* newNode = new Node();
        newNode->data = data;
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
        cout << "Data antrian teller :" << endl;
        Node* current = front;
        int index = 1;
        while (current != nullptr) {
            cout << index++ << ". " << current->data << endl;
            current = current->next;
        }
        while (index <= 5) { // Display empty slots if less than 5
            cout << index++ << ". (kosong)" << endl;
        }
    }
};

int main() {
    Queue queue;

    queue.enqueueAntrian("Andi");
    queue.enqueueAntrian("Maya");
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