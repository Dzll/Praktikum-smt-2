#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;


struct pengembalian
{
    int buku;
    int tgl_p;
    int tgl_k;
    int denda;
} book[100],temp;

int partisi (int awal, int akhir)
{
    int x,i,j;
//x=data[awal];
    i=awal;
    j=akhir;

    while(1)
    {
        while(book[i].denda<book[awal].denda)
            i=i+1;

        while(book[j].denda>book[awal].denda)
            j=j-1;

        if (i<j)
        {
            //tukarkan data
            temp=book[i];
            book[i]=book[j];
            book[j]=temp;
        }
        else
            return j;
    }
}

void quick_sort(int awal, int akhir)
{
    int q;
    if(awal<akhir)
    {
        q=partisi(awal,akhir);
        quick_sort(awal,q);
        quick_sort(q+1,akhir);
    }
}


int main()
{

    int pilih, denda, b, a, c,j,k,hap,n=0;

    cout<< "  -- Daftar Harga Buku Pinjam -- \n";
    cout<< "=======================================\n";
    cout<< "| 1. Saintek           | Rp.3500/hari |\n";
    cout<< "| 2. Agama             | Rp.2000/hari |\n";
    cout<< "| 3. Cerita Anak-anak  | Rp.1500/hari |\n";
    cout<< "| 4. Novel             | Rp.2500/hari |\n";
    cout<< "| 5. Komik             | Rp.2500/hari |\n";
    cout<< "=======================================\n";
    do
    {
        cout<< " 1. Insert"<<endl;
        cout<< " 2. View"<<endl;
        cout<< " 3. Delete"<<endl;
        cout<< " 4. Sorting"<<endl;
        cout<< "=======================================\n";
        cout<< " pilih Menu : ";
        cin>>pilih;
        cout<< "=======================================\n";

        switch(pilih)
        {
        case 1 :
            cout<< " Buku yang di pinjam No:[ 1- 5 ] : ";
            cin>>book[n].buku;
            cout<< " Tanggal pinjam         [ 1-30 ] : ";
            cin>>book[n].tgl_p;
            cout<< " Tanggal Kembali        [ 1-30 ] : ";
            cin>>book[n].tgl_k;
            cout<< "=======================================\n";
            if(book[n].tgl_k-book[n].tgl_p>7)
            {
                cout<< " Anda tidak boleh meminjam buku selama "<<book[n].tgl_k-book[n].tgl_p<< " hari"<<endl;
                if(book[n].buku==1)
                {
                    book[n].denda=(book[n].tgl_k-book[n].tgl_p)*3500;
                }
                else if(book[n].buku==2)
                {
                    book[n].denda=(book[n].tgl_k-book[n].tgl_p)*2000;
                }
                else if(book[n].buku==3)
                {
                    book[n].denda=(book[n].tgl_k-book[n].tgl_p)*1500;
                }
                else if(book[n].buku==4)
                {
                    book[n].denda=(book[n].tgl_k-book[n].tgl_p)*2500;
                }
                else if(book[n].buku==5)
                {
                    book[n].denda=(book[n].tgl_k-book[n].tgl_p)*2500;

                }
            }
            else
            {
                book[n].denda=0;
            }
            n++;


            break;
        case 2 :
            cout<< " -- View Data -- "<<endl;
            cout<< "=======================================\n";
            for (a=0; a<n; a++)
            {
                if(a!=c)
                {
                    if(book[a].buku==1)
                    {
                        cout<< " Buku yang di pinjam : Saintek"<<endl;
                    }
                    else if(book[a].buku==2)
                    {
                        cout<< " Buku yang di pinjam : Agama"<<endl;
                    }
                    else if(book[a].buku==3)
                    {
                        cout<< " Buku yang di pinjam : Cerita Anak- Anak "<<endl;
                    }
                    else if(book[a].buku==4)
                    {
                        cout<< " Buku yang di pinjam : Novel"<<endl;
                    }
                    else
                    {
                        cout<< " Buku yang di pinjam : Komik"<<endl;
                    }
                    cout<< " Tanggal pinjam      : "<<book[a].tgl_p<<endl;
                    cout<< " Tanggal Kembali     : "<<book[a].tgl_k<<endl;
                    cout<< "=======================================\n";
                    cout<< "Denda                :"<<book[a].denda<<endl;

                }
            }
            break;
        case 3 :
            cout<<" Data yang ingin di hapus : ";
            cin>>hap;
            for(a=0; a<n; a++)
            {
                if(hap==a)
                {
                    for (int j = a ; j<= n+1 ; j++)
                    {
                        book[j]=book[j+1];
                    }
                    n--;
                }
            }
            break;
        case 4: int l=0, r=n, p=l;
                while(l<r){
                    if(book[l].denda<book[r].denda){
                        l++;
                    }else{
                        book[90]=book[l];
                        book[l]=book[r];
                        book[r]=book[90];
                        p=r;
                    }
                    if(book[p].denda<book[l].denda){
                        book[90]=book[l];
                        book[l]=book[r];
                        book[r]=book[90];
                    }else{
                        l++;
                    }
                }
                getch();
                for(int i=0; i<n; i++){
                    cout<<"Nama : "<<book[i].denda;
                    cout<<endl;
                    cout<<"==="<<endl;
                }

        }
    }
    while(pilih!=5);
}
