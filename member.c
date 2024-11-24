#include <stdio.h>
#include <string.h>
#include "member.h"

#define MAKS_MEMBER 50

typedef struct {
    int id;
    char nama[50];
    int poin;
} Member;

Member member[MAKS_MEMBER];
int jumlahMember = 0;

void tambahMember() {
    if (jumlahMember >= MAKS_MEMBER) {
        printf("Daftar member penuh!\n");
        return;
    }
    member[jumlahMember].id = jumlahMember + 1;
    printf("Masukkan nama member: ");
    scanf("%s", member[jumlahMember].nama);
    member[jumlahMember].poin = 0;
    jumlahMember++;
    printf("Member berhasil ditambahkan.\n");
}
