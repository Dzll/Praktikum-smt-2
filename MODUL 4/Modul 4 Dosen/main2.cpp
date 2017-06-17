#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define MAX 7
using namespace std;

void shell();
int pilihan,hitung,i;
char ulang,pilih;
char nx[10];
int data[MAX];
int data1[100];
int temp;
int n;
int cek(char str[])
{
    int i, panjang;
    panjang=strlen(str);
    for(i=0; i<panjang; i++)
    {
        if((i==0)&&(str[i]=='-'))
            i++;
        if(!isdigit(str[i]))
        {
            cout<<"Input salah ! Ulangi input !\n";
            return 0;
        }
    }
    return 1;
}
int main()
{
awal :
    system("cls");
    do
    {
        /*int n;
         for (hitung=0;hitung<8;hitung++)
         data1[hitung]=data[hitung]; */
        cout<<"========================"<<endl;
        cout<<"| Program Sorting Data |"<<endl;
        cout<<"========================"<<endl;
        cout<<" "<<endl<<endl;
        cout<<"Masukkan Banyak Data : ";
        cin>>nx;
        cout<<endl;
    }
    while(!cek(nx));
    n=atoi(nx);
    int data[100];
    srand(time(NULL));
    int i;
    for(i=0; i<n; i++)
    {
        data[i]= rand()%n;
        cout<<data[i]<<" ";
    }
    cout<<endl;
    {

        cout<<"\nUrutlan Lagi? [y/t]";
        cin>>ulang;
        cout<<"\n\n";
        if (ulang=='y'||ulang=='Y')
        {
            goto awal;
        }
        else
        {
            exit(1);
        }
    }
}

void shell()
{
    cout<<"------------------------------------------------\n";
    int gap=n/2;
    do
    {
        int swap;
        do

        {
            swap=0;
            for(int i=0; i<n-gap; i++)
                if(data1[i]>data1[i+gap])
                {
                    int t=data1[i];
                    data1[i]=data1[i+gap];
                    data1[i+gap]=t;
                    swap=1;
                }
        }
        while(swap);
    }
    while(gap=gap/2);

    if (pilih=='a')
    {
        cout<<"\nMenjalankan metode Shell Sort dengan pengurutan Ascending";
        cout<<"\n\nHasil Pengurutan: \n\n";
        for(i=0; i<n; i++)
            cout<<data1[i]<<" ";
    }
    if (pilih=='d')
    {
        cout<<"\nMenjalankan metode Shell Sort dengan pengurutan Desscending";
        cout<<"\n\nHasil Pengurutan: \n\n";
        for(i=n-1; i>=0; i--)
            cout<<data1[i]<<" ";
    }
    cout<<endl;
}
