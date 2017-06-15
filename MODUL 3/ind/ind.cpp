#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int maks;
//int f = -1;
int r = -1;
struct Tanggal
{
    int tgl;
    int bulan;
    int tahun;
};
struct Minum
{
    string nama;
    int harga=NULL;
};
struct Makan
{
    string nama;
    int harga=NULL;
};
struct Ruangan
{
    int ukuran;
    int harga;
    int sewa;
    int jamA;
    int jamM;
    int total;
};
struct Queue
{
    string nama;
    Ruangan ruangan;
    Makan *makan=NULL;
    Minum *minum=NULL;

    int pajak;
    int total;
    Tanggal tgl;
}*queue;

void swiftArray(Queue *arrays)
{
    for(int a = 0 ; a<=r; a++)
    {
        arrays[a]=arrays[a+1];
    }
}
bool isEmpty()
{
    if(r==-1) return true;
    else return false;
}
bool isFull()
{
    if(r==maks-1) return true;
    else return false;
}
Makan *pesanMakanan()
{
    char iya;
    int pil;
    int banyak=0;
    Makan *pesanan;
    pesanan = new Makan [64];
    do
    {
        system("cls");
        cout<<"1. Ayam Gerpak /10.000"<<endl;
        cout<<"2. Bebek Goron /13.000 "<<endl;
        cout<<"3. Jamur Crispy /8.000 "<<endl;
        cout<<"4. Penyetan Bu Ana /10.000 "<<endl;
        cin>>pil;
        if (pil==1)
        {
            pesanan[banyak].nama = "Ayam Gerpak";
            pesanan[banyak].harga = 10000;
            banyak++;
        }
        else if (pil==2)
        {
            pesanan[banyak].nama = "Bebek Goreng";
            pesanan[banyak].harga = 13000;
            banyak++;
        }
        else if (pil==3)
        {
            pesanan[banyak].nama = "Jamur Crispy";
            pesanan[banyak].harga = 12000;
            banyak++;
        }
        else if (pil==4)
        {
            pesanan[banyak].nama = "Penyetan Bu ana";
            pesanan[banyak].harga = 10000;
            banyak++;
        }
        cout<<"Masih Ingin Memesan (y/Y): ";
        cin>>iya;
    }
    while(iya=='y' ||iya=='Y');
    return pesanan;
}
int hitungHarga(int n, int n1)
{
    return n*n1;
}
Minum *pesanMinuman ()
{
    Minum *pesan ;
    pesan = new Minum [64];
    int banyak =0;
    char iya;
    int pil;
    do
    {
        system("cls");
        cout<<"1. Es Jeruk /5.000"<<endl;
        cout<<"2. Es Degan /4.000"<<endl;
        cout<<"3. Es Legen /3.000 "<<endl;
        cout<<"4. Es Campur /6.000 "<<endl;
        cin>>pil;
        if(pil==1)
        {
            pesan[banyak].nama = "Es Jeruk";
            pesan[banyak].harga = 5000;
            banyak++;
        }
        if(pil==2)
        {
            pesan[banyak].nama = "Es Degan";
            pesan[banyak].harga = 4000;
            banyak++;
        }
        if(pil==3)
        {
            pesan[banyak].nama = "Es Legan";
            pesan[banyak].harga = 3000;
            banyak++;
        }
        if(pil==4)
        {
            pesan[banyak].nama = "Es Campur";
            pesan[banyak].harga = 6000;
            banyak++;
        }
        cout<<"Masih Ingin Memesan (y/Y): ";
        cin>>iya;
    }
    while(iya=='y'||iya=='Y');
    return pesan;
}
int hitungPajak (int total)
{
    return total*0.1;
}

void enqueue(string namaP, int jamM,int jamA,int lamaSewa, int ruang, int hargaRuang, int hargaRuangan,Makan *pesanMakan,Minum *pesanMinum,int pajak, int total)
{
    r++;
    queue[r].nama = namaP;
    queue[r].ruangan.jamM = jamM;
    queue[r].ruangan.jamA = jamA;
    queue[r].ruangan.sewa = lamaSewa;
    queue[r].ruangan.ukuran = ruang;
    queue[r].ruangan.harga = hargaRuang;
    queue[r].ruangan.total = hargaRuangan;
    queue[r].makan = pesanMakan;
    queue[r].minum = pesanMinum;
    queue[r].pajak = pajak;
    queue[r].total = total;
}
void dequeue()
{
    swiftArray(queue);
    r-=1;
}
string cetakUkuranRuang(int ruang)
{
    if (ruang==1) return "Small";
    else if(ruang==2) return "Medium";
    else if (ruang==3) return "Large";
}

