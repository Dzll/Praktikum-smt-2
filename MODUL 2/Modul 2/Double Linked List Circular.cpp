#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <limits>
#include <iostream>

using namespace std;

struct mahasiswa {
    int NPM;
    char nama [50];
    double nilai;
    mahasiswa *next;
    mahasiswa *prev;
};

int main(){
    mahasiswa *baru, *head=NULL, *bantu, *bantu2, *bantuHapus, *ekor, *hapus;
    int menu, pilih, cari, del, posisi, d, posisi_awal, posisi_ke;
    int jumlah=0;
    char konfirm;

    MENU:
    system("cls");
    printf("============== DATA  MAHASISWA ==============\n");
    printf("1. Tambah Data\n");
    printf("2. Pencarian Data\n");
    printf("3. Tampilkan Data\n");
    printf("4. Hapus Data\n");
    printf("5. Keluar\n");
    printf("Pilih  : ");

    Input:
    while(!(cin >> menu)) //Pengecekan inputan jika tidak berupa integer maka mengulang input
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Pilih : ";
    }

    switch(menu)
    {
        case 1:
        {
            system("CLS");
            baru = new mahasiswa;
            printf("============== PENAMBAHAN DATA ==============\n");
            printf("NPM\t : "); cin >> baru->NPM; getchar();
            printf("Nama\t : "); cin.getline(baru->nama,50);
            printf("Nilai\t : "); cin >> baru->nilai;
            jumlah++;
            baru->next = NULL;
            if (head == NULL){
                head=baru;
                ekor=baru;
                head->next = baru;
                head->prev = baru;
                printf("=============================================\n");
                printf("\nPenambahan Berhasil!");
                goto Lanjut;
            }
            else{
                printf("=============================================\n");
                printf("\nTambah pada posisi : ");
                printf("\n1. Depan \n2. Tengah\n3. Belakang\nPilih : ");
                POS:
                while(!(cin >> posisi))
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Pilih : ";
                }
                switch(posisi){
                case 1 :
                    {
                        //Penambahan Depan
                        tambahDepan:
                        baru->next = head;                //node baru berada di depan data yg telah ada
                        baru->prev = ekor;
                        ekor->next = baru;
                        head->prev = baru;
                        head = baru;
                        printf("\n=============================================\n\n");
                        printf("Penambahan Berhasil!");
                        goto Lanjut;
                    }
                case 2:
                    {
                        //Penambahan Tengah
                        bantu = head;
                        posisi_awal = 1;
                        printf("Masukkan Data Ke ( 1 - %d) : ",jumlah);
                        Limit:
                        while(!(cin >> posisi_ke))
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid ixnput. Pilih : ";
                        }
                        if (posisi_ke > jumlah){
                            cout << "Limit!!";
                            goto Limit;
                        }
                        else if (posisi_ke==1){
                            goto tambahDepan;
                        }
                        else if (posisi_ke == jumlah){
                            goto tambahBelakang;
                        }
                        else
                        for (int i = 1; i <= jumlah; i++){
                            bantu2 = bantu;
                            bantu=bantu->next;
                            if (i == posisi_ke-1){
                                baru->next = bantu;
                                bantu->prev = baru;
                                bantu2->next = baru;
                                baru->prev = bantu2;
                            }
                        }
                        printf("\n=============================================\n\n");
                        printf("Penambahan Berhasil!");
                        goto Lanjut;
                    }
                case 3:
                    {
                        //Penambahan Belakang
                        tambahBelakang:
                        ekor->next = baru;
                        baru->prev = ekor;
                        baru->next = head;
                        head->prev = baru;
                        ekor = baru;
                        printf("\n=============================================\n\n");
                        printf("Penambahan Berhasil!");
                        goto Lanjut;
                    }
                default :
                    {
                        printf("Invalid! Pilih :");
                        goto POS;
                    }
                }
            }
        }
    case 2:
        {
            printf("\n=============================================");
            printf("\nMasukkan NPM : ");
            while(!(cin >> cari))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Pilih : ";
            }
            printf("=============================================\n");
            bantu = head;
            if (bantu!=NULL)
            {
                for (int i=0;i<jumlah;i++)
                {
                    if(cari == bantu->NPM)                  //pengecekan NPM yang dicari
                    {
                        printf("=============================================\n");
                        printf("\nNama\t : %s",bantu->nama);
                        printf("\nNilai\t : %.2f",bantu->nilai);
                        goto Lanjut;
                    }
                    bantu = bantu->next;
                }
                printf("=============================================\n");
                printf("\nData tidak ditemukan!");
                goto Lanjut;
            }
            else
            {
                printf("=============================================\n");
                printf("\nData tidak ditemukan!");
                goto Lanjut;
            }
        }
    case 3:
        {
            system("cls");
            bantu = head;
            printf("Data : ");
            if (head==NULL){
                printf("\n=============================================\n");
                printf("\nData Kosong!");
                goto Lanjut;
            }
            do{
                printf("\n=============================================");
                printf("\n\nNPM\t : %d",bantu->NPM);
                printf("\nNama\t : %s", bantu->nama);
                printf("\nNilai\t : %.2f \n",bantu->nilai);
                printf("=============================================");
                bantu = bantu->next;
            }while(bantu!=head);
            goto Lanjut;
        }
    case 4:
        {
            system("cls");
            printf("Pilihan Hapus :");
            printf("\n1. Depan\n2. Tengah\n3. Belakang\nPilih : ");
            HPS:
            while(!(cin >> del))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Pilih : ";
            }
            switch(del)
            {
            case 1:
                {
                    hapusDepan:
                    bantu = head;
                    if (head != NULL)
                    {
                        if (bantu->next != head){
                            hapus = head;
                            d = hapus->NPM;
                            head = head->next;
                            head->prev = ekor;
                            ekor->next = head;
                            delete hapus;
                        }
                        else {
                            d = head->NPM;
                            head = NULL;
                            ekor = NULL;
                        }
                        jumlah--;
                        printf("=============================================\n\n");
                        printf("NPM %d terhapus\n",d);
                    }
                    else
                    {
                        printf("=============================================\n\n");
                        cout<<"Data Masih Kosong\n";
                    }
                    goto Lanjut;
                }
            case 2:
                {
                    printf("\n=============================================");
                    printf("\nMasukkan NPM : ");
                    while(!(cin >> cari))
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Pilih : ";
                    }
                    printf("=============================================\n");
                    bantu = head;
                    if (head!=NULL)
                    {
                        do{
                            if(cari == bantu->NPM)                  //pengecekan NPM yang dicari
                            {
                                printf("=============================================\n");
                                printf("\nNama\t : %s",bantu->nama);
                                printf("\nNilai\t : %.2f",bantu->nilai);
                                printf("\nHapus Data (y/n) :"); cin >> konfirm;
                                if (konfirm == 'y'|| konfirm == 'Y')
                                {
                                    if(bantu == head)
                                    {
                                        goto hapusDepan;
                                    }
                                    if(bantu == ekor)
                                    {
                                        goto hapusEkor;
                                    }
                                    else
                                    {
                                        hapus = bantu;
                                        bantu2->next=bantu->next;
                                        bantuHapus = bantu->next;
                                        bantuHapus->prev = bantu2;
                                        delete hapus;
                                    }
                                    jumlah--;
                                    printf("=============================================\n\n");
                                    printf("Data Berhasil Dihapus!");
                                }
                                else
                                {
                                    printf("=============================================\n\n");
                                    printf("Data Tidak Dihapus!");
                                }
                                goto Lanjut;
                            }
                            bantu2 = bantu;
                            bantu = bantu->next;
                        }while (bantu!=head);
                        printf("=============================================\n");
                        printf("\nData tidak ditemukan!");
                        goto Lanjut;
                    }
                    else
                    {
                        printf("=============================================\n");
                        printf("\nData Kosong!");
                        goto Lanjut;
                    }
                }
            case 3:
                {
                    hapusEkor:
                    if (head != NULL){
                        if(ekor->next!=ekor){
                            hapus = ekor;
                            d = hapus->NPM;
                            ekor=ekor->prev;
                            ekor->next = head;
                            head->prev = ekor;
                            delete hapus;
                        }
                        else{
                            d = ekor->NPM;
                            ekor = NULL;
                            head = NULL;
                        }
                        jumlah--;
                        printf("\n=============================================\n\n");
                        printf("NPM %d terhapus",d);
                    }
                    else{
                        printf("Masih kosong\n");
                    }
                    goto Lanjut;
                }
            default :
                {
                    printf("Invalid input. Pilih : ");
                    goto HPS;
                }
            }
        }
    case 5:
        {
            goto keluar;
        }
    default :
        printf("Invalid input. Pilih : ");
    }

    Lanjut:
    printf("\n\n=============================================\n");
    printf("1.Kembali ke Menu Utama\n");
    printf("2.Keluar dari program\n");
    printf("=============================================\n");
    printf("Masukan Pilihan Anda   : ");

    input:
    while(!(cin >> pilih))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Pilih : ";
    }

    switch(pilih)
    {
    case 1:
        {
            goto MENU;
        }
    case 2:
        {
            keluar:
            system("cls");
            printf("TERIMA KASIH");
            getch();
            break;
        }
    default :
        {
            cout << "Invalid input. Pilih : ";
            goto input;
        }
    }
}
