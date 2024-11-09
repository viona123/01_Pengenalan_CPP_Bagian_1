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

        // If the queue is empty or the new node has a smaller NIM than the front
        if (isEmpty() || nim < front->nim) {
            newNode->next = front;
            front = newNode;
            if (back == nullptr) { // If the queue was empty, set back to new node
                back = newNode;
            }
        } else {
            // Find the correct position to insert the new node
            Node* current = front;
            while (current->next != nullptr && current->next->nim < nim) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;

            // Update back if the new node is added at the end
            if (newNode->next == nullptr) {
                back = newNode;
            }
        }
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

    // Input number of students
    int n;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, nim;
        cout << "Masukkan nama mahasiswa: ";
        cin >> name;
        cout << "Masukkan NIM mahasiswa: ";
        cin >> nim;
        queue.enqueueAntrian(name, nim);
    }

    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    // Dequeue one student
    queue.dequeueAntrian();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    // Clear the queue
    queue.clearQueue();
    queue.viewQueue();
    cout << "Jumlah antrian = " << queue.countQueue() << endl;

    return 0;
}