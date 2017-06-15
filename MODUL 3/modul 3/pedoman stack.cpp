#include <iostream>
#include <windows.h>

using namespace std;

struct stack
{
    int no;
    string nama;
}*s;


int pil,maks,top=-1;
char kembali;

bool isEmpety();
bool isFull();
void push();
void pop();
void view();
int main()
{
    cout<<"linier stack\n";
    cout<<"Masukkan banyak data\t: ";
    cin>>maks;
    s=new stack[maks];
    system("cls");
    do
    {
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. View\n";
        cout<<"4. Exit\n";
        cout<<"Masukkan pilihan anda\t: ";
        cin>>pil;
        switch(pil)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            view();
            break;
        case 4:
            return 0;
        default:
            cout<<"Pilihan anda salah";
        }

        cout<<"\n\nKembali..?";
        cin>>kembali;
        system("cls");
    }
    while(kembali=='y'||kembali=='Y');

}


bool isEmpety()
{
    if(top==-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull()
{
    if(top==maks-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push()
{
    if(isFull())
    {
        cout<<"Data sudah penuh";
    }
    else
    {
        top++;
        cout<<"No\t\t: ";
        cin>>s[top].no;
        cout<<"Nama\t\t: ";
        cin>>s[top].nama;
    }
}

void pop()
{
    if(isEmpety())
    {
        cout<<"Data masih koson";
    }
    else
    {
        top--;
    }
}

void view()
{
    if(isEmpety())
    {
        cout<<"Data masih kosong";
    }
    else
    {
        for (int a=0; a<=top; a++)
        {

            cout << "NO\t\t: "<<s[a].no<< endl;
            cout << "Nama\t\t: "<<s[a].nama<< endl<<endl;
//    }
//    for (int a=max_stack-1; a>=top2; a--)
//    {
//        cout << "nama kendaraan"<< pajak[a].kendaraan<< endl;
//        cout << "nama no polisi"<<pajak[a].no_polisi<< endl;
//        cout << "tanggal pembelian"<<pajak[a].tanggal_pembelian<< endl;
//    }
        }
    }
}
