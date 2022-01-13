#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/*
    QUICK-SORT MIDDLE PIVOT
    NGAKAN PUTU WIDYASPRANA
    2008561033
*/

//  Prototipe Fungsi dan Prosedur
    void menu_simpel();
    void inputArray();
    void quickSortMiddle();
    void lihatArray();
    int partition();
    int swap();
 
int main()
{
    //  Variabel
        int array[MAX];
        int cek;
    
    inputArray(array);
    menu_simpel(cek,array);
}

void menu_simpel(int cek,int array[MAX])
{
    system("cls");
    printf("\n==================================");
    printf("\n Apakah ingin melakukan sorting ? ");
    printf("\n==================================\n");
    printf("  Masukan Pilihan [1]/[0] : ");
    scanf("%d",&cek);
    getchar();

    if(cek==1){
        quickSortMiddle(array,0,MAX-1);
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

void quickSortMiddle(int arraySort[MAX],int left_side, int right_side)
{
    if (left_side< right_side) {
        int splitter= partition(arraySort, left_side, right_side);
        quickSortMiddle(arraySort, left_side, splitter- 1);
        quickSortMiddle(arraySort, splitter + 1, right_side);
    }
}

int partition(int arraySort[MAX],int left_side, int right_side)
{
    int middle=(left_side+right_side)/2;
    swap(&arraySort[left_side],&arraySort[middle]);

    int pivot= arraySort[left_side];
    int ptrLow=left_side+1;
    int ptrHigh=right_side;

    while(ptrLow<=ptrHigh)
    {
        while(arraySort[ptrHigh]>pivot)
            ptrHigh=ptrHigh-1;
        while(ptrLow<=ptrHigh && arraySort[ptrLow]<=pivot)
            ptrLow=ptrLow+1;

        if(ptrLow<=ptrHigh){
            swap(&arraySort[ptrLow],&arraySort[ptrHigh]);
            ptrLow=ptrLow+1;
            ptrHigh=ptrHigh-1;
        }
    }
    swap(&arraySort[left_side],&arraySort[ptrHigh]);
    return ptrHigh;
}

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}