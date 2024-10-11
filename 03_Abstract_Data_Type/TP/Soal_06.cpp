#include <iostream>
#include <cmath>

using namespace std;

class Kerucut {
private:
    double jari_jari;  
    double tinggi;     

public:
    Kerucut(double r, double t) {
        jari_jari = r;
        tinggi = t;
    }

    double hitungVolume() {
        return (1.0 / 3.0) * M_PI * pow(jari_jari, 2) * tinggi;
    }

    double hitungLuasPermukaan() {
        double garisLukis = sqrt(pow(jari_jari, 2) + pow(tinggi, 2)); 
        return M_PI * jari_jari * (jari_jari + garisLukis);
    }

    void tampilkan() {
        cout << "Jari-jari: " << jari_jari << endl;
        cout << "Tinggi: " << tinggi << endl;
    }
};

int main() {
    Kerucut kerucut(2, 6);

    kerucut.tampilkan();

    cout << "Volume kerucut: " << kerucut.hitungVolume() << endl;
    cout << "Luas permukaan kerucut: " << kerucut.hitungLuasPermukaan() << endl;

    return 0;
}
