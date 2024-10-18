#include <iostream>
#include "list.h"

using namespace std;

int main() {
    List L;
    createList(L); 

    for (int i = 1; i <= 10; i++) { 
        int digit;
        cout << "Digit " << i << " : ";
        cin >> digit;

        address P = allocate(digit);

        insertLast(L, P); 
    }

    cout << "Isi list : ";
    printInfo(L); 

    return 0;
}

