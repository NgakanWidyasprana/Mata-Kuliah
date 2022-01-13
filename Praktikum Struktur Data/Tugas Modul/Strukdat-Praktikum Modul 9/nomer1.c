#include <stdio.h>
#include <stdlib.h>

/*
    NGAKAN PUTU WIDYASPRANA
    2008561033
    C
*/

typedef struct Data
{
    int angka;
    struct Data *leftChild;
    struct Data *rightChild;
}data;

data* akar;
int cek=0;

data* insertData(int angka)
{
    data* baru = (data*)malloc(sizeof(data));
    baru->angka=angka;
    baru->leftChild=NULL;
    baru->rightChild=NULL;
    return(baru);
}

void reviewLintasan(data* temp,int cari)
{
    if (temp == NULL)
        return;
 
    printf("%d ", temp->angka);

    //  Checking Node
        if(temp->angka==cari)
            cek=1;
    
    reviewLintasan(temp->leftChild,cari);
    reviewLintasan(temp->rightChild,cari);
}

int main()
{   
    //  Variabel
        int cari;

    akar=insertData(1);
    akar->leftChild= insertData(2);
    akar->rightChild=insertData(3);
    akar->leftChild->leftChild=insertData(4);
    akar->leftChild->rightChild=insertData(5);
    akar->rightChild->leftChild=insertData(6);
    akar->rightChild->rightChild=insertData(7);
    akar->leftChild->leftChild->leftChild=insertData(8);
    akar->leftChild->leftChild->rightChild=insertData(9);
    akar->rightChild->rightChild->leftChild=insertData(14);
    akar->rightChild->rightChild->rightChild=insertData(15);

    printf ("Input nomer urut : ");
    scanf("%d",&cari);
    getchar();

    system("cls");
    printf(" Lintasan Tree   : ");

    //  Secara Preorder
        reviewLintasan(akar,cari);
    
    if (cek==1)
        printf("\n Hasil Searching : ADA \n");
    else
        printf("\n Hasil Searching : TIDAK ADA \n");

    getchar();
}