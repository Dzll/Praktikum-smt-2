#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
    struct buku
    {
        char judul[10];
        char thn[10];
        char pengarang[10];
        char penerbit[10];
    };

    struct peminjaman
    {
        char nama[10];
        int tgl_p;
        int tgl_k;
        buku bk[10];
    } p[10];


    int pilih,denda,jum,jumbuku,a,b,c,j,hap;
    char ex;

    /*cout<< "  -- Daftar Harga Buku Pinjam -- \n";
    cout<< "=======================================\n";
    cout<< "| 1. Saintek           | Rp.3500/hari |\n";
    cout<< "| 2. Agama             | Rp.2000/hari |\n";
    cout<< "| 3. Cerita Anak-anak  | Rp.1500/hari |\n";
    cout<< "| 4. Novel             | Rp.2500/hari |\n";
    cout<< "| 5. Komik             | Rp.2500/hari |\n";
    cout<< "=======================================\n";*/
    do
    {
        cout<< "\n"<<endl;
        cout<< " 1. Insert"<<endl;
        cout<< " 2. View"<<endl;
        cout<< " 3. Delete"<<endl;
        cout<< "=======================================\n";
        cout<< " pilih Menu : ";
        cin>>pilih;
        cout<< "=======================================\n";

        switch(pilih)
        {
        case 1 :
            cout<< " Jumlah peminjam : ";
            cin>>jum;
            cout<< "=======================================\n";
            for(a=1; a<=jum; a++)
            {
                cin.sync();
                cout<< " Nama : ";
                gets(p[a].nama);
                cout<< " Jumlah buku pinjam : ";
                cin>>jumbuku;
                for(int b=1; b<=jumbuku; b++)
                {
                    cout<<endl;
                    cin.sync();
                    cout<< " Judul Buku "<<b<<" : ";
                    gets(p[a].bk[b].judul);
                    cout<< " Tahun : ";
                    gets(p[a].bk[b].thn);
                    cout<< " pengarang : ";
                    gets(p[a].bk[b].pengarang);
                    cout<< " penerbit : ";
                    gets(p[a].bk[b].penerbit);
                }
                cout<< "=======================================\n";
                cout<< " Tanggal Pinjam  [1-30] : ";
                cin>>p[a].tgl_p;
                cout<< " Tanggal Kembali [1-30] : ";
                cin>>p[a].tgl_k;
                cout<< "=======================================\n";
            }
            cout<< " Ingin Mengulang ?? (y/n) : ";
            cin>>ex;
            cout<<endl;
            break;
        case 2 :
            cout<< " -- View Data -- "<<endl;
            cout<< "=======================================\n";
            for(a=1; a<=jum; a++)
            {
                cout<< " Nama : "<<p[a].nama<<endl;
                for(int b=1; b<=jumbuku; b++)
                {
                    cout<< " Buku "<<b<<" yang di pinjam "<<endl;
                    cout<< " Judul : "<<p[a].bk[b].judul<<endl;
                    cout<< " Tahun : "<<p[a].bk[b].thn<<endl;
                    cout<< " pengarang : "<<p[a].bk[b].pengarang<<endl;
                    cout<< " penerbit : "<<p[a].bk[b].penerbit<<endl;
                    cout<<endl;
                }
                cout<< "=======================================\n";
                cout<< " Tanggal Pinjam   : "<<p[a].tgl_p<<endl;
                cout<< " Tanggal Kembali  : "<<p[a].tgl_k<<endl;
                cout<< "=======================================\n";
            }
            cout<< " Ingin Mengulang ?? (y/n) : ";
            cin>>ex;
            cout<<endl;
            break;

        case 3 :
            cout<<" Data yang ingin di hapus : ";
            cin>>hap;

            if(hap>jum)
            {
                cout<< " Tidak Bisa Menghapus ";
            }
            else
            {
                for (int i = 1 ; i<=jum ; i++)
                {
                    if (hap == i)
                    {
                        for(int a = i ; a<=jum; a++)
                        {
                            p[a] = p[a+1];
                        }
                    }
                }

            }
            jum--;

            cout<< " Ingin Mengulang ?? (y/n) : ";
            cin>>ex;
            cout<<endl;
            break;
        }
    }
    while(ex=='y' || ex=='Y');
}
