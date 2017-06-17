#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void shell_sort (char ar[], int size)
{
  int j;
  for (int gap = size / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < size; ++i)
    {
      char temp = ar[i];
      for (j = i; j >= gap && temp < ar[j - gap]; j -= gap)
      {
        ar[j] = ar[j - gap];
      }
      ar[j] = temp;
    }
  }
}

int main()
{
    int jum;
    char hrf[100];
    cout<< " Input Jumlah : ";
    cin>>jum;
    cin.ignore();

    for(int a=0;a<jum;a++){
        cout<< " Input Huruf "<<a+1<<" : ";
        cin>>hrf[a];
    }
    cout<< "\n"<<endl;
    cout<< " Pengurutan karakter : "<<endl;
    shell_sort(hrf, jum);

    for(int c=0;c<jum;c++){
        cout<<hrf[c]<<ends;
    }
    return 0;
}
