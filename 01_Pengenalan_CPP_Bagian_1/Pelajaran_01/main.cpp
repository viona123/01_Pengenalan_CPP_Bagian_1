/*#include <iostream>

using namespace std;

int main(){
    cout << "saya lagi belajar c++ nih" << endl;
    return 0;

}*/6

/* #include <iostream>
int main (){
    int inp;
    cin >> inp;
    cout << "nilai = " << inp;
    return 0;
}*/

/*#include <iostream>
using namespace std;
int main (){
    int W, X, Y; float Z;
    X = 11; Y = 3; W = 1;
    Z = (X + Y)/ (Y+W);
    cout << "nilai = " << Z <<endl;
    return 0;
}*/

/*#include <iostream>
using namespace std;
int main (){
    double tot_pembelian, diskon;
    cout << "total pembelian: Rp";
    cin >> tot_pembelian;
    diskon = 0;
    if(tot_pembelian >= 100000)
        diskon = 0.05*tot_pembelian;
    else
        diskon = 0;
    cout << "besardiskon = Rp" <<diskon;
}*/

#include <iostream>
#include <conio.h>

using namespace std;

int main (){
    int i=1;
    int jum;
    cin>>jum;
    do{
        cout<<"baris ke-"<<i+1<<endl;
        i++;
    }while(i<jum);
    getch();
    return 0;
}
