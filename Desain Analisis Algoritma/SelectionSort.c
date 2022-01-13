#include <stdio.h>

int main()
{
    //int data2[10]={1,3,5,7,9,2,4,6,8,10};

    int data2[10]={24,23,56,7,8,9,3,12,99,21};

    // [ Mencari ukuran array ] //

    /*
        sizeof adalah ukuran data, kalau integer 4 bytes


        sizeof (data) artinya 4*10= 40
        sizeof (data[0]) artinya 4 bytes

        ukuran array = 40/4 = 10
    */

    int n = sizeof(data2)/sizeof(data2[0]);

    // [ Prose Pengurutan ] //
    
    // Deklarasi
    int i,j,min,temp;

    // melakukan perulangan dengan i sebagi awal
    for (i=0;i<n-1;i++){

        min=i;
        

        // melakukan perulangan j untuk pengecekan
        for (j=i+1;j<n;j++){
            if (data2[j]<data2[min]){
                min=j;
            }

            // swap
            temp = data2[min];
            data2[min] = data2[i];
            data2[i]=temp;
        }
    }

    /* [ Penjelasan]

    Kasus 1:
        indek pertama i adalah 0 = 1;
        indeks pertama j adalah 1= 3;
        min= 0;
        ~
        jika 3<1 
            (salah)
                min = 0
                i = 0
                data[min]=1
    
    Kasus 2 ;
        indeks pertama i adalah 4 = 9;
        indeks pertama j adalah 5 = 2;
        min = 4;
        ~
        jika 2<9
            (benar)
                min = 5
                i= 4
                data[min]=2;

            swap
            1. temp = data[min];
               temp = 2

            2. data[min]=data[i];
               data[min] = 9
            
            3. data[i]=temp;
               data[i]=2;

        Akhirnya data ke-4 adalah 2.
        dan data ke-4 adalah 9.

    */

   // Cetak Terurut

   printf ("\nData Terurut : ");
   for (int k=0;k<n;k++){
       printf (" %d ",data2[k]);
   }
}


// Kompleksitas Algoritma Big O

/*
    Jika i =0 maka akan mengecek sejumlah n-1;
    Jika i=1 maka akan mengecek sejumlah n-2;

    contoh :
        2,1,4,3
            i=0 , a[i]=2 , sisanya 1,4,3 (3)
            i=1, a[i]=1, sisanya 4,3 (2)

    
    Jadi, i = k maka akan mengcek sejumlah n-k;

    maka jumlah setiap operasi
    T(n) = (n-1)+(n-2)+(n-3)+(n-4)+...+(n-k)
    T(n) = n(n-1)/2
         = (n^2 - n )/ 2
    (Pangkat tertinggi 2-kuadrat )


    Notasi :  O(n) = n^2;

    contoh :
        2,1,4,3 = 4 buah

        T(n)= 3+2+1+0 = 6

*/