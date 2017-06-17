#include <iostream>
#include <iomanip>
#include <conio.h>
#include <time.h>
#include <windows.h>
#define MAX 7

using namespace std;

void bubble();
void SelectionSort();
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
 for(i=0;i<panjang;i++)
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
 for(i=0;i<n;i++)
 {
 data[i]= rand()%n;
 cout<<data[i]<<" ";
 }
cout<<endl;
{
 for (hitung=0;hitung<n;hitung++)
 data1[hitung]=data[hitung];
cout<<"\n==========================\n";
 cout<<"| Pilihan Metode Sorting |\n";
 cout<<"--------------------------\n";
 cout<<"| 1.Bubble sort |\n";
 cout<<"| 2.Selection sort |\n";
 cout<<"| 3.Shell sort |\n";
 cout<<"==========================\n\n";
cout<<"Pilih Metorde Sorting <1-3>: ";
 cin>>pilihan;
 cout<<"------------------------------------------------\n";
 cout<<"Pilihan pengurutan Ascending/Descending [a/d]? ";
 cin>>pilih;
 switch (pilihan)
 {
 case 1:
 bubble();
 break;
 case 2:
 SelectionSort();
 break;
 case 3:
 shell();
 break;
 default:
 cout<<"kode salah";
 break;
 }

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

void bubble()
{
 cout<<"------------------------------------------------\n";
 for (int i=0; i<n-1; i++)
 for (int ii=0; ii<n-1; ii++)
 if (data1[ii]>=data1[ii+1])
 {
 temp=data1[ii];
 data1[ii]=data1[ii+1];
 data1[ii+1]=temp;
 }
if (pilih=='a')
 {
 cout<<"\nMenjalankan metode Bubble Sort dengan pengurutan Ascending";
 cout<<"\n\nHasil Pengurutan: \n\n";
 for(int iii=0; iii<n; iii++)
 cout<<data1[iii]<<" ";
 }
 if (pilih=='d')
 {
 cout<<"\nMenjalankan metode Bubble Sort dengan pengurutan Descending";
 cout<<"\n\nHasil Pengurutan: \n\n";
 for(int iii=n-1; iii>=0; iii--)
 cout<<data1[iii]<<" ";
 }
 cout<<"\n";
}

void SelectionSort()
{
 cout<<"------------------------------------------------\n";
 int kecil;
 for (int i=0;i<n;i++)
 {
 kecil=i;
 for (int j=kecil+1; j<n;j++)
 {
 if (data1[kecil]>data1[j])
 {kecil=j;}
 }
 temp=data1[i];
 data1[i]=data1[kecil];
 data1[kecil]=temp;
 }
if (pilih=='a')
 {
 cout<<"\nMenjalankan metode Selection Sort dengan pengurutan Ascending";
 cout<<"\n\nHasil Pengurutan: \n\n";
 for(int iii=0; iii<n; iii++)
 cout<<data1[iii]<<" ";
 }
 if (pilih=='d')
 {
 cout<<"\nMenjalankan metode Selection Sort dengan pengurutan Dscending";
 cout<<"\n\nHasil Pengurutan: \n\n";
 for(int iii=n-1; iii>=0; iii--)
 cout<<data1[iii]<<" ";
 }
 cout<<"\n";
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
 for(int i=0;i<n-gap;i++)
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
 for(i=0;i<n;i++)
 cout<<data1[i]<<" ";
 }
 if (pilih=='d')
 {
 cout<<"\nMenjalankan metode Shell Sort dengan pengurutan Desscending";
 cout<<"\n\nHasil Pengurutan: \n\n";
 for(i=n-1;i>=0;i--)
 cout<<data1[i]<<" ";
 }
cout<<endl;
}
