#include <stdio.h>
#include "penjualan.h"
#include "barang.h"
#include "member.h"

#define MAKS_PENJUALAN 200

// Struktur untuk mencatat penjualan
typedef struct {
    int idBarang;
    int jumlah;
    float totalHarga;
} Penjualan;

// Variabel global untuk menyimpan data penjualan
Penjualan penjualan[MAKS_PENJUALAN];
int jumlahPenjualan = 0;

void prosesPenjualan() {
    int idBarang, jumlahBeli, ditemukan = 0;
    float totalHarga = 0;

    printf("\n=== Proses Penjualan ===\n");
    printf("Masukkan ID barang: ");
    scanf("%d", &idBarang);

    // Cari barang berdasarkan ID
    for (int i = 0; i < jumlahBarang; i++) {
        if (barang[i].id == idBarang) {
            ditemukan = 1;
            printf("Masukkan jumlah yang dibeli: ");
            scanf("%d", &jumlahBeli);

            // Periksa apakah stok cukup
            if (jumlahBeli > barang[i].stok) {
                printf("Stok tidak mencukupi! Stok tersedia: %d\n", barang[i].stok);
                return;
            }

            // Update stok barang
            barang[i].stok -= jumlahBeli;

            // Hitung total harga
            totalHarga = barang[i].harga * jumlahBeli;

            // Simpan data penjualan
            penjualan[jumlahPenjualan].idBarang = idBarang;
            penjualan[jumlahPenjualan].jumlah = jumlahBeli;
            penjualan[jumlahPenjualan].totalHarga = totalHarga;
            jumlahPenjualan++;

            printf("Penjualan berhasil diproses! Total harga: Rp %.2f\n", totalHarga);
            return;
        }
    }

    if (!ditemukan) {
        printf("Barang dengan ID %d tidak ditemukan.\n", idBarang);
    }
}

void laporanPenjualan() {
    printf("\n=== Laporan Penjualan ===\n");

    if (jumlahPenjualan == 0) {
        printf("Belum ada transaksi yang tercatat.\n");
        return;
    }

    // Tampilkan semua data penjualan
    for (int i = 0; i < jumlahPenjualan; i++) {
        printf("Penjualan %d:\n", i + 1);
        printf("  ID Barang: %d\n", penjualan[i].idBarang);
        printf("  Jumlah: %d\n", penjualan[i].jumlah);
        printf("  Total Harga: Rp %.2f\n", penjualan[i].totalHarga);
    }
}
