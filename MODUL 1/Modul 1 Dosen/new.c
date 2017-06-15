#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{
    struct buku{
        char judul[10];
        char thn[4];
        char pengarang[10];
        char penerbit[10];
    };

    struct peminjaman{
        char nama[10];
        int tgl_p;
        int tgl_k;
        buku bk;
    }p[3];


    int pilih,denda,jum,jumbuku,a,b,c,j,hap;
    char ex;

    cout<< "  -- Daftar Harga Buku Pinjam -- \n";
    cout<< "=======================================\n";
    cout<< "| 1. Saintek           | Rp.3500/hari |\n";
    cout<< "| 2. Agama             | Rp.2000/hari |\n";
    cout<< "| 3. Cerita Anak-anak  | Rp.1500/hari |\n";
    cout<< "| 4. Novel             | Rp.2500/hari |\n";
    cout<< "| 5. Komik             | Rp.2500/hari |\n";
    cout<< "=======================================\n";
    do{
    cout<< " 1. Insert"<<endl;
    cout<< " 2. View"<<endl;
    cout<< " 3. Delete"<<endl;
    cout<< "=======================================\n";
    cout<< " pilih Menu : "; cin>>pilih;
    cout<< "=======================================\n";

    switch(pilih){
        case 1 :cout<< " Jumlah peminjam : ";
                cin>>jum;
                cout<< "=======================================\n";
                for(a=1; a<=jum; a++){
                   // system("cls");
                    cout<< " >> Peminjam "<<a<<endl;
                    cout<<endl;
                    cin.sync();
                    cout<< " Nama : "; gets(p[a].nama);
                    cout<< " Jumlah buku pinjam : "; cin>>jumbuku;
                    for(int a=1; a<=jumbuku; a++){
                        cout<<endl;
                        cin.sync();
                        cout<< " Judul Buku "<<a<<" : "; gets(p[a].bk.judul);
                        cout<< " Tahun : "; gets(p[a].bk.thn);
                        cout<< " pengarang : "; gets(p[a].bk.pengarang);
                        cout<< " penerbit : "; gets(p[a].bk.penerbit);
                    }
                    cout<< "=======================================\n";
                    cout<< " Tanggal Pinjam  [1-30] : "; cin>>p[a].tgl_p;
                    cout<< " Tanggal Kembali [1-30] : "; cin>>p[a].tgl_k;
                    cout<< "=======================================\n";
                }
                cout<< " Ingin Mengulang ?? (y/n) : ";
                cin>>ex;
                cout<<endl;
                break;
        case 2 :cout<< " -- View Data -- "<<endl;
                cout<< "=======================================\n";
                for(a=1; a<=jum; a++){
                    cout<< " Peminjam "<<a<<endl;
                    cout<< " Nama : "<<p[a].nama<<endl;
                    for(int b=1; b<=jumbuku; b++){
                        cout<< " Buku "<<b<<" yang di pinjam "<<endl;
                        cout<< " Tahun : "<<p[b].bk.thn<<endl;
                        cout<< " Judul : "<<p[b].bk.judul<<endl;
                        cout<< " pengarang : "<<p[b].bk.pengarang<<endl;
                        cout<< " penerbit : "<<p[b].bk.penerbit<<endl;
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

        case 3 :cout<<" Data yang ingin di hapus : ";
                cin>>hap;
                for(a=1; a<=jum; a++){
                    if(hap==a){
                        for (int j = a ; j<= jum+1 ;j++){
                            p[j]=p[j+1];
                        }
                        jum--;
                    }
                }

                cout<< " Ingin Mengulang ?? (y/n) : ";
                cin>>ex;
                cout<<endl;
                break;
        }
    }while(ex=='y' || ex=='Y');
}





        /*case 2 :cout<< " -- View Data -- "<<endl;
                cout<< "=======================================\n";
                for (a=1; a<=jum; a++){
                    if(a!=c){
                        if(book[a].buku==1){
                            cout<< " Buku yang di pinjam : Saintek"<<endl;
                        }
                        else if(book[a].buku==2){
                            cout<< " Buku yang di pinjam : Agama"<<endl;
                        }
                        else if(book[a].buku==3){
                            cout<< " Buku yang di pinjam : Cerita Anak- Anak "<<endl;
                        }
                        else if(book[a].buku==4){
                            cout<< " Buku yang di pinjam : Novel"<<endl;
                        }
                        else{
                            cout<< " Buku yang di pinjam : Komik"<<endl;
                        }
                    cout<< " Tanggal pinjam      : "<<book[a].tgl_p<<endl;
                    cout<< " Tanggal Kembali     : "<<book[a].tgl_k<<endl;
                    cout<< "=======================================\n";
                    if(book[a].tgl_p>book[a].tgl_k){
                        if(30-book[a].tgl_p+book[a].tgl_k>7){
                            cout<< " Anda tidak boleh meminjam buku selama "<<30-book[a].tgl_p+book[a].tgl_k<< " hari"<<endl;
                            if(book[a].buku==1){
                            cout<< " Denda : Rp. "<<(30-book[a].tgl_p+book[a].tgl_k)*3500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==2){
                            cout<< " Denda : Rp. "<<(30-book[a].tgl_p+book[a].tgl_k)*2000<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==3){
                            cout<< " Denda : Rp. "<<(30-book[a].tgl_p+book[a].tgl_k)*1500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==4){
                            cout<< " Denda : Rp. "<<(30-book[a].tgl_p+book[a].tgl_k)*2500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==5){
                            cout<< " Denda : Rp. "<<(30-book[a].tgl_p+book[a].tgl_k)*2500<<endl;
                            cout<<endl;
                            }
                            else{
                            cout<<"Yang anda pilih tidak tersedia"<<endl;
                            }

                        }
                        else{
                            cout<< " Denda : Rp. 0"<<endl;
                            cout<<endl;
                        }
                    }
                    else{
                        if(book[a].tgl_k-book[a].tgl_p>7){
                        cout<< " Anda tidak boleh meminjam buku selama "<<book[a].tgl_k-book[a].tgl_p<< " hari"<<endl;
                        if(book[a].buku==1){
                            cout<< " Denda : Rp. "<<(book[a].tgl_k-book[a].tgl_p)*3500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==2){
                            cout<< " Denda : Rp. "<<(book[a].tgl_k-book[a].tgl_p)*2000<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==3){
                            cout<< " Denda : Rp. "<<(book[a].tgl_k-book[a].tgl_p)*1500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==4){
                            cout<< " Denda : Rp. "<<(book[a].tgl_k-book[a].tgl_p)*2500<<endl;
                            cout<<endl;
                            }
                            else if(book[a].buku==5){
                            cout<< " Denda : Rp. "<<(book[a].tgl_k-book[a].tgl_p)*2500<<endl;
                            cout<<endl;
                            }
                            else{
                            cout<<" Buku Yang anda pilih tidak tersedia"<<endl;
                            }
                        }
                        else{
                            cout<< " Denda : Rp. 0"<<endl;
                            cout<<endl;
                        }
                    }
                    }
                }
                break;*/
