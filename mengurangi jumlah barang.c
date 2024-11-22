#include <stdio.h>

struct Barang {
    char nama[20];
    int harga;
    int stok;
};

int main() {
    struct Barang brg[5] = {
        {"Aqua", 5000, 100},
        {"Sendal", 20000, 200},
        {"AlQuran", 100000, 115},
        {"Parfume", 30000, 200},
        {"KucingMuchkin", 2300000, 2}
		
		
    };
    
    int pilihan, jumlah;
    
    while(1) {
        printf("\nDaftar Barang:\n");
        for(int i = 0; i < 5; i++) {
            printf("%d. %s (Rp%d) - Stok: %d\n", 
                   i+1, brg[i].nama, brg[i].harga, brg[i].stok);
        }
        
        printf("\nPilih barang (1-5) atau 0 untuk keluar: ");
        scanf("%d", &pilihan);
        
        if(pilihan == 0) break;
        if(pilihan < 1 || pilihan > 5) continue;
        
        printf("Jumlah beli: ");
        scanf("%d", &jumlah);
        
        if(jumlah <= brg[pilihan-1].stok) {
            brg[pilihan-1].stok -= jumlah;
            printf("Total: Rp%d\n", brg[pilihan-1].harga * jumlah);
        } else {
            printf("Stok tidak cukup!\n");
        }
    }
    return 0;
}
