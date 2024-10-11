#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa{ //mendifinisika data mahasiswa
    char nim [10]; //menyimpan nim dengan maksimal 10 karakter
    int nilai1, nilai2; //menyimpan nilai mhasiswa dalam bentuk int
};

void inputMhs(mahasiswa &m); // fungsi yang menerima input dari pengguna
float rata2(mahasiswa m); // fungsi untuk menghitung rata rata nilai mahasiswa yang diinputkan

int main() 
{
    mahasiswa mhs;  //deklarasi 
    inputMhs(mhs);
    cout << "rata-rata = " << rata2(mhs);
    return  0;
}

//perbedaan &m untuk memanggil lokasi dan m hanya variabel saja
void inputMhs(mahasiswa &m){ //inputkan nim, nilai1, nilai2
    cout << "input nim = "; 
    cin >> m.nim;
    cout << "input nilai1 = ";
    cin >> m.nilai1;
    cout << "input nilai2 = ";
    cin >> m.nilai2;
}

float rata2 (mahasiswa m){
    return (m.nilai1 + m.nilai2) /2.0; //menginpuntkan nilai dan dibagi 2
}