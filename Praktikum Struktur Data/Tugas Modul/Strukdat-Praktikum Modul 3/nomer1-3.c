#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

// Prototipe Fungsi
   int cekStack();
   void push();
   void pop();
   void seek();
   void clear();

typedef struct Data{

    char nama[15];
    struct Data *next;

}data;

data *top,*tmp,*baru;

int main()
{   
     // Variabel Menu 
        top=NULL;
        int status=1,pilihan;

    while (status)
    {   
        system("cls");
        printf ("\n======== MENU STACK =========\n");
        printf ("\n         [1] PUSH              ");
        printf ("\n         [2] POP               ");
        printf ("\n         [3] CLEAR             ");
        printf ("\n         [4] PRINT             ");
        printf ("\n         [5] EXIT              ");
        printf ("\n\n========= by: Ngakan ========= ");
        printf ("\n\nMasukan Pilihan : ");
        scanf  ("%d",&pilihan);
        getchar();

        switch (pilihan)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                clear();
                break;
            case 4:
                seek();
                break;
            case 5:
                system("cls");
                printf ("\n==========================  ");
                printf ("\n      TERIMA KASIH :)       ");
                printf ("\n==========================\n");
                status=0;
                break;
            default:
                system("cls");
                printf ("\n==============================================  ");
                printf ("\n[ Pilihan Tidak Tersedia, Silahkan Ulangi ! ]   ");
                printf ("\n==============================================\n");
                getchar();
        }
    }
    getchar();
}

int cekStack()
{   

    // Variabel
       int i=0;
       tmp=top;

    while(tmp!=NULL)
    {
        tmp=tmp->next;
        i++;
    }
    return i;
}

void push()
{   
    system("cls");

    // Variabel
       char nm[15];
    // Alokasi Memori Dinamis
       baru = (data*)malloc(sizeof(data));

    if(cekStack()<MAX){
        BALIK:
        printf ("\nMasukan Nama [15]: ");
        scanf  ("%[^\n]",&nm);
        getchar();

        if (strlen(nm)<=sizeof(nm)){
            strcpy(baru->nama,nm);
            baru->next =top;
            top=baru;
        }else{
            system("cls");
            printf ("\n=====================================   ");
            printf ("\n Maksimal Karakter Adalah 15 Huruf !    ");
            printf ("\n=====================================\n ");
            goto BALIK;
        }
    }else{
        system("cls");
        printf ("\n=====================================   ");
        printf ("\n      Maaf Stack Sudah Penuh :(         ");
        printf ("\n=====================================\n ");
        getchar();
    }  
}

void pop()
{   
    // Variabel
       tmp=top;

    if(tmp==NULL){
        system ("cls");
        printf ("\n======================   ");
        printf ("\n  Stack Masih Kosong     ");
        printf ("\n====================== \n");
    }else{
        system ("cls");
        top=top->next;
        printf ("Data [ %s ] Berhasil Dihapus...",tmp->nama);
        free(tmp);
    }
    getchar();
}

void seek()
{   
    // Variabel
       tmp=top;

    if (top==NULL){
        system ("cls");
        printf ("\n======================   ");
        printf ("\n  Stack Masih Kosong     ");
        printf ("\n====================== \n");
    }else{
        system ("cls");
        printf ("\n ========= ISI STACK ========\n\n");
        while(tmp->next!=NULL)
        {
            printf ("   [  ...  ]--- %s\n",tmp->nama);
            tmp=tmp->next;
        }
        printf ("   [ BAWAH ]--- %s\n",tmp->nama);
        printf ("\n ========= by: Ngakan ========\n");
    }
    getchar();
}

void clear()
{   
    if(top==NULL){
        system ("cls");
        printf ("\n======================   ");
        printf ("\n  Stack Masih Kosong     ");
        printf ("\n====================== \n");
    }else{
        system("cls");
        while(top!=NULL)
        {
            tmp=top;
            top=top->next;
            free(tmp);
        }
        printf ("Semua data berhasil dihapus...");
    }
    getchar();
}