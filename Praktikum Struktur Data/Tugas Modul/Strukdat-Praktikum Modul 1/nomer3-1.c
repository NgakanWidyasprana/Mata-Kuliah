#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Deklarasi fungsi yang digunakan
int cari_huruf();

int main()
{
    char kata[30];
    char huruf;
    int cek;

    printf ("Masukan Kata : ");
    scanf ("%[^\n]",&kata);
    getchar();

    printf ("Masukan huruf yang dicari : ");
    scanf ("%c",&huruf);
    getchar();

    // Alokasi memori dinamis untuk inputan kata
    char *temp = (char *)malloc(strlen(kata));
    strcpy(temp,kata);

    // Statement ditemukan atau tidak
    cek=cari_huruf(temp,&huruf);

    if (cek>=1)
        printf ("\nKata %c atau %c ditemukan pada kata %s...\n",tolower(huruf),toupper(huruf),kata);
    else if (cek <1)
        printf ("\nKata tidak ditemukan...\n");

    free(temp);
}

// Fungsi mencari huruf tanpa case sensitive
int cari_huruf(char *kata,char *pointer_huruf)
{   
    int cek=0;

    for (int i=0;i<strlen(kata);i++){
        if(toupper(*pointer_huruf)==toupper(kata[i])){
            cek=cek+1;
        }else{
            cek=cek+0;
        }
    }

    return cek;
}
