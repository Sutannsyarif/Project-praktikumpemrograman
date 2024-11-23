#include <stdio.h>

int main() {
    char nama_barang[50];
    float harga, total, bayar, kembalian;
    int jumlah;
    
    // Header
    printf("=== Program Kasir Sederhana ===\n\n");
    
    // Input data
    printf("Masukkan nama barang: ");
    scanf("%s", nama_barang);
    
    printf("Masukkan harga barang: Rp ");
    scanf("%f", &harga);
    
    printf("Masukkan jumlah barang: ");
    scanf("%d", &jumlah);
    
    // Hitung total
    total = harga * jumlah;
    
    // Tampilkan struk
    printf("\n=== Struk Pembayaran ===\n");
    printf("Nama Barang: %s\n", nama_barang);
    printf("Harga Barang: Rp %.2f\n", harga);
    printf("Jumlah Barang: %d\n", jumlah);
    printf("Total Pembayaran: Rp %.2f\n", total);
    
    // Proses pembayaran
    printf("\nMasukkan jumlah uang: Rp ");
    scanf("%f", &bayar);
    
    // Hitung kembalian
    kembalian = bayar - total;
    printf("Kembalian: Rp %.2f\n", kembalian);
    printf("\nTerima kasih telah berbelanja!\n");
    
    return 0;
}
