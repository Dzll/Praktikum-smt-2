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
string namaa="";



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

void cari()
{
    if (awal==NULL)
        cout<< " Data Kosong!!!";
    else
    {
        cin.ignore();
        cout<<" Masukkan nama buku : ";
        getline(cin,namaa);
        bantu=awal;
        if(namaa<bantu->buku)
        {
             cout<< " Data Tidak ditemukan !!!";
             system("PAUSE");
             return;
        }else{
            while(bantu->buku!=namaa)
            {
                bantu=bantu->next;
            }
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
        }
    }
    getch();

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


int main()
{
    int pilih;

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
        cout<< " 6. Cari data \n";
        cout<< " 7. Lihat semua data \n";
        cout<< " ------------------------\n";
        cout<< " Pilih menu : ";
        cin>>pilih;
        cout<<endl;
        switch(pilih)
        {
        case 1 :
            buat_baru();
            Input_awal();
            break;
        case 2:
            buat_baru();
            input_belakang();
            break;
        case 3 :
            if(awal==NULL)
            {
                cout<< " Data kosong ";
                system("PAUSE");
            }
            else if(sisip<NULL)
            {
                cout<< " Data kurang ";
                system("PAUSE");
            }
            else
            {
                buat_baru();
                sisip_tengah();
            }
            break;
        case 4:
            hapus_depan();
            break;
        case 5 :
            if(awal==NULL)
            {
                cout<< " Data kosong ";
                system("PAUSE");
            }
            else if(hap<NULL)
            {
                cout<< " Data kurang ";
                system("PAUSE");
            }
            else
            {
                hapus_tengah();
            }
            break;
        case 6:
            cari();
            break;
        case 7 :
            lihat_data();
            break;
        }
    }
    while (pilih!=8);
}
