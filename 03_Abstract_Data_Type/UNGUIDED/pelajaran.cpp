#include "pelajaran.h"
#include <iostream>

pelajaran create_pelajaran(std::string namapel, std::string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    std::cout << "Nama Pelajaran: " << pel.namaMapel << std::endl;
    std::cout << "Nilai: " << pel.kodeMapel << std::endl;
}