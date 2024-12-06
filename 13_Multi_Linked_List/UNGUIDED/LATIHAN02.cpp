#include <iostream>
#include <string>

using namespace std;

struct BookNode {
    string book_title;
    string return_date;  
    BookNode* next;

    BookNode(string title, string date) : book_title(title), return_date(date), next(nullptr) {}
};

struct MemberNode {
    string member_name;
    string member_id;
    BookNode* books;  
    MemberNode* next;

    MemberNode(string name, string id) : member_name(name), member_id(id), books(nullptr), next(nullptr) {}
};

class LibraryManager {
private:
    MemberNode* head;  

public:
    LibraryManager() : head(nullptr) {}

    void addMember(string name, string id) {
        MemberNode* new_member = new MemberNode(name, id);
        if (!head) {
            head = new_member;
        } else {
            MemberNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_member;
        }
    }

    void addBookToMember(string member_id, string book_title, string return_date) {
        MemberNode* member = findMember(member_id);
        if (member) {
            BookNode* new_book = new BookNode(book_title, return_date);
            if (!member->books) {
                member->books = new_book;
            } else {
                BookNode* current = member->books;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_book;
            }
        } else {
            cout << "Member with ID " << member_id << " not found." << endl;
        }
    }

    MemberNode* findMember(string member_id) {
        MemberNode* current = head;
        while (current) {
            if (current->member_id == member_id) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void removeMemberAndBooks(string member_id) {
        MemberNode* current = head;
        MemberNode* prev = nullptr;

        while (current) {
            if (current->member_id == member_id) {
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                BookNode* current_book = current->books;
                while (current_book) {
                    BookNode* temp = current_book;
                    current_book = current_book->next;
                    delete temp;
                }
                delete current;
                cout << "Member " << member_id << " and their borrowed books have been removed." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Member with ID " << member_id << " not found." << endl;
    }

    void displayData() {
        MemberNode* current_member = head;
        while (current_member) {
            cout << "Member: " << current_member->member_name << " (ID: " << current_member->member_id << ")" << endl;
            BookNode* current_book = current_member->books;
            while (current_book) {
                cout << "  Book: " << current_book->book_title << ", Return Date: " << current_book->return_date << endl;
                current_book = current_book->next;
            }
            current_member = current_member->next;
        }
    }

    ~LibraryManager() {
        MemberNode* current_member = head;
        while (current_member) {
            BookNode* current_book = current_member->books;
            while (current_book) {
                BookNode* temp = current_book;
                current_book = current_book->next;
                delete temp;
            }
            MemberNode* temp = current_member;
            current_member = current_member->next;
            delete temp;
        }
    }
};

int main() {
    LibraryManager manager;

    cout << "1. Masukkan data anggota berikut:" << endl;
    manager.addMember("Rani", "A001");
    manager.addMember("Dito", "A002");
    manager.addMember("Vina", "A003");
    cout << "  - Anggota 1: Nama = \"Rani\", ID = \"A001\"." << endl;
    cout << "  - Anggota 2: Nama = \"Dito\", ID = \"A002\"." << endl;
    cout << "  - Anggota 3: Nama = \"Vina\", ID = \"A003\"." << endl;

    cout << "\n2. Tambahkan buku yang dipinjam:" << endl;
    manager.addBookToMember("A001", "Pemrograman C++", "01/12/2024");
    manager.addBookToMember("A002", "Algoritma Pemrograman", "15/12/2024");
    cout << "  - Buku 1: Judul = \"Pemrograman C++\", Pengembalian = \"01/12/2024\" (Untuk Rani)." << endl;
    cout << "  - Buku 2: Judul = \"Algoritma Pemrograman\", Pengembalian = \"15/12/2024\" (Untuk Dito)." << endl;

    cout << "\n3. Tambahkan buku baru:" << endl;
    manager.addBookToMember("A001", "Struktur Data", "10/12/2024");
    cout << "  - Buku 3: Judul = \"Struktur Data\", Pengembalian = \"10/12/2024\" (Untuk Rani)." << endl;

    cout << "\n4. Hapus anggota Dito beserta buku yang dipinjam." << endl;
    manager.removeMemberAndBooks("A002");

    cout << "\n5. Tampilkan seluruh data anggota dan buku yang dipinjam." << endl;
    manager.displayData();

    return 0;
}
