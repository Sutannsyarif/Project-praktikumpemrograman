#include <stdio.h>
#include <string.h>
#include "barang.h"

Barang barang[MAKS_BARANG];
int jumlahBarang = 0;

void tambahBarang() {
    if (jumlahBarang >= MAKS_BARANG) {
        printf("Daftar barang penuh!\n");
        return;
    }

    barang[jumlahBarang].id = jumlahBarang + 1;

    printf("Masukkan nama barang: ");
    scanf("%49s", barang[jumlahBarang].nama);

    printf("Masukkan kategori barang: ");
    scanf("%29s", barang[jumlahBarang].kategori);

    printf("Masukkan harga barang: ");
    if (scanf("%f", &barang[jumlahBarang].harga) != 1) {
        printf("Input tidak valid! Harus berupa angka.\n");
        return;
    }

    printf("Masukkan stok barang: ");
    if (scanf("%d", &barang[jumlahBarang].stok) != 1) {
        printf("Input tidak valid! Harus berupa angka.\n");
        return;
    }

    jumlahBarang++;
    printf("Barang berhasil ditambahkan.\n");
}

void hapusBarang() {
    int id;
    printf("Masukkan ID barang yang ingin dihapus: ");
    if (scanf("%d", &id) != 1) {
        printf("Input tidak valid.\n");
        return;
    }

    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            barang[i] = barang[jumlahBarang - 1]; // Optimalkan penghapusan
            jumlahBarang--;
            printf("Barang berhasil dihapus.\n");
            return;
        }
    }
    printf("Barang tidak ditemukan.\n");
}

void ubahStokBarang() {
    int id, perubahanStok;
    printf("Masukkan ID barang: ");
    if (scanf("%d", &id) != 1) {
        printf("Input tidak valid.\n");
        return;
    }

    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == id) {
            printf("Masukkan perubahan stok (+/-): ");
            if (scanf("%d", &perubahanStok) != 1) {
                printf("Input tidak valid.\n");
                return;
            }
            barang[i].stok += perubahanStok;
            printf("Stok barang berhasil diubah. Stok baru: %d\n", barang[i].stok);
            return;
        }
    }
    printf("Barang tidak ditemukan.\n");
}

void daftarBarang() {
    if (jumlahBarang == 0) {
        printf("Belum ada barang yang terdaftar.\n");
        return;
    }

    printf("\n=== Daftar Barang ===\n");
    for (int i = 0; i < jumlahBarang; i++) {
        printf("ID: %d, Nama: %s, Kategori: %s, Harga: %.2f, Stok: %d\n",
               barang[i].id, barang[i].nama, barang[i].kategori, barang[i].harga, barang[i].stok);
    }
}
