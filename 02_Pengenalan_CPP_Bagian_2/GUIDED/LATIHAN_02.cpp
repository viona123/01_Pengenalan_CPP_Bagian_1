/* #include <iostream> //memanggil library
#include <conio.h>

using namespace std;
int main(){
    int x,y; //x dan y bertipe int
    int *px; //merupakan variabel pointer menujuk kearah variabel int
    x = 87; //penddeklarasian
    px = &x;
    y = *px;

    cout <<"Alamat x= "<<&x<<endl;
    cout <<"Isi px= "<<px<<endl;
    cout <<"Isi x= "<<x<<endl;
    cout <<"Nilai yang ditunjuk x= "<<*px<<endl;
    cout <<"Nilai y= "<<y<<endl;
    getch();
    return 0;
}*/


#include <iostream>
#include <conio.h>
#define MAX 5 //ukuran array
using namespace std;

int main(){
    int i,j;
    float nilai_total, rata_rata;
    float nilai [MAX];
    static int nilai_tahun[MAX] [MAX] =
    {
        {0,2,2,0,0},
        {0,1,1,1,0},
        {0,3,3,3,0},
        {4,4,0,0,4},
        {5,0,0,0,5}
    };
    /* inisialisasi array dua dimensi */
    for (i=0; i<MAX; i++){
        cout<<"Masukan nilai ke-"<<i+1<<endl;
        cin>>nilai[i];
    }
    cout<<"\ndata nilai siswa :\n";

    /* menampilkan array satu dimensi */
    for (i=0; i<MAX; i++)
    cout<<"nilai k-"<<i+1<<"=" <<nilai[i]<<endl;
    cout<<"\n nilai tahunan: \n";

    /*menampilkan array dua dimensi*/
    for(i=0; i<MAX; i++){
        for (j=0; j<MAX; j++)
        cout<<nilai_tahun[i][j];
        cout<<"\n";
    }
    getch(); //menahal layar agar tidak langsung tertutup saaat layar digunakan
    return 0;
} 


/* #include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int maks3(int a,int b, int c);

int main(){
    system("cls");
    int x,y,z;
    cout<<"masukan nilai nilangan ke-1 =";
    cin>> x;
    cout<<"masukan nilai bilangan ke-2 =";
    cin>>y;
    cout<<"masukan nilai bilangan ke-3 =";
    cin>>z;
    cout<<"nilai maksimum nya dalah =" 
        <<maks3(x,y,z);

        getche ();
        return 0;
}
int maks3(int a, int b, int c){
    int temp_max =a;
    if(b>temp_max)
        temp_max=b;
    if(c>temp_max)
        temp_max=c;
        return (temp_max);
} */