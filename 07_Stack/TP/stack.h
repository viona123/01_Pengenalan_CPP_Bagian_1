#ifndef STACK_H
#define STACK_H

typedef char infotype;

struct stack {
    infotype info[15];
    int Top;
};

// Membuat stack kosong
void createStack_2311104008(stack &S);

// Mengecek apakah stack kosong
bool isEmpty_2311104008(stack S);

// Mengecek apakah stack penuh
bool isFull_2311104008(stack S);

// Menambahkan elemen ke dalam stack
void push_2311104008(stack &S, infotype x);

// Mengeluarkan elemen dari stack
infotype pop_2311104008(stack &S);

// Menampilkan semua elemen dalam stack
void printInfo_2311104008(stack S);

#endif

