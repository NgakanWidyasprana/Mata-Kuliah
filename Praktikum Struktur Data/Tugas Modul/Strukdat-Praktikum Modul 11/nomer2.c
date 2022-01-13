#include <stdio.h>
#include <stdlib.h>

struct graph{int data;};
struct namaGraph{char nama[255];};

//  Prototipe
    void buatGraph();
    void cetakGraph();
    void cariMinimum();
    void s_selaInput();

//  Variabel Global
    int terkecil = 999,tempRow[255],tempCol[255],jumlah=0,counter;
    struct graph matriks[100][100];
    struct namaGraph namaMatriks[100];

int main()
{
    system("cls");
    printf("Masukkan berapa banyak data : ");
    scanf("%d",&jumlah);
    getchar();

    //  Prosedur
        buatGraph();
        cetakGraph();
        cariMinimum();

    // Cetak Nilai Minimum
    // Dan Semua Edge-nya
    printf("=========== by : Ngakan =============\n\n");
    printf(" [.] Nilai bobot terkecil adalah %d \n",terkecil);
    printf(" [.] Terletak Pada Edge : ");
    for(int i=0;i<counter;i++){
        printf("\n      %d. (%s - %s) ",i+1,namaMatriks[tempRow[i]].nama,namaMatriks[tempCol[i]].nama);
    }
}

void buatGraph()
{   
    printf("\n=============|  INPUT  |=============");
    printf("\n=============| MATRIKS |=============\n\n");
    for (int i = 0; i < jumlah; i++)
    {   
        printf("[->] Masukkan nama vertex [%d] : ",i);
        scanf("%s", &namaMatriks[i].nama);
        getchar();
        
    }
    s_selaInput();
    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < jumlah; j++)
        {   
            if(i==j)
                matriks[i][j].data=0;
            else{
                printf("[->] Masukan Bobot (%s,%s) : ",namaMatriks[i].nama,namaMatriks[j].nama);
                scanf("%d", &matriks[i][j].data);
                getchar();
            }
        }
    }    
}

void cetakGraph()
{   
    system("cls");
    printf("\n=============| MATRIKS |=============\n\n");
    for (int i = 0; i < jumlah; i++)
    {   
        if(i==0)
            printf("%9s|",namaMatriks[i].nama);
        else
            printf("%5s|",namaMatriks[i].nama);
    }
    printf("\n\n");
    for (int i = 0; i < jumlah; i++)
    {   
        printf("%3s|",namaMatriks[i].nama);
        for (int j = 0; j < jumlah; j++)
        {
            printf("%6d",matriks[i][j].data);
        }
        if(i<jumlah-1)
            printf("\n\n"); 
    }
}

void cariMinimum()
{
    printf("\n\n");
    for (int i = 0; i < jumlah; i++)
    {
        for (int j = 0; j < jumlah; j++)
        {
            if(matriks[i][j].data<terkecil && matriks[i][j].data!=0){
                terkecil=matriks[i][j].data;
            }
        } 
    }
    for (int w = 0; w < jumlah; w++)
    {
        for (int z = 0; z < jumlah; z++)
        {
            if(matriks[w][z].data!=0){
                if(terkecil==matriks[w][z].data){
                    tempRow[counter]=w;
                    tempCol[counter]=z;
                    counter++;
                }
            }
        }   
    }   
}

void s_selaInput()
{   
    system("cls");
    printf("(<>)\n\n");
        printf("     |----------------- ATURAN -----------------|    \n");
        printf("     |                                          |    \n");              
        printf("     | Masukan Nilai Bobot dari vertex A ke B   |    \n");
        printf("     | Sebagai contoh :                         |    \n");
        printf("     | Masukan Bobot (A,B) : 10                 |    \n");
        printf("     |                                          |    \n");
        printf("     |----------------- ATURAN -----------------|    \n");       
    printf("\n(<>)\n\n");
}