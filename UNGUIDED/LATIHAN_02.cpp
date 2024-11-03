#include <iostream>
#include <stack>
#include <sstream> 
#include <vector>

using namespace std;

// Fungsi untuk membalik setiap kata dalam kalimat
string reverse_words(const string& sentence) {
    stack<string> wordStack;
    string word;
    string reversedSentence;

    // Menggunakan stringstream untuk memecah kalimat menjadi kata-kata
    stringstream ss(sentence);
    while (ss >> word) {
        wordStack.push(word); // Menyimpan setiap kata ke dalam stack
    }

    // Mengambil kata dari stack untuk membalik urutan
    while (!wordStack.empty()) {
        string currentWord = wordStack.top();
        string reversedWord;

        // Membalikkan kata
        for (int i = currentWord.length() - 1; i >= 0; i--) {
            reversedWord += currentWord[i];
        }

        reversedSentence += reversedWord + " "; // Menambahkan kata yang dibalik ke hasil
        wordStack.pop(); // Menghapus kata dari stack
    }

    // Menghapus spasi tambahan di akhir kalimat
    if (!reversedSentence.empty()) {
        reversedSentence.pop_back(); 
    }

    return reversedSentence;
}

int main() {
    string user_input;

    // Input dari pengguna
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, user_input);

    // Menghitung jumlah kata
    int wordCount = 0;
    stringstream ss(user_input); // Menggunakan stringstream untuk memecah kalimat menjadi kata-kata.
    string tempWord;
    while (ss >> tempWord) {
        wordCount++;
    }

    // Memeriksa apakah kalimat memiliki minimal 3 kata
    if (wordCount < 3) {
        cout << "Kalimat harus terdiri dari minimal 3 kata." << endl;
    } else {
        // Membalik kata-kata dalam kalimat
        string result = reverse_words(user_input);  //fungsi reverse_words untuk membalik setiap kata dalam kalimat dan menampilkan hasilnya.
        cout << "Hasil: " << result << endl;
    }

    return 0;

}