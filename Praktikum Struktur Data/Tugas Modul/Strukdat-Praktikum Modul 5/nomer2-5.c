#include <stdio.h>
#include <stdlib.h>

/*
    Himpunan Bilangan Genap
*/

//  Prototipe Fungsi dan Prosedur
    int rekursif();
//  -----------------------------
    int s_ulang();
    void s_header();
    void s_hasil();
    void s_error();
    void s_reset();

int total=0,counter=0,Un=0;


int main()
{   
    //  Variabel
        int x,y,ulang;

    MENU:
    s_header();
    printf ("\nMasukan Jumlah Bilangan Genap : ");
    scanf ("%d",&total);
    getchar();

    printf ("\nMasukan Bilangan genap ke-n : ");
    scanf ("%d",&y);
    getchar();

    if(y>total){
        s_error();
        goto MENU;
    }else{
        s_hasil(rekursif(2,y),total,y);
    }

    s_ulang();
    printf("\n\n Masukan Pilihan Anda : ");
    scanf("%d",&ulang);
    getchar();

    if(ulang==0)
        return 0;
    else{
        s_reset();
        goto MENU;
    }
}

int rekursif(int x,int y)
{   
    if(total==1){
        counter++;
        Un=2;
        return 2;
    }else if(counter<total){

        if(counter<y)
            Un=Un+2;

        counter++;
        return rekursif(x,y)+rekursif(x+2,y);
    }
}

int s_ulang()
{   
    system("cls");
    printf("\n====================================");
    printf("\n Apakah Bapak/Ibu Ingin Mengulang ? ");
    printf("\n Tekan [1]: Jika Iya,               ");
    printf("\n Tekan [0]: Jika Tidak,             ");
    printf("\n------------------------------------");
    printf("\n         > Terima Kasih :) <        ");
    printf("\n====================================");
}

void s_header()
{   
    system("cls");
    printf("\n======================================\n");
    printf("\n Fitur Program :                        ");
    printf("\n [-1-] Menentukan Jumlah Suku ke-Sn     ");
    printf("\n [-2-] Menentukan Suku ke-n           \n");
    printf("\n======================================\n");
}

void s_hasil(int Sn,int suku1,int suku2)
{
    system("cls");
    printf("\n=====================================");
    printf("\n [-1-] Jumlah Suku ke-%d adalah %d ",suku1,Sn);
    printf("\n [-2-] Suku ke-%d adalah %d ",suku2,Un);
    printf("\n=====================================\n");
    getchar();   
}

void s_error()
{
    system("cls");
    printf("\n====================================");
    printf("\n Tidak Dapat Diproses Karena Jumlah ");
    printf("\n Bilangan Lebih Kecil Dari Suku     ");
    printf("\n Yang Dicari.....                   ");
    printf("\n====================================\n");
    getchar();
}

void s_reset()
{
    total=counter=Un=0;
}