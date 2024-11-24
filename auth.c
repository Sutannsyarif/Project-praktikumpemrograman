#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "auth.h"

void login() {
    char username[50], password[50];
    printf("=== Login ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
        printf("Login berhasil. Selamat datang, %s!\n", username);
    } else {
        printf("Username atau password salah. Program keluar...\n");
        exit(1);
    }
}
