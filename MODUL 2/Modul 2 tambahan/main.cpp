#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int pil,hap,sisip;
void pilih();
void buat_baru();
void Input_awal();
void input_belakang();
void sisip_tengah();
void hapus_depan();
void hapus_tengah();
void cari();
void lihat_data();
struct peminjaman
{
    string buku = "";
    int tglp;
    int tglk;
    peminjaman *prev, *next;
};
peminjaman *baru, *awal=NULL, *akhir=NULL,*hapus,*bantu,*bantu2;
int main()
{
    do
    {
        system("cls");
        cout<< "   -- Daftar Harga Buku Pinjam -- \n";
        cout<< " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<< " | Saintek           | Rp.3500/hari |\n";
        cout<< " | Agama             | Rp.2000/hari |\n";
        cout<< " | Cerita Anak-anak  | Rp.1500/hari |\n";
        cout<< " | Novel             | Rp.2500/hari |\n";
        cout<< " | Komik             | Rp.2500/hari |\n";
        cout<< " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<< "\n"<<endl;


        cout<< " >> Menu Pilihan << "<<endl;
        cout<< " ------------------------\n";
        cout<< " 1. Input Awal \n";
        cout<< " 2. Input Belakang \n";
        cout<< " 3. Sisip tengah \n";
        cout<< " 4. Hapus depan \n";
        cout<< " 5. Hapus tengah \n";
        cout<< " 6. Lihat semua data \n";
        cout<< " ------------------------\n";
        cout<< " Pilih menu : ";
        cin>>pil;
        cout<<endl;
        pilih();
    }
    while(pil!=8);
}
void pilih()
{
    if(pil==1)
        Input_awal();
    else if(pil==2)
        input_belakang();
    else if(pil==3)
        if (awal== NULL)
        {
            cout<< " Data Kosong... \n";
            system("PAUSE");
        }
        else if(sisip<2)
        {
            cout<< " Data kurang dari 3... \n";
            system("PAUSE");
        }
        else
        {
            sisip_tengah();
        }
    else if(pil==4)
        hapus_depan();
    else if(pil==5)
        if (awal== NULL)
        {
            cout<< " Data Kosong... \n";
            system("PAUSE");
        }
        else if(sisip<2)
        {
            cout<< " Data kurang dari 3... \n";
            system("PAUSE");
        }
        else
        {
            hapus_tengah();
        }
    else if(pil==6)
        if(awal==NULL){
            cout<< " Data kosong...";
        }else{
        cari();
        }
    else if(pil==7)
        lihat_data();
    else
        cout<<"selesai";
}
void buat_baru()
{
    baru = new(peminjaman);
    cout<< " Input Buku Pinjam     : ";
    cin>>baru->buku;
    cout<< " Input Tanggal Pinjam  : ";
    cin>>baru->tglp;
    cout<< " Input Tanggal Kembali : ";
    cin>>baru->tglk;
    baru->prev=NULL;
    baru->next=NULL;
}

void Input_awal()
{
    buat_baru();
    if(awal==NULL)
    {
        awal=baru;
        akhir=baru;
    }
    else
    {
        baru->next=awal;
        awal->prev=baru;
        awal=baru;
    }
    cout<<endl<<endl;
    lihat_data();
}

void input_belakang()
{
    buat_baru();
    if(awal==NULL)
    {
        awal=baru;
        akhir=baru;
    }
    else
    {
        akhir->next=baru;
        baru->prev=akhir;
        akhir=baru;
    }
    cout<<endl<<endl;
    lihat_data();
}

void sisip_tengah()
{
    int sisip;
    cout<< " Masukkan Posisi Sisip : ";
    cin>>sisip;
    bantu=awal;

    for(int i=1; i<sisip-1; i++)
    {
        bantu=bantu->next;
    }

    buat_baru();

    bantu2=bantu->next;
    bantu->next=baru;
    baru->prev=bantu;
    baru->next=bantu2;
    bantu2->prev=baru;
}

void hapus_depan()
{
    if (awal==NULL)
        cout<< " Data Kosong!!!";
    else if (awal->next==NULL)
    {
        hapus=awal;
        awal=NULL;
        akhir=NULL;
        delete hapus;
    }
    else
    {
        hapus=awal;
        awal=hapus->next;
        awal->prev=NULL;
        delete hapus;
    }
    cout<<endl<<endl;
    lihat_data();
}

