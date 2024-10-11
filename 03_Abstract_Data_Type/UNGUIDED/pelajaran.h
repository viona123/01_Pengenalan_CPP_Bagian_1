#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>

typedef struct {
    std::string namaMapel;
    std::string kodeMapel;
} pelajaran;

pelajaran create_pelajaran(std::string namapel, std::string kodepel);
void tampil_pelajaran(pelajaran pel);

#endif  // PELAJARAN_H