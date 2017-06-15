#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct peminjaman
{
    string buku;
    int tglp;
    int tglk;
}*p;


int PIL,R,PILIHAN,maks,pl,ke,jumlah;
//char HURUF;

void Inisialisasi();
bool isFull();
bool isEmpety();
void enqueue();
void dequeue();
void lihat_individu();
void lihat();

int main ()
{
    Inisialisasi();

    cout<< " Masukkan Batas Data : ";
    cin>>maks;
    p = new peminjaman[maks];

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


        cout<<" >> Menu Pilihan << "<<endl;
        cout<<"-----------------------------------\n";
        cout<<" 1. Insert Data"<<endl;
        cout<<" 2. Hapus Data"<<endl;
        cout<<" 3. View Data"<<endl;
        cout<<"-----------------------------------\n";
        cout<<" PILIHAN : ";
        cin>>PILIHAN;
        cout<<"-----------------------------------\n";
        switch (PILIHAN)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            cout<< " 1. View individu \n";
            cout<< " 2. View keseluruhan \n";
            cout<< " -----------------------------------\n";
            cout<< " Pilih : ";
            cin>>pl;
            if(pl==1)
            {
                lihat_individu();
            }
            else
            {
                lihat();
            }
            break;
        default:
            cout<< " Exit " <<endl;
            break;
        }
        cout<<"\n\npress any key to continue"<<endl;
        getch();
        system("cls");
    }
    while (PIL<4);
}

void Inisialisasi()
{
    R=-1;
}

