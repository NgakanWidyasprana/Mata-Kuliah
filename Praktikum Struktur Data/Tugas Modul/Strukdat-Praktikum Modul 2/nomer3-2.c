#include <stdio.h>
#include <stdlib.h>

// Prototipe Fungsi Utama
void tambahBuku();
void lihatBuku();
void lihatTengah();
void hapusBuku();
// Prototipe Fungsi Bantuan
int pinPosisi();

typedef struct Data
{
    char kode[20];
    char judulBuku[20];
    char penulisBuku[20];
    char penerbitBuku[20];
    struct Data *next;

}data;

data *head;
data *baru;
data *temp,*bantu;

int main()
{   
    // Mengosongkan head;
    head=NULL;

    // Variabel Menu
    int status=1,pilihan;

    while(status)
    {   
        system ("cls");
        printf ("\n====================[ MENU ]====================\n");
        printf ("\n [1] Tambah Buku       || [4] Hapus Data          ");
        printf ("\n [2] Lihat Data        || [5] Keluar              ");
        printf ("\n [3] Lihat Data Tengah ||                        \n");
        printf ("\n================================================\n");
        printf ("\n Masukan Pilihan Anda : ");
        scanf ("%d",&pilihan);
        getchar();

        switch(pilihan)
        {
            case 1:
                tambahBuku();
                break;
            case 2:
                lihatBuku();
                break;
            case 3:
                lihatTengah();
                break;
            case 4:
                hapusBuku();
                break;
            case 5:
                return 0;
                break;
            default:
                printf ("\n Pilihan tidak tersedia, silahkan ulangi...");
                getchar();
        }

        system("cls");
        printf ("Apakah ingin kembali ke menu utama ?\n");
        printf ("\n--> [:] Tekan Apa Saja untuk melanjutkan...");
        printf ("\n--> [:] tekan 0 Untuk berhenti/keluar...");
        printf ("\n\nMasukan Pilihan Anda : ");
        scanf  ("%d",&status);

        getchar();
    }
}

void tambahBuku()
{
    system("cls");

    baru =(data*)malloc(sizeof(data));

    printf ("=================================\n");

    printf ("\nMasukan Judul Buku : ");
    scanf  ("%[^\n]",&baru->judulBuku);
    getchar();

    printf ("Masukan Penulis Buku : ");
    scanf ("%[^\n]",&baru->penulisBuku);
    getchar();

    printf ("Masukan Penerbit Buku : ");
    scanf ("%[^\n]",&baru->penerbitBuku);
    getchar();

    printf ("Masukan Kode Buku (ISBN): ");
    scanf ("%[^\n]",&baru->kode);
    getchar();

    printf ("\n=================================");

    baru->next=head;
    head=baru;
}

void lihatBuku()
{     
    system("cls");
    temp = head;

    if (head!=NULL){
        printf ("\n====================[ Data Perpustakaan ]====================\n\n");

        while(temp!=NULL)
        {
            printf (" [%d]  Kode Buku     : %s\n",i++,temp->kode);
            printf ("      Judul Buku    : %s\n",temp->judulBuku);
            printf ("      Penulis Buku  : %s\n",temp->penulisBuku);
            printf ("      Penerbit Buku : %s\n",temp->penerbitBuku);
            printf ("\n\n");

            temp = temp->next;
        }
        printf ("\n==================[copy right : ngakanptwp]==================\n\n");
        getchar();
    }else{
        printf ("\n====================[ Data Perpustakaan ]====================\n\n");
        printf ("\n                [KOSONG SILAHKAN ISI DAHULU]                   \n");
        printf ("\n==================[copy right : ngakanptwp]==================\n\n");
    }
}

int pinPosisi(int x)
{   
    int total=x;
    int i=0;
    temp=head;
    
    while (temp!=NULL)
    {
        temp=temp->next;
        i++;
    }

    for(int x=0;x<=i;x++){
        total=total+x;
    }

    if(i%2==0)
        total=(total/i)+1;
    else
        total=total/i;

    return (total);
}

void lihatTengah()
{   
    int x=0;

    if(head!=NULL){ 
        int final= pinPosisi(x);
    
        temp = head;

        for (int y=0;y<final;y++){
         
            if (y==final-1){
                printf ("\n         Data Ditengah        ");
                printf ("\n==============================");
                printf ("\nKode Buku     : %s",temp->kode);
                printf ("\nJudul Buku    : %s",temp->judulBuku);
                printf ("\nPenulis Buku  : %s",temp->penulisBuku);
                printf ("\nPenerbit Buku : %s",temp->penerbitBuku);
                printf ("\n==============================");
                getchar();
            }
            temp = temp->next;
        }
    }else{
        lihatBuku();
    }
}

void hapusBuku()
{
    temp=head;

    if (head!=NULL){
        while(temp!=NULL)
        {   
            if(temp->next==NULL && temp==head){
                printf ("\n         Data Dihapus       ");
                printf ("\n==============================");
                printf ("\nKode Buku     : %s",temp->kode);
                printf ("\nJudul Buku    : %s",temp->judulBuku);
                printf ("\nPenulis Buku  : %s",temp->penulisBuku);
                printf ("\nPenerbit Buku : %s",temp->penerbitBuku);
                printf ("\n==============================");
                getchar();

                head=NULL;
                free(temp);
            }else if (temp->next == NULL && temp !=head){
                printf ("\n         Data Dihapus       ");
                printf ("\n==============================");
                printf ("\nKode Buku     : %s",temp->kode);
                printf ("\nJudul Buku    : %s",temp->judulBuku);
                printf ("\nPenulis Buku  : %s",temp->penulisBuku);
                printf ("\nPenerbit Buku : %s",temp->penerbitBuku);
                printf ("\n==============================");
                getchar();

                bantu->next=NULL;
                free(temp); 
            }
            bantu=temp;
            temp=temp->next;
        }
    }else{
        lihatBuku();
    }
}