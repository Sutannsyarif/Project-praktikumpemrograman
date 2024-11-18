#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_USERS 5
#define MAX_LENGTH 70

struct User {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];
};


struct User users[MAX_USERS] = {
    {"Atan", "Atan1", "administrator"},
    {"Alhafiz", "Alhafiz2", "kasir"},
    {"Wyna", "Wyna3", "kasir"},
};


bool checkLogin(char *username, char *password, char *role) {
    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(users[i].username, username) == 0 && 
            strcmp(users[i].password, password) == 0) {
            strcpy(role, users[i].role);
            return true;
        }
    }
    return false;
}


void showKasirMenu() {
    printf("\n=== MENU KASIR ===\n");
    printf("1. Input Transaksi\n");
    printf("2. Lihat Riwayat Transaksi\n");
    printf("3. Logout\n");
}


void showAdminMenu() {
    printf("\n=== MENU ADMINISTRATOR ===\n");
    printf("1. Kelola Pengguna\n");
    printf("2. Lihat Laporan Penjualan\n");
    printf("3. Pengaturan Sistem\n");
    printf("4. Logout\n");
}

int main() {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char role[MAX_LENGTH];
    int choice;
    bool isLoggedIn = false;

    while (1) {
        if (!isLoggedIn) {
            printf("\n=== SISTEM KASIR ===\n");
            printf("Silakan login untuk melanjutkan\n");
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);

            if (checkLogin(username, password, role)) {
                printf("\nLogin berhasil sebagai %s!\n", role);
                isLoggedIn = true;
            } else {
                printf("\nLogin gagal! Username atau password salah.\n");
                continue;
            }
        }

        
        if (strcmp(role, "kasir") == 0) {
            showKasirMenu();
            printf("Pilih menu (1-3): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nMenu Input Transaksi\n");
                    printf("Fitur dalam pengembangan...\n");
                    break;
                case 2:
                    printf("\nMenu Riwayat Transaksi\n");
                    printf("Fitur dalam pengembangan...\n");
                    break;
                case 3:
                    printf("\nLogout berhasil!\n");
                    isLoggedIn = false;
                    break;
                default:
                    printf("\nPilihan tidak valid!\n");
            }
        } else if (strcmp(role, "administrator") == 0) {
            showAdminMenu();
            printf("Pilih menu (1-4): ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("\nMenu Kelola Pengguna\n");
                    printf("Fitur dalam pengembangan\n");
                    break;
                case 2:
                    printf("\nMenu Laporan Penjualan\n");
                    printf("Fitur dalam pengembangan\n");
                    break;
                case 3:
                    printf("\nMenu Pengaturan Sistem\n");
                    printf("Fitur dalam pengembangan\n");
                    break;
                case 4:
                    printf("\nLogout berhasil!\n");
                    isLoggedIn = false;
                    break;
                default:
                    printf("\nPilihan tidak valid!\n");
            }
        }
    }

    return 0;
}
