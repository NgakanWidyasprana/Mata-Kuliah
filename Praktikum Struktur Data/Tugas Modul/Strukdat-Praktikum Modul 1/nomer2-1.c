#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Deklarasi fungsi yang digunakan
void cari_huruf();

int main()
{
    char kata[20];
    char huruf;

    printf ("Masukan Kata : ");
    scanf ("%[^\n]",&kata);
    getchar();

    printf ("Masukan huruf yang dicari : ");
    scanf ("%c",&huruf);
    getchar();

    cari_huruf(kata,&huruf);
}

// Fungsi mencari huruf tanpa case sensitive
void cari_huruf(char *kata,char *pointer_huruf)
{  
    for (int i=0;i<strlen(kata);i++){
        if(toupper(*pointer_huruf)==toupper(kata[i])){
            printf ("\nKata %c atau %c ditemukan pada kata %s...\n",tolower(*pointer_huruf),toupper(*pointer_huruf),kata);
            break;
        }
    }
}
