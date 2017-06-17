#include <iostream>
#define n 20

using namespace std;
int Ar[n];
void quickSort(int arr[], int left, int right);

int main()
{
    int jumlahBil=5;

    cout<<"Masukkan jumlah bilangan dalam arry [Maksimal 20]"<<endl;
    cin>>jumlahBil;
    int Ar[jumlahBil];
    for(int i=0; i<jumlahBil; i++)
    {
        cout<<"Bilangan ke-"<< i+1 << endl;
        cin>>Ar[i];
    }
    quickSort(Ar,0,jumlahBil-1 );
    cout<<"Data yang telah diurutkan"<<endl;
    for(int i=0; i<jumlahBil; i++)
    {
        cout<<Ar[i]<<"\n";
    }

}
void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;

    int tmp;

    int pivot = arr[(left + right) / 2];
    while (i <= j)
    {

        while (arr[i] < pivot)

            i++;

        while (arr[j] > pivot)

            j--;

        if (i <= j)
        {
            tmp = arr[i];

            arr[i] = arr[j];

            arr[j] = tmp;

            i++;

            j--;

        }

    };

    if (left < j)

        quickSort(arr, left, j);

    if (i < right)

        quickSort(arr, i, right);
}
