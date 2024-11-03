#include <iostream>
#include <stack>
#include <string>
#include <cctype> // untuk fungsi tolower

using namespace std;

bool is_palindrome(const string& sentence) {
    stack<char> charStack;
    string cleaned_sentence;

    // Menghapus spasi dan mengubah ke huruf kecil
    for (char ch : sentence) {
        if (isalnum(ch)) { 
            char lowerChar = tolower(ch);
            cleaned_sentence += lowerChar;
            charStack.push(lowerChar); 
        }
    }

    // Membalikkan string dengan stack
    string reversed_sentence;
    while (!charStack.empty()) {
        reversed_sentence += charStack.top();
        charStack.pop();
    }

    // Membandingkan kalimat asli dengan kalimat yang dibalik
    return cleaned_sentence == reversed_sentence;
}

int main() {
    string user_input;
    cout << "Masukkan kalimat: ";
    getline(cin, user_input);

    // Mengecek apakah kalimat tersebut palindrom
    if (is_palindrome(user_input)) {
        cout << "Kalimat tersebut adalah : palindrom." << endl;
    } else {
        cout << "Kalimat tersebut adalah bukan palindrom." << endl;
    }

    return 0;
}

// Cara Kerja Program
// 1. Penghapusan Karakter Tidak Relevan:
//       Program membersihkan kalimat input dengan menyimpan hanya karakter alfanumerik (huruf dan angka) menggunakan isalnum(), mengabaikan spasi dan tanda baca.
// 2. Normalisasi Karakter:
//       Karakter valid diubah menjadi huruf kecil dengan tolower() dan disimpan dalam string cleaned_sentence serta stack charStack.
// 3. Membalik Kalimat dengan Stack:
//       Setelah karakter dimasukkan ke dalam stack, program membalik kalimat dengan mengambil karakter dari stack menggunakan top() dan pop(), membentuk string reversed_sentence.
// 4.Perbandingan:
//       Program membandingkan cleaned_sentence dengan reversed_sentence. Jika keduanya sama, kalimat adalah palindrom; jika tidak, kalimat bukan palindrom.