void view ()
{
    system("cls");
    for(int a = 0 ; a<=r; a++)
    {
        cout<<"Nama Pengunjung : "<<queue[a].nama<<endl;
        cout<<"Jam Awal : "<<queue[a].ruangan.jamM<<endl;
        cout<<"Jam Akhir : "<<queue[a].ruangan.jamA<<endl;
        cout<<"Lama Sewa : "<<queue[a].ruangan.sewa<<endl;
        cout<<"Ukuran Ruangan : "<<cetakUkuranRuang(queue[a].ruangan.ukuran)<<endl;
        cout<<"Harga Ruangan : "<<queue[a].ruangan.harga<<endl;
        cout<<"======================================="<<endl;
        if(queue[a].makan!=NULL)
        {
            int b =0;
            while(queue[a].makan[b].harga!=0)
            {
                cout<< queue[a].makan[b].nama<<"\t";
                cout<<queue[a].makan[b].harga<<endl;
                b++;
            }
            cout<<"======================================="<<endl;
        }
        if(queue[a].minum!=NULL)
        {
            int b = 0;
            while(queue[a].minum[b].harga!=0)
            {
                cout<< queue[a].minum[b].nama<<"\t";
                cout<<queue[a].minum[b].harga<<endl;
                b++;
            }
            cout<<"======================================="<<endl;
        }
        cout<<"Pajak : "<<queue[a].pajak<<endl;
        cout<<"Total : "<<queue[a].total<<endl;
        cout<<"======================================="<<endl<<endl;
    }
    getch();
}

void inserts ()
{
    system("cls");
    char namaP[64];
    int ruang,jamM,jamA,lamaSewa,hargaRuangan,hargaRuang,pajak;
    int total = 0;
    Makan *pesanMakan = NULL;
    Minum *pesanMinum = NULL;
    cout<<"Masukan Nama Penyewa : ";
    cin.getline(namaP,64);
    do
    {
        cout<<"1. Small "<<endl;
        cout<<"2. Medium "<<endl;
        cout<<"3. Large "<<endl;
        cout<<"Masukan Ukuran Ruangan : ";
        cin>>ruang;
    }
    while(ruang!=1 && ruang!=2 &&ruang!=3 );
    cout<<"Jam Mulai : ";
    cin>>jamM;
    cout<<"Jam Akhir : ";
    cin>>jamA;
    if (ruang==1) hargaRuang = 68500;
    else if (ruang==2) hargaRuang = 89000;
    else if (ruang ==3) hargaRuang = 123400;
    lamaSewa = jamA-jamM;
    hargaRuangan = hitungHarga(lamaSewa, hargaRuang);
    total = hargaRuangan;
    int pil;
    do
    {
        cout<<"Ingin Memesan Makanan "<<endl;
        cout<<"1. Iya " <<endl;
        cout<<"2. Tidak " <<endl;
        cin>>pil;
    }
    while(pil !=1 && pil!=2);
    if (pil==1)
    {
        pesanMakan= pesanMakanan();
    }
    do
    {
        system("cls");
        cout<<"Ingin Memesan Minum "<<endl;
        cout<<"1. Iya " <<endl;
        cout<<"2. Tidak " <<endl;
        cin>>pil;
    }
    while(pil !=1 && pil!=2);
    if (pil==1)
    {
        pesanMinum= pesanMinuman();
    }
    int a = 0;
    if(pesanMakan!=NULL)
    {
        while(pesanMakan[a].harga!=0)
        {
            getch();
            total+=pesanMakan[a].harga;
            a++;
        }
    }
    a = 0;
    if(pesanMinum!=NULL)
    {
        while(pesanMinum[a].harga!=0)
        {
            total+=pesanMinum[a].harga;
            a++;
        }
    }
    pajak = hitungPajak(total);
    total+=pajak;
    enqueue(namaP,jamM,jamA,lamaSewa,ruang,hargaRuang,hargaRuangan,pesanMakan,pesanMinum,pajak,total);



}
int main()
{
    int pil;
    cout<<"Masukan maks : ";
    cin>>maks;
    queue = new Queue[maks];
    do
    {
        system("cls");
        cout<<"1. Enqueue "<<endl;
        cout<<"2. Dequeue "<<endl;
        cout<<"3. View "<<endl;
        cout<<"4. Exit "<<endl;
        cout<<"Masukan Pilihan : ";
        cin>>pil;
        cin.ignore();
        switch (pil)
        {
        case 1 :
            if(!isFull()) inserts();
            else
            {
                cout<<"Queue Penuh..";
                getch();
            }
            break;
        case 2 :
            if(!isEmpty()) dequeue();
            else
            {
                cout<<"Queuue Kosong... ";
                getch();
            }
            break;
        case 3 :
            if(!isEmpty()) view();
            else
            {
                cout<<"Queuue Kosong... ";
                getch();
            }
            break;
        }
    }
    while(pil!=4);
}
