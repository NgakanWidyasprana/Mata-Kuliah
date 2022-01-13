#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

//  Prototipe Fungsi Tampilan
    void s_menu();
    void s_keluar();
    void s_penuh();
    void s_kosong();
    void s_panjang();
    void s_reset();

//  Prototipe Fungsi Stack
    int cekPenuh();
    int cekKosong();
    void push();
    void pop();
    void clear();
    void seek();

typedef struct Data{

    char nama[15];

}data;

data barang[MAX];
int top=-1;

int main()
{   
    clear();
    s_menu();
}

/* 
=========================
 FUNGSI TAMPILAN PROGRAM
=========================
*/ 

void s_menu()
{   
    // Variabel
       int status=1,pilihan;

    while(status)
    {   
        system("cls");
        printf ("\n\t+---------------------+");
        printf ("\n\t|  Menu Tumpukan Kain |");
        printf ("\n\t+---------------------+");
        printf ("\n\t|      [1] Push       |");
        printf ("\n\t|      [2] Pop        |");
        printf ("\n\t|      [3] Clear      |");
        printf ("\n\t|      [4] Print      |");
        printf ("\n\t|      [5] Exit       |");
        printf ("\n\t+---------------------+");
        printf ("\n\nMasukan Pilihan : ");
        scanf  ("%d",&pilihan);
        getchar();

        switch(pilihan)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                if(cekKosong()==1)
                    s_kosong();
                else{
                    s_reset();
                    clear();
                }
                break;
            case 4:
                seek();
                break;
            case 5:
                s_keluar();
                status=0;
                break;
        }
    }
}

void s_keluar()
{   
    system("cls");
    printf ("\n====================   ");
    printf ("\n   Terima Kasih :)     ");
    printf ("\n====================\n ");
    getchar();
}

void s_penuh()
{   
    system("cls");
    printf ("\n======================  ");
    printf ("\n Maaf Stack Penuh :(    ");
    printf ("\n======================\n");
    getchar();
}

void s_kosong()
{
    system("cls");
    printf ("\n==========================  ");
    printf ("\n Stack Kosong, Isi Dahulu   ");
    printf ("\n==========================\n");
    getchar();
}

void s_panjang()
{
    system("cls");
    printf ("\n========================   ");
    printf ("\n Nama Maksimal 15 Huruf    ");
    printf ("\n======================== \n");
    getchar();
}

void s_reset()
{
    system("cls");
    printf ("\n============================= ");
    printf ("\n Stack Berhasil Di Kosongkan  ");
    printf ("\n=============================\n");
    getchar();
}
/*
============================
    FUNGSI STACK Program
============================
*/

int cekPenuh()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}

int cekKosong()
{
    if (top==-1)
        return 1;
    else
        return 0;
}

void push()
{   
    // Variabel
       char nm[15];

    if(cekPenuh()==1){
        s_penuh();
    }else{
        BALIK:
        printf ("\nMasukan Nama Kain : ");
        scanf  ("%[^\n]",&nm);
        getchar();

        if(strlen(nm)>sizeof(nm)){
            s_panjang();
            goto BALIK;
        }else{
            top=top+1;
            strcpy(barang[top].nama,nm);
        }
    }   
}

void pop()
{   
    // Variabel
       char tmp[]="-";

    if(cekKosong()==1){
        s_kosong();
    }else{
        system("cls");
        printf ("\nData [ %s ] Berhasil Dihapus...",&barang[top].nama);
        strcpy(barang[top].nama,tmp);
        top=top-1;
        getchar();
    }
}

void clear()
{   
    // Variabel
       char tmp[]="-";

    for (int i=0;i<MAX;i++){
        strcpy(barang[i].nama,tmp);
        top = -1;
    }

}

void seek()
{   
    printf ("\nJenis Kain :\n\n");
    for (int i=(MAX-1);i>-1;i--){
        printf ("   [...]  %s\n",&barang[i].nama);
    }
    getchar();
}