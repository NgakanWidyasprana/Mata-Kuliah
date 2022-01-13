#include <stdio.h>


typedef struct data
{
    char nama_siswa[20];
    int nomerinduk_siswa;
    char kelas_siswa;

}data_siswa;

//Struct dengan sebuah array
data_siswa baru[1];

int main()
{   
    for(int i=0;i<3;i++){
        printf ("\nMasukan Nama Lengkap : ");
        scanf ("%[^\n]",&baru[i].nama_siswa);
        getchar();

        printf ("\nMasukan Nomer Induk : ");
        scanf ("%d",&baru[i].nomerinduk_siswa);
        getchar();

        printf ("\nMasukan Kelas : ");
        scanf ("%c",&baru[i].kelas_siswa);
        getchar();
    }

    // Display
    printf ("\n\n Data Keseluruhan Siswa \n\n");

    for (int j=0;j<3;j++){
        printf ("\n\nNama : %s ",baru[j].nama_siswa);
        printf ("\nNIS : %d ",baru[j].nomerinduk_siswa);
        printf ("\nKelas : %c ",baru[j].kelas_siswa);
    }
}