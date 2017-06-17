#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

struct peminjaman
{
    string buku,alamat;
    int tglp,tglk;
};

struct dataa
{
    peminjaman baru;
    int no;

} data[90],temp,xx;

int denda1, denda2, denda3, denda4, denda5;
int pil,x,a,b,d,c,loc,j,p,simpan,minn;
char kembali;

void masukan();
void tampilkann();
void Delet();
void swaps (int *a, int*b);
void quickSort(dataa *data, int left, int right);

int main()
{
    do
    {
        cout<<">> Menu PIlihan <<\n";
        cout<<"--------------------------\n";
        cout<<"1. Input\n";
        cout<<"2. View\n";
        cout<<"3. Hapus\n";
        cout<<"4. Quick Sort\n";
        cout<<"\n";
        cout<<"Masukkan menu pilihan anda\t: ";
        cin>>pil;
        system("cls");
        switch(pil)
        {
        case 1:
            masukan();
            break;
        case 2:
            tampilkann();
            break;
        case 3:
            Delet();
            break;
        case 4:
            quickSort(data,1,x);
            break;
        default:
            cout<<"Pilihan anda salah\n";
        }
        cout<<"\nkiembali...? (y/t)\t: ";
        cin>>kembali;
        system("cls");
    }

    while(kembali=='y'||kembali=='Y');
}

void masukan()
{
    cout<<"Masukkan banyak data\t: ";
    cin>>x;
    for(int a=1; a<=x; a++)
    {
        cout<<" No         : ";
        cin>>data[a].no;
        cout<<" Input Buku : ";
        cin.sync();
        getline(cin,data[a].baru.buku);
        cout<<" Tgl Pinjam : ";
        cin>>data[a].baru.tglp;
        cout<<" Tgl Kembali : ";
        cin>>data[a].baru.tglk;
        cout<<endl;
    }
}

void tampilkann()
{
    for(int a=1; a<=x; a++)
    {
        cout<<"No           : "<<data[a].no;
        cout<<"\nBuku        : "<<data[a].baru.buku;
        cout<<"\nTgl Pinjam  : "<<data[a].baru.tglp;
        cout<<"\nTgl Kembali : "<<data[a].baru.tglk;
        cout<<"\n-------------------------\n";
        if(data[a].baru.tglk>data[a].baru.tglp)
        {
            if(data[a].baru.tglk-data[a].baru.tglp>7)
            {
                cout<< " Anda Meminjam buku selama "<<data[a].baru.tglk-data[a].baru.tglp<< " hari"<<endl;
                if(data[a].baru.buku=="saintek")
                {
                    denda1=(data[a].baru.tglk-data[a].baru.tglp-7)*3500;
                    cout<< " Denda Rp."<<denda1<<",-"<<endl;
                }
                else if(data[a].baru.buku=="agama")
                {
                    denda2=(data[a].baru.tglk-data[a].baru.tglp-7)*2000;
                    cout<< " Denda Rp."<<denda2<<",-"<<endl;
                }
                else if(data[a].baru.buku=="cerita")
                {
                    denda3=(data[a].baru.tglk-data[a].baru.tglp-7)*1500;
                    cout<< " Denda Rp."<<denda3<<",-"<<endl;
                }
                else if(data[a].baru.buku=="novel")
                {
                    denda4=(data[a].baru.tglk-data[a].baru.tglp-7)*2500;
                    cout<< " Denda Rp."<<denda4<<",-"<<endl;
                }
                else if(data[a].baru.buku=="komik")
                {
                    denda5=(data[a].baru.tglk-data[a].baru.tglp-7)*2500;
                    cout<< " Denda Rp."<<denda5<<",-"<<endl;
                }
                else
                {
                    cout<< " Inputan buku salah !!"<<endl;
                }
            }
            else
            {
                cout<< " Anda Meminjam buku selama "<<data[a].baru.tglk-data[a].baru.tglp<< " hari"<<endl;
                cout<< " Denda Rp.0,-"<<endl;
            }
        }
        else
        {
            if(30-data[a].baru.tglp+data[a].baru.tglk>7)
            {
                cout<< " Anda Meminjam buku selama "<<30-data[a].baru.tglp+data[a].baru.tglk<< " hari"<<endl;
                if(data[a].baru.buku=="saintek")
                {
                    denda1=(30-data[a].baru.tglp+data[a].baru.tglk-7)*3500;
                    cout<< " Denda Rp."<<denda1<<",-"<<endl;
                }
                else if(data[a].baru.buku=="agama")
                {
                    denda2=(30-data[a].baru.tglp+data[a].baru.tglk-7)*2000;
                    cout<< " Denda Rp."<<denda2<<",-"<<endl;
                }
                else if(data[a].baru.buku=="cerita")
                {
                    denda3=(30-data[a].baru.tglp+data[a].baru.tglk-7)*1500;
                    cout<< " Denda Rp."<<denda3<<",-"<<endl;
                }
                else if(data[a].baru.buku=="novel")
                {
                    denda4=(30-data[a].baru.tglp+data[a].baru.tglk-7)*2500;
                    cout<< " Denda Rp."<<denda4<<",-"<<endl;
                }
                else if(data[a].baru.buku=="komik")
                {
                    denda5=(30-data[a].baru.tglp+data[a].baru.tglk-7)*2500;
                    cout<< " Denda Rp."<<denda5<<",-"<<endl;
                }
                else
                {
                    cout<< " Inputan buku salah !!"<<endl;
                }
            }
            else
            {
                cout<< " Anda Meminjam buku selama "<<30-data[a].baru.tglp+data[a].baru.tglk<< " hari"<<endl;
                cout<< " Denda Rp.0,-"<<endl;

            }

        }
        cout<<endl;
    }
}

void Delet()
{
    cout<<"Pilih data yang anda hapus berdasarkan no\t: ";
    cin>>p;
    for( a=1; a<=x; a++)
    {

        if(p==data[a].no)
        {
            data[a]=data[a+1];
        }

    }
    x--;
    cout<<"Data terhapus";

}

void swaps (dataa *a, dataa*b)
{

    dataa temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(dataa *data, int left, int right)
{
    int a = left, b = right;
    int pivot = data[(left + right) / 2].no;

    while (a <= b)
    {
        while (data[a].no< pivot)
            a++;
        while (data[b].no> pivot)
            b--;
        if (a <= b)
        {
            swaps(&data[a],&data[b]);
            a++;
            b--;
        }
    };


    if (left < b)
        quickSort(data, left, b);
    if (a < right)
        quickSort(data, a, right);

}
