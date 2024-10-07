#include <iostream>

using namespace std;

int main(){
    int bilangan, asli, jumlah;

    cout << "Masukkan bilangan asli: ";
    cin >> asli;

    bilangan = 1;
    jumlah = 0;
    while (bilangan <= asli){
        if (bilangan % 2 == 0){
            jumlah += bilangan;
        }
        bilangan++;
    }
    cout << "Jumlah bilangan genap: " << jumlah << endl;
    return 0;
}

#include <iostream>

/*using namespace std;
int main(){
    int a, b, bilangan;
    cout << "Masukan batas bawah: ";
    cin >> a;
    cout << "Masukan batas atas: ";
    cin >> b;
    for (bilangan = a; bilangan <= b; bilangan++){
        cout << "Bilangan " << bilangan << endl;
    }
    return 0;
}*/

/*#include <iostream>

using namespace std;

int main(){
    int nilai;
    cin >> nilai;
    if (nilai > 80){
        cout << "A" << endl;
    } else {
        cout << "Bukan A" << endl;
    }
    return 0;
}*/

/*int main(){
    int bil1 = 2, bil2 = 3, hasil;
    hasil = bil1 <= bil2 and bil1 < bil2;
    cout << hasil << endl;
    hasil = bil1 >= bil2 or bil1 < bil2;
    cout << hasil << endl;
    hasil = not(bil1 >= bil2) or bil1 < bil2;
    cout << hasil << endl;
    return 0;
}*/


/*int main(){
    int bil1 = 2, bil2 = 3, hasil;
    hasil = bil1 > bil2;
    cout << hasil << endl;
    hasil = bil1 >= bil2;
    cout << hasil << endl;
    hasil = bil1 < bil2;
    cout << hasil << endl;
    hasil = bil1 <= bil2;
    cout << hasil << endl;
    hasil = bil1 == bil2;
    cout << hasil << endl;
    hasil = bil1 != bil2;
    cout << hasil << endl;
    return 0;
}*/

/*int main(){
    int bil1 = 3, bil2 = 4, hasil1;
    float bil3 = 3.0, bil4 = 4.0, hasil2;
    hasil1  = bil1 + bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 - bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 * bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 / bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 / bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 % bil2;
    cout << hasil1 << endl;
    hasil1 = bil1 % bil2;
    cout << hasil1 << endl;
    hasil2 = bil3 / bil4;
    cout << hasil2 << endl;
    return 0;
}*/



/*#include <iostream>

using namespace std;

int main(){
    string nama, nim;
    cout << "Siapa nama anda? ";
    cin >> nama;
    cout << "Berapa nim anda? ";
    cin >> nim;
    cout << "Nama saya:" << nama << endl;
    cout << "NIM saya:" << nim << endl;
    return 0;
}*/

/* #include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Masukan angka: ";
    cin >> n;

    for (int i = n; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            cout << "    ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << "  ";
        }
        cout << "*  ";
        for (int j = 2; j <= i; j++) {
            cout << j << "  ";
        }
        cout << endl;
    }
    for (int j = n; j > 0; j--) {
        cout << "    ";
    }
    cout << "*" << endl;

    return 0;
}*/

/*#include <iostream>
#include <string>

using namespace std;

string angka_satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
string angka_puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

int main() {
    int num;
    cout << "Masukan angka 0-100: ";
    cin >> num;
    if (num < 10) {
        cout << num << " (" << angka_satuan[num] << ")" << endl;
    } else if (num < 20) {
        switch (num) {
            case 10:
                cout << num << " (sepuluh)" << endl;
                break;
            case 11:
                cout << num << " (sebelas)" << endl;
                break;
            default:
                cout << num << " (" << angka_puluhan[num / 10] << " " << angka_satuan[num % 10] << ")" << endl;
        }
    } else {
        cout << num << " (" << angka_puluhan[num / 10] << (num % 10 > 0 ? " " + angka_satuan[num % 10] : "") << ")" << endl;
    }
    return 0;
}*/





/*#include <iostream>

using namespace std;

int main(){
    float num1, num2;

    cout << "Masukan nilai ke 1: ";
    cin >> num1;
    cout << "Masukan nilai ke 2: ";
    cin >> num2;

    cout << "Hasil Dari dua bilangan: " << endl;
    cout << "Penjumlahan: " << num1 + num2 << endl;
    cout << "Penguragan: " << num1 - num2 << endl;
    cout << "Perkalian: " << num1 * num2 << endl;
    if (num2 != 0){
            cout << "Pembagian: " << num1 / num2 << endl;
    } else{
        cout << "Error nilai yang anda dapat 0" << endl;
    }

    return 0;
}*/


