#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main()
{
    struct pengembalian{
        int buku;
        int tgl_p;
        int tgl_k;
    }book[100];

    char ex,ey;
    int pilih, denda, b, a, c,j,k,hap;

    do{
    cout<< "\n 1. USER\n";
    cout<< " 2. PETUGAS\n";
    cout<< "=======================================\n";
    cout<< " Anda masuk sebagai ?? [1/2] : ";
    cin>>pilih;


    switch(pilih){
    case 1 :system("cls");
            cout<<endl;
            cout<< "  >> ANDA MASUK SEBAGAI USER << "<<endl;
            cout<<endl;
            cout<< "  -- Daftar Harga Buku Pinjam -- \n";
            cout<< "=======================================\n";
            cout<< "| 1. Saintek           | Rp.3500/hari |\n";
            cout<< "| 2. Agama             | Rp.2000/hari |\n";
            cout<< "| 3. Cerita Anak-anak  | Rp.1500/hari |\n";
            cout<< "| 4. Novel             | Rp.2500/hari |\n";
            cout<< "| 5. Komik             | Rp.2500/hari |\n";
            cout<< "=======================================\n";
            cout<<endl;

            cout << " Jumlah peminjam : ";
            cin>>b;
            cout<< "=======================================\n";
            for (a=1; a<=b; a++){
            cout<< " Buku yang di pinjam No:[ 1- 5 ] : "; cin>>book[a].buku;
            cout<< " Tanggal pinjam         [ 1-30 ] : "; cin>>book[a].tgl_p;
            cout<< " Tanggal Kembali        [ 1-30 ] : "; cin>>book[a].tgl_k;
            cout<< "=======================================\n";
            }

            cout<< " Apakah ingin mengulang ?? (y/n) : ";
            cin>>ex;
            break;
    case 2 :system("cls");
            cout<<endl;
            cout<< "  >> ANDA MASUK SEBAGAI PETUGAS << "<<endl;
            cout<<endl;
            cout<< "  -- Daftar Harga Buku Pinjam -- \n";
            cout<< "=======================================\n";
            cout<< "| 1. Saintek           | Rp.3500/hari |\n";
            cout<< "| 2. Agama             | Rp.2000/hari |\n";
            cout<< "| 3. Cerita Anak-anak  | Rp.1500/hari |\n";
            cout<< "| 4. Novel             | Rp.2500/hari |\n";
            cout<< "| 5. Komik             | Rp.2500/hari |\n";
            cout<< "=======================================\n";
            cout<<endl;

            do{
            cout<< " 1. Insert"<<endl;
            cout<< " 2. View"<<endl;
            cout<< " 3. Delete"<<endl;
            cout<< "=======================================\n";
            cout<< " pilih Menu : "; cin>>pilih;
            cout<< "=======================================\n";

            switch(pilih){
                case 1 :cout << " Jumlah peminjam : ";
                        cin>>b;
                        cout<< "=======================================\n";
                        for (a=1; a<=b; a++){
                        cout<< " Buku yang di pinjam No:[ 1- 5 ] : "; cin>>book[a].buku;
                        cout<< " Tanggal pinjam         [ 1-30 ] : "; cin>>book[a].tgl_p;
                        cout<< " Tanggal Kembali        [ 1-30 ] : "; cin>>book[a].tgl_k;
                        cout<< "=======================================\n";
                        }
                        cout<<" Apakah anda ingin tetap masuk sebagai petugas(y/n)?";
                        cin>>ex;
                        break;
                case 2 :cout<< " -- View Data -- "<<endl;
                        cout<< "=======================================\n";
                        for (a=1; a<=b; a++){
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
                        cout<<" Apakah anda ingin tetap masuk sebagai petugas(y/n)?";
                        cin>>ex;
                        break;
                case 3 :cout<<" Data yang ingin di hapus : ";
                        cin>>hap;
                        for(a=1; a<=b; a++)
                        {
                            if(hap==a)
                            {
                                for (int j = a ; j<= b+1 ;j++)
                                {
                                    book[j]=book[j+1];
                                }
                                b--;
                            }
                        }
                        cout<<" Apakah anda ingin tetap masuk sebagai petugas(y/n)?";
                        cin>>ex;
                        break;
                }
    }while(ex=='y'||ex=='Y');
    }
                cout<<" Anda keluar sebagai petugas"<<endl;
                cout<<" Apakah anda ingin kembali ke menu paling awal(y/n)?";
                cin>>ex;


}while(ex=='y' || ex=='Y');
}