void hapus_tengah()
{
    int hap;
    cout<<" Masukkan Posisi hapus : ";
    cin>>hap;
    bantu=awal;

    for(int i=1; i<hap-1; i++)
    {
        bantu=bantu->next;
    }
    hapus=bantu->next;
    bantu2=hapus->next;
    bantu->next=hapus->next;
    bantu2->prev=bantu;
    delete hapus;

}




void lihat_data()
{
    if (awal==NULL)
        cout<< " Data Kosong!!!";
    else
    {
        bantu=awal;
        while(bantu!=NULL)
        {
            cout<<" Buku Pinjam     : "<<bantu->buku<<endl;
            cout<<" Tanggal Pinjam  : "<<bantu->tglp<<endl;
            cout<<" Tanggal Kembali : "<<bantu->tglk<<endl;
            cout<< " ------------------------\n";
            if(bantu->tglk>bantu->tglp)
            {
                if(bantu->tglk-bantu->tglp>7)
                {
                    cout<< " Anda meminjam buku selama "<<bantu->tglk-bantu->tglp<< " hari"<<endl;
                    if(bantu->buku=="saintek")
                    {
                        cout<< " Denda Rp."<<(bantu->tglk-bantu->tglp-7)*3500<<",-"<<endl;
                    }
                    else if(bantu->buku=="agama")
                    {
                        cout<< " Denda Rp."<<(bantu->tglk-bantu->tglp-7)*2000<<",-"<<endl;
                    }
                    else if(bantu->buku=="cerita")
                    {
                        cout<< " Denda Rp."<<(bantu->tglk-bantu->tglp-7)*1500<<",-"<<endl;
                    }
                    else if(bantu->buku=="novel")
                    {
                        cout<< " Denda Rp."<<(bantu->tglk-bantu->tglp-7)*2500<<",-"<<endl;
                    }
                    else if(bantu->buku=="komik")
                    {
                        cout<< " Denda Rp."<<(bantu->tglk-bantu->tglp-7)*2500<<",-"<<endl;
                    }
                    else
                    {
                        cout<< " Inputan Buku Salah \n";
                    }
                    cout<<endl;
                }
                else
                {
                    cout<< " Anda meminjam buku selama "<<bantu->tglk-bantu->tglp<< " hari"<<endl;
                    cout<< " Denda Rp.0,- \n"<<endl;
                    cout<<endl;
                }
            }
            else
            {
                if(30-bantu->tglp+bantu->tglk>7)
                {
                    cout<< " Anda meminjam buku selama "<<30-bantu->tglp+bantu->tglk<< " hari"<<endl;
                    if(bantu->buku=="saintek")
                    {
                        cout<< " Denda Rp."<<((30-bantu->tglp+bantu->tglk)-7)*3500<<",-"<<endl;
                    }
                    else if(bantu->buku=="agama")
                    {
                        cout<< " Denda Rp."<<((30-bantu->tglp+bantu->tglk)-7)*2000<<",-"<<endl;
                    }
                    else if(bantu->buku=="cerita")
                    {
                        cout<< " Denda Rp."<<((30-bantu->tglp+bantu->tglk)-7)*1500<<",-"<<endl;
                    }
                    else if(bantu->buku=="novel")
                    {
                        cout<< " Denda Rp."<<((30-bantu->tglp+bantu->tglk)-7)*2500<<",-"<<endl;
                    }
                    else if(bantu->buku=="komik")
                    {
                        cout<< " Denda Rp."<<((30-bantu->tglp+bantu->tglk)-7)*2500<<",-"<<endl;
                    }
                    else
                    {
                        cout<< " Inputan Buku Salah \n";
                    }
                    cout<<endl;
                }
                else
                {
                    cout<< " Anda meminjam buku selama "<<30-bantu->tglp+bantu->tglk<< " hari"<<endl;
                    cout<< " Denda Rp.0,- \n";
                    cout<<endl;
                }
            }


            bantu=bantu->next;
        }
    }
    getch();
}
