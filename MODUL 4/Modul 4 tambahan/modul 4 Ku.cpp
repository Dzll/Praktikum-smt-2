#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;

struct peminjaman
{
    int bk;
    int tglp;
    int tglk;
    int hari;
    int harga;
    double total;
} buku[100];
int sisa,ke,maks,a,vw;
void selection(int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        for(int j=i+1; j<n; j++)
        {
            if(buku[j].total>buku[min].total)
            {
                min=j;
            }
        }
        if(min!=i)
        {
            buku[n+1]=buku[i];
            buku[i]=buku[min];
            buku[min]=buku[n+1];
        }
    }
    cout<<" BERHASIL"<<endl;
};
void insert (int n)
{
    int batas;

    cout<< "   -- Daftar Harga Buku Pinjam -- \n";
    cout<< " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<< " | 1. Saintek           | Rp.3500/hari |\n";
    cout<< " | 2. Agama             | Rp.2000/hari |\n";
    cout<< " | 3. Cerita Anak-anak  | Rp.1500/hari |\n";
    cout<< " | 4. Novel             | Rp.2500/hari |\n";
    cout<< " | 5. Komik             | Rp.2500/hari |\n";
    cout<< " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<< "\n";
    cout<< " Pilih Buku Pinjam [1-5] : ";
    cin>>buku[n].bk;
    if(buku[n].bk==1)
    {
        buku[n].harga=3500;
    }
    else if(buku[n].bk==2)
    {
        buku[n].harga=2000;
    }
    else if(buku[n].bk==3)
    {
        buku[n].harga=1500;
    }
    else if(buku[n].bk==4)
    {
        buku[n].harga=2500;
    }
    else
    {
        buku[n].harga=2500;
    }

    cout<< " Tanggal Pinjam   [1-30] : ";
    cin>>buku[n].tglp;
    cout<< " Tanggal Kembali  [1-30] : ";
    cin>>buku[n].tglk;
    if(buku[n].tglk-buku[n].tglp>7)
    {
        buku[n].hari=buku[n].tglk-buku[n].tglp;
        buku[n].total=(buku[n].tglk-buku[n].tglp-7)*buku[n].harga;
    }
    else
    {
        buku[n].hari=buku[n].tglk-buku[n].tglp;
        buku[n].total=0;
    }

}
void view (int n,int batas)
{
    sisa=batas-n;
    for (int i=0; i<n; i++)
    {
        if(buku[i].bk==1)
        {
            cout<<" Buku Pinjam     : Saintek "<<endl;
        }
        else if(buku[i].bk==2)
        {
            cout<<" Buku Pinjam     : Agama"<<endl;
        }
        else if(buku[i].bk==3)
        {
            cout<<" Buku Pinjam     : Cerita Anak anak"<<endl;
        }
        else if(buku[i].bk==4)
        {
            cout<<" Buku Pinjam     : Novel"<<endl;
        }
        else if(buku[i].bk==5)
        {
            cout<<" Buku Pinjam     : Komik"<<endl;
        }
        else
        {
            cout<<" inputan Salah "<<endl;
        }
        cout<<" Tanggal Pinjam  : "<<buku[i].tglp<<endl;
        cout<<" Tanggal Kembali : "<<buku[i].tglk<<endl;
        cout<<"--------------------------------\n";
        cout<<" Anda memninjam Buku selama "<<buku[i].hari<<" hari"<<endl;
        cout<<" Denda Rp."<<buku[i].total<<endl;
        cout<<endl;
    }
    cout<<" Data yang masih kosong : "<<batas-n<<endl;
}

void view_individu(int n)
{
    cout<< " View data ke - ";
    cin>>vw;
    cout<<"--------------------------------\n";
    for (int i=0; i<n; i++)
    {
        if(i==vw-1)
        {

            if(buku[i].bk==1)
            {
                cout<<" Buku Pinjam     : Saintek "<<endl;
            }
            else if(buku[i].bk==2)
            {
                cout<<" Buku Pinjam     : Agama"<<endl;
            }
            else if(buku[i].bk==3)
            {
                cout<<" Buku Pinjam     : Cerita Anak anak"<<endl;
            }
            else if(buku[i].bk==4)
            {
                cout<<" Buku Pinjam     : Novel"<<endl;
            }
            else if(buku[i].bk==5)
            {
                cout<<" Buku Pinjam     : Komik"<<endl;
            }
            else
            {
                cout<<" inputan Salah "<<endl;
            }
            cout<<" Tanggal Pinjam  : "<<buku[i].tglp<<endl;
            cout<<" Tanggal Kembali : "<<buku[i].tglk<<endl;
            cout<<"--------------------------------\n";
            cout<<" Anda memninjam Buku selama "<<buku[i].hari<<" hari"<<endl;
            cout<<" Denda Rp."<<buku[i].total<<endl;
            cout<<endl;
        }
    }
}

int main ()
{

    int a, pilih,batas,n=0, hapus,mil,ke;
    char ulang,b;
    cout<<" Input batas Data : ";
    cin>>batas;
    system("cls");
    do
    {
        cout<<" >> Menu pilihan <<" <<endl;
        cout<<"--------------------------------\n";
        cout<<" 1. Insert Data"<<endl;
        cout<<" 2. View Data"<<endl;
        cout<<" 3. Hapus Data"<<endl;
        cout<<" 4. Sorting"<<endl;
        cout<<"--------------------------------\n";
        cout<<" Pilih : ";
        cin>>pilih;
        system("cls");
        if(pilih==1)
        {
            if(n==batas)
            {
                cout<<" Data sudah penuh !!";
                cout<<endl;
            }
            else
            {
                insert(n);
                n++;
            }
        }
        else if(pilih==2)
        {
            cout<<" 1. view individu  \n";
            cout<<" 2. view keseluruhan \n";
            cout<<"--------------------------------\n";
            cout<<" Pilih : ";
            cin>>mil;
            cout<<"--------------------------------\n";
            if(mil==1)
            {
                view_individu(n);
            }
            else
            {
                view (n,batas);
            }
        }
        else if(pilih==3)
        {
            cout<<" Hapus Data ke - ";
            cin>>hapus;
            for (int j=0; j<n; j++)
            {
                if(hapus-1==j)
                {
                    for(int c = j; c< n ; c++)
                    {
                        buku[c]=buku[c+1];
                    }
                    n--;
                }
            }
            cout<<" Data Berhasil Dihapus"<<endl;
        }
        else
        {
            selection(n);
        }
        cout<<"--------------------------------\n";
        cout<<" Ingin mengulang (y/n) ?? ";
        cin>>ulang;
        system("cls");
    }
    while(ulang=='y'||ulang=='Y');

}
