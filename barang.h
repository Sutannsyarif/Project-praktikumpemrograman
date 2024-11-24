#ifndef BARANG_H
#define BARANG_H

#define MAKS_BARANG 100

typedef struct {
    int id;
    char nama[50];
    char kategori[30];
    float harga;
    int stok;
} Barang;

extern Barang barang[MAKS_BARANG];
extern int jumlahBarang;

void tambahBarang();
void hapusBarang();
void ubahStokBarang();
void daftarBarang();

#endif
