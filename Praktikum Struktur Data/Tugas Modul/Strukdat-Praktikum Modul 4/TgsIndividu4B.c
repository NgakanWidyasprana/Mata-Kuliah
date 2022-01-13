#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//PROGRAM ANTRIAN VAKSIN//

struct queueVaksin
{
    int nomorAntrian;
    char namaPasien[10];
    struct queueVaksin *next;
};

struct queueVaksin *head, *temp, *iniDataku, *bantu;
int nomor= 0;

void menuPasien(){
    printf("================================\n");
    printf("       MENU PASIEN VAKSIN       \n");
    printf("================================\n");
    printf("      [1] Tambah Pasien         \n");
    printf("      [2] Lihat Antrian Pasien  \n");
    printf("      [3] Lihat Pasien Tengah   \n");
    printf("      [4] Hapus Pasien Vaksin   \n");
    printf("      [5] Keluar                \n");
    printf("================================\n");
    printf("Masukkan Pilihannmu : ");
}

void tampilanAntrian(){
    temp= head;
    system("cls");
    printf("==============================\n");
    printf("        TAMPILAN ANTRIAN      \n");
    printf("==============================\n");
    printf("        [TEMPAT SUNTIK]       \n");

    while (temp!=NULL)
    {
        printf("Nomer Antrian : %d \n",temp->nomorAntrian);
        printf("Nama : %s ",temp->namaPasien);
        temp=temp->next;
    }
    getchar();
}

void enqueuePasien(){

    iniDataku = (struct queueVaksin*)malloc(sizeof(struct queueVaksin));
    
    printf ("Masukan Nama Lengkap : ");
    scanf ("%[^\n]",&iniDataku->namaPasien);
    getchar();

    iniDataku->nomorAntrian=nomor++;
    iniDataku->next=NULL;

    if (head==NULL){
        head=bantu=iniDataku;
    }else{
        bantu->next=iniDataku;
        bantu = bantu->next;
    }
}

int main()
{
    /*memanggil fungsi*/
    int pilihanMenu;
    char namaPasienVaksin[10];
    head = NULL;

    while (1)
    {
        //system("cls");
        menuPasien();
        scanf("%d", &pilihanMenu);
        getchar();

        switch (pilihanMenu)
        {
            case 1 :
                enqueuePasien();
                break;
            case 2 :
                tampilanAntrian();
                break;
            case 3 :
                system("cls");
                getchar();
                //dataTengah(bantuTengah,head);
                getchar();
                break;
            case 4 :
                system("cls");
                getchar();
                //dequeuePasien (head);
                getchar();
                break;
            case 5 :
                return 0;
            default:
                break;
        }
    }
}


