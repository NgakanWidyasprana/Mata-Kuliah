#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  Prototipe Prosedur
    void startArray();
    void outputArray();
    void searchingArray(char start[],char temp);

int main()
{
    char vokal[5] = "aiueo";
    char konsonan[20]= "bcdfghjklmnpqrstvwyz";
    char num[10]= "0123456789";
    char array[10];
    char findChar;
    
    system("cls");
    printf("Masukkan Inputan : ");
    scanf("%[^\n]",&array);
    getchar();
    
    printf("Masukan Huruf Yang Dicari : ");
    scanf("%c",&findChar);
    getchar();
    
    //  Prosedur
        system("cls");
        startArray(array);
        outputArray(array,vokal,konsonan,num);
        searchingArray(array,findChar);
    
    printf("\n");
    return 0;
}

void searchingArray(char start[],char temp)
{      
    int flag=0;
    for(int i=0;i<strlen(start);i++){
        if(tolower(start[i])==tolower(temp)){
            printf("\n\n[ Karakter %c Ditemukan pada %s ]",temp,start);
            flag=1;
            break;
        }
    }

    if(flag==0)
        printf("\n\n[ Maaf Karakter %c Tidak Ditemukan.... ]",temp);
}

void startArray(char start[])
{
    printf("Array Asal : %s \n",start);
}

void outputArray(char array[], char vokal[],char konsonan[],char num[])
{   
    int jumlahVokal=0,arrVokal[10];
    int jumlahKonsonan=0,arrKonsonan[10];
    int jumlahNumerik=0,arrNumerik[10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (tolower(array[i])==tolower(vokal[j]))
            {
                arrVokal[jumlahVokal]=array[i];
                jumlahVokal++;
            }
        }

        for(int j=0;j< 20;j++)
        {
            if(tolower(array[i])==tolower(konsonan[j]) && tolower(array[i])!= ' ')
            {
                arrKonsonan[jumlahKonsonan]=array[i];
                jumlahKonsonan++;
            }
        }

        for(int j=0;j<10;j++)
        {
            if(array[i]==num[j])
            {
                arrNumerik[jumlahNumerik]=array[i];
                jumlahNumerik++;
            }
        }
    }
    
    printf("\nJumlah Vokal %d   : ", jumlahVokal);
    for (int i = 0; i < jumlahVokal; i++)
    {
        printf("%c", arrVokal[i]);
    }

    printf("\nJumlah Konsonan %d : ",jumlahKonsonan);
    for(int w=0;w<jumlahKonsonan;w++)
    {
        printf("%c",arrKonsonan[w]);
    }

    printf("\nJumlah Numerik %d  : ",jumlahNumerik);
    for(int z=0;z<jumlahNumerik;z++)
    {
        printf("%c",arrNumerik[z]);
    }

}