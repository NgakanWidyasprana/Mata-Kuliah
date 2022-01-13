#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
    ===============================
     PROGRAM BUBBLE SORT OPTIMIZED
            by Ngakan WP
             2008561033
    ===============================
*/
//  Prototipe Fungsi dan Prosedur
    void inputArray();
    void lihatArray();
    void bubbleSort();

int main()
{
    //  Variabel
        int array[MAX];
        int cek;

    inputArray(array);

    system("cls");
    printf("\n==================================");
    printf("\n Apakah ingin melakukan sorting ? ");
    printf("\n==================================\n");
    printf("  Masukan Pilihan [1]/[0] : ");
    scanf("%d",&cek);
    getchar();

    if(cek==1){
        bubbleSort(array);
        lihatArray(array,2);
    }else{
        lihatArray(array,1);
    }
}

void inputArray(int array[MAX])
{
    system("cls");

    //  Variabel
        int input;

    for(int i=0;i<MAX;i++){
        printf("\nMasukan Nilai Array [%d] : ",i);
        scanf("%d",&input);
        getchar();

        //  Proses Input
            array[i]=input;
    }
}

void lihatArray(int array[MAX],int cek)
{
    system("cls");
    if(cek==1){
        printf("Isi Dari Array Sebelum di Sorting\n");
        for(int i=0;i<MAX;i++){
            printf("\nArray [%d] : %d",i,array[i]);
        }
    }else{
        printf("Isi Dari Array Setelah di Sorting\n");
        for(int i=0;i<MAX;i++){
            printf("\nArray [%d] : %d",i,array[i]);
        }   
    }
}

void bubbleSort(int arraySort[MAX])
{
    for(int i=0;i<MAX-1;i++){
        int cek=0;
        for(int j=0;j<MAX-i-1;j++){
            if(arraySort[j]>arraySort[j+1]){

                //  Proses Swapping
                    int temp=arraySort[j];
                    arraySort[j]=arraySort[j+1];
                    arraySort[j+1]=temp;

                cek=1;
            }
        }
        if(cek==0)
            break;
    }
}
