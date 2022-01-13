#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

/*  RULES PROGRAM by NGAKAN PUTU WIDYASPRANA

    Aturan :
    [1] Masukan ID User Dengan Bentuk Berikut 
        tahun-3 Digit Kode perusahaan-3 digit nomer
        ex :
        2020-DGF-001

    [2] Nilai Kode Hanya Diperbolehkan 1-5
        Jika tidak program akan mengalami error.

    [3] Jika ingin melebihi 5 maka ganti nilai MAX
        dengan yang diinginkan.
        
*/

typedef struct Database
{
    char username[255];
    char password[255];
    char id[255];

}node;

/* Prototipe Prosedur dan Fungsi */
    
    //  Prosedur
        void login_Page();
        void signUp_Page();
        void insertHash();
        void enkripsiPass();
        void display();
        void landingPage();

    //  Fungsi
        int cekHash();
        int idHash();
        int cekInputHash();
        int cekElementHash();

/*        Global Variabel        */
         node *arrayStandar[MAX];
         node *newData; 

int main()
{   
    //  Variabel 
        int pilihan;

    while(1)
    {   
        system("cls");
        printf("[1] Login \n");
        printf("[2] Sign-Up \n");
        printf("[3] Display\n");
        printf("[4] Keluar\n\n");
        printf("Masukan Pilihan : ");
        scanf("%d",&pilihan);
        getchar();

        switch(pilihan)
        {
            case 1:
                login_Page();
                break;
            case 2:
                signUp_Page();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                system("cls");
                printf("\n =============================================== ");
                printf("\n --> Masukan Pilihan Sesuai Menu Program !!! <-- ");
                printf("\n =============================================== \n\n");
                system("pause");
        }
    }
}

/*
    PROSEDUR DAN FUNGSI
*/

int cekHash()
{   
    int i=0;

    while(i<MAX)
    {
        if(arrayStandar[i]!=NULL)
            i++;
        else
            return 1;
    }
}

int idHash(char id[])
{   
    //  Variabel
        char temp[3];
        int j=0;

    for (int i =strlen(id)-3;i<strlen(id);i++)
    {
        temp[j]=id[i];
        j++;
    }

    int val=atoi(temp);
    return val;
}

int cekInputHash(char username[], char password[], char id[])
{   
    int tempUser,tempPass,tempId;
    int keyPegawai=idHash(id)%MAX;

    if(arrayStandar[keyPegawai]!=NULL){
        tempUser = strcmp(username,arrayStandar[keyPegawai]->username);
        enkripsiPass(password,0xad6b21);
        tempPass = strcmp(password,arrayStandar[keyPegawai]->password);
        tempId = strcmp(id,arrayStandar[keyPegawai]->id);

        if(tempUser==0 && tempPass==0 && tempId==0)
            return 1;
        else
            return 2;
    }
}

int cekElementHash(char userBaru[],char idPegawai[])
{
    int i=0;

    while(i<MAX)
    {
        if(arrayStandar[i]==NULL)
            i++;
        else{
            int temp1 = strcmp(arrayStandar[i]->username,userBaru);
            int temp3 = strcmp(arrayStandar[i]->id,idPegawai);

            if(temp1 == 0 || temp3 == 0)
                return 1;
            i++;
        }   
    }
}

void login_Page()
{   
    //  Variabel Login Page
        char user[255];
        char pass[255];
        char id[255];
        int status =1;
        int pilihan;
        int cek;
  
    system("cls");
    printf("Username    : ");
    scanf("%[^\n]",&user);
    getchar();

    printf("Password    : ");
    scanf("%[^\n]",&pass);
    getchar();

    printf("No. Pegawai : ");
    scanf("%s",&id);
    getchar();

    cek = cekInputHash(user,pass,id);

    if(cek==1){
        landingPage();
    }else if(cek==2){
        printf("\nData yang anda masukan tidak sesuai pada database....");
        printf("\nSilahkan Periksa Kembali...");
        getchar();
    }else{
        printf("\nID Pegawai belum terdaftar silahkan Sign-Up dahulu....\n");
        printf("\nApakah Ingin Sign-Up ? ");
        printf("\n-> Ya [1] ");
        printf("\n-> Tidak [0] \n");
        printf("\nPilihan : ");
        scanf("%d",&pilihan);
        getchar();

        if(pilihan==1){
            signUp_Page();
        }
    }
}

void signUp_Page()
{
    //  Variabel SignUp Page
        char userBaru[255];
        char passBaru[255];
        char idPegawai[255];
        int pilihan;
    system("cls");
    if(cekHash()==1){
        printf("Masukan Username Baru    : ");
        scanf("%[^\n]",&userBaru);
        getchar();

        printf("Masukan Password Baru    : ");
        scanf("%[^\n]",&passBaru);
        getchar();

        enkripsiPass(passBaru,0xad6b21);

        printf("Masukan Nomer ID Pegawai : ");
        scanf("%s",&idPegawai);
        getchar();

        int cek = cekElementHash(userBaru,idPegawai);

        if(cek==1){
            printf("\nData Anda Sudah Terdaftar pada Database...");
            printf("\nSilahkan Bisa Melakukan Login..... \n");
            printf("\nApakah Ingin Direct Login ? ");
            printf("\n-> Ya [1] ");
            printf("\n-> Tidak [0] \n");
            printf("\nPilihan : ");
            scanf("%d",&pilihan);
            getchar();

            if(pilihan==1)
                login_Page();

        }else{
            insertHash(userBaru,passBaru,idPegawai);
        }

    }else{
        system("cls");
        printf("\n ======================================  ");
        printf("\n --> Slot Database Sedang Penuh.... <--  ");
        printf("\n --> Mohon Hubungi Customer Service <--  ");
        printf("\n ====================================== \n");
        system("pause");
    }
}

void insertHash(char userBaru[],char passBaru[],char idPegawai[])
{   
    int keyPegawai=idHash(idPegawai);

    newData=(node*)malloc(sizeof(node));
    strcpy(newData->username,userBaru);
    strcpy(newData->password,passBaru);
    strcpy(newData->id,idPegawai);

    int hashKey = keyPegawai%MAX;

    while(arrayStandar[hashKey]!=NULL){
        hashKey++;
        hashKey=hashKey%MAX;
    }
    arrayStandar[hashKey]=newData;
}

void enkripsiPass(char password[],unsigned int changer)
{
    unsigned int i;
    for(i=0;i<strlen(password);++i)
    {
        password[i] = password[i] - changer;
    }    
}

void display()
{  
   //   Variabel
        int i = 0;

    system("cls");
    printf("\nSlot Database : ");
    while(i<MAX)
    {   
        if(arrayStandar[i]!=NULL){
            printf("\n\n[%d] Username : %s ",i+1,arrayStandar[i]->username);
            printf("\n    Pasword  : %s ",arrayStandar[i]->password);
            printf("\n    ID Kerja : %s ",arrayStandar[i]->id);
        }else{
            printf("\n\n[.] NULL");
        }
        i++;
    }
    printf("\n\n");
    system("pause");
}

void landingPage()
{   
    system("cls");
    printf("\n ==================================================================== ");
    printf("\n|                                                                    |");
    printf("\n|                  SELAMAT DATANG PADA LANDING PAGE                  |");
    printf("\n|                                                                    |");
    printf("\n ==================================================================== \n\n");
    system("pause");
}