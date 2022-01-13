#include <stdio.h>
#include <stdlib.h>

int jumlah,tanda=1;

/*
    NGAKAN PUTU WIDYASPRANA
    2008561033
    C
*/

int main()
{   
    //  Variabel
        int input,ulang;
        int array[]={3,4,2,13,30};

    system("cls");
    printf(" Masukan Data Yang Dicari : ");
    scanf("%d",&input);
    getchar();

    jumlah=sizeof(array)/sizeof(array[0]);

    system("cls");

    //  Metode Pencarian
        for(int i=0;i<jumlah;i++){
            if(array[i]==input){
                printf("Nilai %d ditemukan pada indeks ke-%d \n",input,i);
                tanda=-1;
                break;
            }
        }

    //  Metode Pemasukan
        if(tanda==1){
            jumlah=jumlah+1;
            array[jumlah]=input;
        }

    //  Cetak
        printf("\nData Array : ");
        for(int i=0;i<jumlah;i++){
            printf("[ %d ] ",array[i]);
        }

        if(tanda==1){
            printf ("\n\n[ Penambahan Data %d pada Indeks Ke-%d ]",input,jumlah);
        }
    
    printf("\n");
    getchar(); 
}