bool isFull()
{
    if (R==maks-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpety()
{
    if (R==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue()
{
    if(isFull())
    {
        cout<<" Data sudah full";
    }
    else
    {
        R++;
        cout<<" Nama buku\t: ";
        cin.sync();
        getline(cin,p[R].buku);
        cout<<" Tgl pinjam\t: ";
        cin>>p[R].tglp;
        cout<<" Tgl kembali\t: ";
        cin>>p[R].tglk;
    }
}

void dequeue()
{
    if(isEmpety())
    {
        cout<<" Data masih kosong ";
    }
    else
    {
        for(int a = 0 ; a<R; a++)
        {
            p[a]=p[a+1];
        }
        R-=1;
    }
}

void lihat()
{
    if(isEmpety())
    {
        cout<<" Data masih kosong";
    }
    else
    {
        jumlah=maks;
        for(int a = 0 ; a<=R; a++)
        {
            cout<<" Nama Buku   : "<<p[a].buku<<endl;
            cout<<" Tgl Pinjam  : "<<p[a].tglp<<endl;
            cout<<" Tgl Kembali : "<<p[a].tglk<<endl;
            cout<<"-----------------------------------\n";
            if(p[a].tglk>p[a].tglp)
            {
                if(p[a].tglk-p[a].tglp>7)
                {
                    cout<< " Anda Meminjam buku selama "<<p[a].tglk-p[a].tglp<< " hari"<<endl;
                    if(p[a].buku=="saintek")
                    {
                        cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*3500<<",-"<<endl;
                    }
                    else if(p[a].buku=="agama")
                    {
                        cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2000<<",-"<<endl;
                    }
                    else if(p[a].buku=="cerita")
                    {
                        cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*1500<<",-"<<endl;
                    }
                    else if(p[a].buku=="novel")
                    {
                        cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2500<<",-"<<endl;
                    }
                    else if(p[a].buku=="komik")
                    {
                        cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2500<<",-"<<endl;
                    }
                    else
                    {
                        cout<< " Inputan buku salah !!"<<endl;
                    }
                }
                else
                {
                    cout<< " Anda Meminjam buku selama "<<p[a].tglk-p[a].tglp<< " hari"<<endl;
                    cout<< " Denda Rp.0,-"<<endl;
                }
            }
            else
            {
                if(30-p[a].tglp+p[a].tglk>7)
                {
                    cout<< " Anda Meminjam buku selama "<<30-p[a].tglp+p[a].tglk<< " hari"<<endl;
                    if(p[a].buku=="saintek")
                    {
                        cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*3500<<",-"<<endl;
                    }
                    else if(p[a].buku=="agama")
                    {
                        cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2000<<",-"<<endl;
                    }
                    else if(p[a].buku=="cerita")
                    {
                        cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*1500<<",-"<<endl;
                    }
                    else if(p[a].buku=="novel")
                    {
                        cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2500<<",-"<<endl;
                    }
                    else if(p[a].buku=="komik")
                    {
                        cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2500<<",-"<<endl;
                    }
                    else
                    {
                        cout<< " Inputan buku salah !!"<<endl;
                    }
                }
                else
                {
                    cout<< " Anda Meminjam buku selama "<<30-p[a].tglp+p[a].tglk<< " hari"<<endl;
                    cout<< " Denda Rp.0,-"<<endl;
                }
            }
            cout<<endl;
            jumlah--;
        }
    }

    cout<<" Data yang masih kosong : "<<jumlah;
}

void lihat_individu()
{
    if(isEmpety())
    {
        cout<<" Data masih kosong";
    }
    else
    {
        cout<< " View data ke - : ";
        cin>>ke;
        for(int a =0 ; a<=R; a++)
        {
            if(a==ke-1)
            {
                cout<<" Nama Buku   : "<<p[a].buku<<endl;
                cout<<" Tgl Pinjam  : "<<p[a].tglp<<endl;
                cout<<" Tgl Kembali : "<<p[a].tglk<<endl;
                cout<<"-----------------------------------\n";
                if(p[a].tglk>p[a].tglp)
                {
                    if(p[a].tglk-p[a].tglp>7)
                    {
                        cout<< " Anda Meminjam buku selama "<<p[a].tglk-p[a].tglp<< " hari"<<endl;
                        if(p[a].buku=="saintek")
                        {
                            cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*3500<<",-"<<endl;
                        }
                        else if(p[a].buku=="agama")
                        {
                            cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2000<<",-"<<endl;
                        }
                        else if(p[a].buku=="cerita")
                        {
                            cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*1500<<",-"<<endl;
                        }
                        else if(p[a].buku=="novel")
                        {
                            cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2500<<",-"<<endl;
                        }
                        else if(p[a].buku=="komik")
                        {
                            cout<< " Denda Rp."<<(p[a].tglk-p[a].tglp-7)*2500<<",-"<<endl;
                        }
                        else
                        {
                            cout<< " Inputan buku salah !!"<<endl;
                        }
                    }
                    else
                    {
                        cout<< " Anda Meminjam buku selama "<<p[a].tglk-p[a].tglp<< " hari"<<endl;
                        cout<< " Denda Rp.0,-"<<endl;
                    }
                }
                else
                {
                    if(30-p[a].tglp+p[a].tglk>7)
                    {
                        cout<< " Anda Meminjam buku selama "<<30-p[a].tglp+p[a].tglk<< " hari"<<endl;
                        if(p[a].buku=="saintek")
                        {
                            cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*3500<<",-"<<endl;
                        }
                        else if(p[a].buku=="agama")
                        {
                            cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2000<<",-"<<endl;
                        }
                        else if(p[a].buku=="cerita")
                        {
                            cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*1500<<",-"<<endl;
                        }
                        else if(p[a].buku=="novel")
                        {
                            cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2500<<",-"<<endl;
                        }
                        else if(p[a].buku=="komik")
                        {
                            cout<< " Denda Rp."<<(30-p[a].tglp+p[a].tglk-7)*2500<<",-"<<endl;
                        }
                        else
                        {
                            cout<< " Inputan buku salah !!"<<endl;
                        }
                    }
                    else
                    {
                        cout<< " Anda Meminjam buku selama "<<30-p[a].tglp+p[a].tglk<< " hari"<<endl;
                        cout<< " Denda Rp.0,-"<<endl;
                    }
                }
                cout<<endl;
            }
        }
    }
}
