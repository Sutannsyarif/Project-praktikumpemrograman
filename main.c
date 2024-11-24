#include <stdio.h>
#include <stdlib.h>
#include "auth.h"
#include "barang.h"
#include "member.h"
#include "penjualan.h"

int main() {
    int pilihan;

    login();

    do {
        printf("\n=== Menu Utama ===\n");
        printf("1. Tambah Barang\n");
        printf("2. Hapus Barang\n");
        printf("3. Ubah Stok Barang\n");
        printf("4. Daftar Barang\n");
        printf("5. Tambah Member\n");
        printf("6. Proses Pembayaran\n");
        printf("7. Laporan Penjualan\n");
        printf("8. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
        case 1:
            tambahBarang();
            break;
        case 2:
            hapusBarang();
            break;
        case 3:
            ubahStokBarang();
            break;
        case 4:
            daftarBarang();
            break;
        case 5:
            tambahMember();
            break;
        case 6:
            prosesPenjualan();
            break;
        case 7:
            laporanPenjualan();
            break;
        case 8:
            printf("Keluar dari program...\n");
            break;
        default:
            printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 8);

    return 0;
}
