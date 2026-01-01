#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX 100


struct pasienKlinik {
    int ID;
    char nama[20];
    int umur;
    char penyakit[20];
};

void tampilkanDataPasien(struct pasienKlinik data[], int n);
void tambahDataPasien(struct pasienKlinik data[], int n);
void menu();

struct pasienKlinik pasien[MAX] = {
    {101, "Ahmad fauziah", 45, "Diabetes"},
    {102, "Siti Nurhaliza", 30, "Demam Berdarah"},
    {103, "Budi Susanto", 25, "Flu dan batuk"},
    {104, "Lestari Wulandari", 43, "Hipertensi"},
    {105, "Dedi Mulyadi", 23, "Asma"}
};

void tampilkanDataPasien(struct pasienKlinik data[], int n) {
    system("cls");
    int i;

    printf("ID\t| Nama\t\t\t| Umur\t| Penyakit \n");
    printf("------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        if (data[i].ID != 0) {
            if (strlen(data[i].nama) >= 13) {
                printf("%d\t| %s\t| %d\t| %s\n", data[i].ID, data[i].nama, data[i].umur, data[i].penyakit);
            } else if (strlen(data[i].nama) <= 5) {
                printf("%d\t| %s\t\t\t| %d\t| %s\n", data[i].ID, data[i].nama, data[i].umur, data[i].penyakit);
            } else {
                printf("%d\t| %s\t\t| %d\t| %s\n", data[i].ID, data[i].nama, data[i].umur, data[i].penyakit);
            };
        };
    };

    printf("\nTekan 'enter' untuk kembali ke menu...");
    fflush(stdin); getchar(); menu();
};

void tambahDataPasien(struct pasienKlinik data[], int n) {
    int i;
    char confirm;

    for (i = 0; i < MAX; i++) {
        if (pasien[i].ID != 0) {
            continue;
        } else {
            system("cls");
            pasien[i].ID = pasien[i - 1].ID + 1;
            printf("Pasien ID: %d\n", pasien[i].ID);
            printf("Masukkan Nama Pasien: "); fflush(stdin); fgets(pasien[i].nama, sizeof(pasien[i].nama), stdin);
            strtok(pasien[i].nama, "\n");
            printf("Masukkan Umur Pasien: "); scanf("%d", &pasien[i].umur);
            printf("Masukkan Penyakit Pasien: "); fflush(stdin); fgets(pasien[i].penyakit, sizeof(pasien[i].penyakit), stdin);
            strtok(pasien[i].penyakit, "\n");
            printf("\n");
        };

        while (1) {
            printf("Ingin Menambah Lagi? (y/n): "); scanf("%c", &confirm);
            if (confirm == 'y') {
                printf("Data %d Berhasil Disimpan!", pasien[i].ID);
                Sleep(800);
                break;
            } else if (confirm == 'n') {
                printf("Data %d Berhasil Disimpan!", pasien[i].ID);
                Sleep(800);
                menu();
            };
        };
    };
};

void cariPasien(struct pasienKlinik data[], int n) {
    system("cls");
    char metode[10], nama[20], confirm;
    int ID, i, j;
    int ditemukan = 0;

    while (1) {
        printf("Ketik 'menu' Untuk Kembali Ke Menu\nCari Menggunakan:\n1. ID Pasien\n2. Nama Pasien\n");
        printf("Silahkan Pilih Metode: ");
        scanf("%s", metode);
    
        system("cls");
    
        if (strcmp(metode, "ID") == 0 || strcmp(metode, "Id") == 0 || strcmp(metode, "id") == 0 || strcmp(metode, "1") == 0) {
            printf("Masukkan ID Pasien: ");
            scanf("%d", &ID);
    
            for (i = 0; i < n; i++) {
                if (data[i].ID == ID) {
                    ditemukan = 1;
                    printf("Data Ditemukan:\n");
                    printf("ID\t\t: %d\n", data[i].ID);
                    printf("Nama\t\t: %s\n", data[i].nama);
                    printf("Umur\t\t: %d\n", data[i].umur);
                    printf("Penyakit\t: %s\n", data[i].penyakit);
                    break;
                };
            };
        } else if (strcmp(metode, "nama") == 0 || strcmp(metode, "Nama") == 0 || strcmp(metode, "2") == 0) {
            printf("Masukkan Nama Depan Pasien: ");
            fflush(stdin);
            fgets(nama, sizeof(nama), stdin);
            strtok(nama, "\n");  // hapus newline
    
            for (i = 0; i < n; i++) {
                char hasil[20];
                j = 0;
    
                while (data[i].nama[j] != ' ' && data[i].nama[j] != '\0') {
                    hasil[j] = data[i].nama[j];
                    j++;
                }
                hasil[j] = '\0';
    
                if (strcmp(hasil, nama) == 0) {
                    ditemukan = 1;
                    printf("Data Ditemukan:\n");
                    printf("ID\t\t: %d\n", data[i].ID);
                    printf("Nama\t\t: %s\n", data[i].nama);
                    printf("Umur\t\t: %d\n", data[i].umur);
                    printf("Penyakit\t: %s\n", data[i].penyakit);
                    break;
                };
            };
        } else if (strcmp(metode, "menu") == 0) {
            menu();
            return;
        } else {
            printf("Metode tidak valid.\n");
        };
    
        if (!ditemukan) {
            printf("Data tidak ditemukan.\n");
        };
    
        printf("\nTekan 'enter' untuk kembali.");
        fflush(stdin); getchar(); cariPasien(pasien, MAX);
    };
};


void menu() {
    system("cls");
    int menu;
    printf("Menu: \n1. Tambah Pasien\n2. Tampilkan Pasien\n3. Cari Pasien\n\n");
    while (1) {
        printf("Silahkan Pilih Menu (1/2/3): "); scanf("%d", &menu);
        if (menu == 1 || menu == 2 || menu == 3) {
            break;
        };
    };

    if (menu == 1) {
        tambahDataPasien(pasien, MAX);
    } else if (menu == 2) {
        tampilkanDataPasien(pasien, MAX);
    } else if (menu == 3) {
        cariPasien(pasien, MAX);
    };
};

int main() {
    menu();

    return 0;                                    
};                                               