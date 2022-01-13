#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Prototipe Menu
    void s_menu();
    void s_exit();
    void s_error_switch();
    void s_error_queque();
    void s_penuh();
    void s_kosong();
    void s_clear();
    void s_proses();

//  Prototipe Antrian
    int isEmpty();
    int isFull();
    void enQueque();
    void deQueque();
    void listQueque();
    void clearQueque();
    void maxQueque();

typedef struct Data{
    char nama[20];
    int nomerAntrian;
    struct Data *next;
}data;

//  Variabel Global
    data *head,*tail,*baru,*bantu;
    int max=-1;
    int counter=0;
    int nomer=1;

int main()
{
    //  Variabel Main
        head=NULL;
    if(max==-1)
        maxQueque();
        
    s_menu();
}

/*
    Prosedur dan Fungsi Menu
*/
void s_menu()
{
    //  Variabel
        int status=1,pilihan;

    while(status)
    {   
        ULANG:
        system("cls");
        printf("\n==============| ANTRIAN ANGKRINGAN BALI |=============  ");
        printf("\n==============|        E-Serving        |=============\n");
        printf("\n   [1] Masukan Data        ||    [2] Proses Antrian      ");
        printf("\n   [3] Lihat Antrian       ||    [4] Kosongkan Antrian   ");
        printf("\n   [5] Buat/Tambah Antrian ||    [6] Keluar Program    \n");
        printf("\n====================== by : Ngakan ===================  ");
        printf("\n\nMasukan Pilihan : ");
        scanf("%d",&pilihan);
        getchar();

        switch(pilihan)
        {
            case 1:
                enQueque();
                break;
            case 2:
                deQueque();
                break;
            case 3:
                listQueque();
                break;
            case 4:
                clearQueque();
                break;
            case 5:
                maxQueque();
                break;
            case 6:
                s_exit();
                status=0;
                break;
            default:
                s_error_switch();
                goto ULANG;
                break;
        }
    }
}

void s_exit()
{
    system("cls");
    printf("\n========================================  ");
    printf("\n        Aplikasi Berhasil Keluar          ");
    printf("\n        ------------------------          ");
    printf("\n            Terima Kasih :)               ");
    printf("\n========================================\n");
    getchar();
}

void s_error_switch()
{   
    system("cls");
    printf("\n=========================================  ");
    printf("\n Pilihan Tidak Tersedia, Silahkan Ulangi   ");
    printf("\n=========================================\n");
    getchar();
}

void s_error_queque()
{
    system("cls");
    printf ("\n===============================================  ");
    printf ("\n  Silahkan Buat Jumlah Antrian Terlebih Dahulu   ");
    printf ("\n===============================================\n");
    getchar();
}

void s_penuh()
{
    system("cls");
    printf ("\n============================================  ");
    printf ("\n Antrian Sedang Penuh, Mohon Untuk Menunggu   ");
    printf ("\n============================================\n");
    getchar();
}

void s_kosong()
{
    system("cls");
    printf ("\n============================================  ");
    printf ("\n       Antrian Saat Ini Sedang Kosong         ");
    printf ("\n============================================\n");
    getchar();
}

void s_clear()
{
    system("cls");
    printf ("\n===============================================  ");
    printf ("\n        Antrian Berhasil Dikosongkan             ");
    printf ("\n===============================================\n");
    getchar(); 
}

void s_proses()
{
    system("cls");
    printf ("\n==================================   ");
    printf ("\nDengan,                              ");
    printf ("\nNama Lengkap  : %s ",head->nama);
    printf ("\nNomer Antrian : %d ",head->nomerAntrian);
    printf ("\n----------------------------------   ");
    printf ("\n  Silahkan Menuju Ke Kasir Untuk    ");
    printf ("\n         Mengambil Pesanan          ");
    printf ("\n================================== \n");
    getchar(); 
}

/*
    Prosedur dan Fungsi Antrian
*/
int isEmpty()
{   
    //bantu=head;

    if(max==-1)
        return -1;
    else if(head==NULL)
        return 0;
}

int isFull()
{
    //  variabel
        int i=0;
        bantu=head;

    while (bantu!=NULL)
    {  
        bantu=bantu->next;
        i++;
    }
    return i; 
}

void enQueque()
{
    system("cls");

    //  Alokasi Memori Dinamis
        baru=(data*)malloc(sizeof(data));

    //  Variabel
        char nm[20];

    if (isEmpty()==-1){
        s_error_queque();
    }else{
        printf("\nJumlah Antrian : %d ",max);
        printf("\nTempat Kosong  : %d \n\n",counter);

        if(isFull()<max){
            printf("  --> Masukan Nama Lengkap  : ");
            scanf("%[^\n]",&nm);
            getchar();

            strcpy(baru->nama,nm);
            baru->nomerAntrian=nomer++;

            baru->next=NULL;

            if(head==NULL){
                head=tail=baru;
            }else{
                tail->next=baru;
                tail=baru;
            }                
            counter--;
        }else{
            s_penuh();
        }
    }
}

// void enQueque()
// {   
//     system("cls");

//     //  Alokasi Memori Dinamis
//         baru=(data*)malloc(sizeof(data));

//     if (isEmpty()==-1){
//         s_error_queque();
//     }else{
//         printf ("\nJumlah Antrian : %d",max);
//         printf ("\nTempat Kosong  : %d\n\n",counter);

//         if(isFull()<max){
//             ULANG:
//             printf("--> Masukan Nama Lengkap  : ");
//             scanf("%[^\n]",&baru->nama);
//             getchar();

//             printf("--> Masukan Nomer Antrian : ");
//             scanf ("%d",&baru->nomerAntrian);
//             getchar();
            
//             baru->next = NULL;

//             if(head==NULL){
//                 head=tail=baru;
//             }else{
//                 tail->next=baru;
//                 tail=baru;
//             }
//             counter--;
//         }else{
//             s_penuh();
//         }
//     }
// }

void deQueque()
{   
    //  Variabel
        bantu=head;

    if(isEmpty()==-1){
        s_error_queque();
    }else if(isEmpty()==0){
        s_kosong();
    }else{
        s_proses();
        head=head->next;
        free(bantu);
        counter++;
    }
}

void listQueque()
{
    system("cls");

    //  Variabel
        bantu=head;

    if(isEmpty()==-1){
        s_error_queque();
    }else{
        if(isEmpty()==0){
            s_kosong();
        }else{
            printf("[-] Daftar Antrian Pelanggan : \n");

            while(bantu!=NULL)
            {
                printf("\n    --> %s / %d ",bantu->nama,bantu->nomerAntrian);
                bantu=bantu->next;
            }
            getchar();
        }
    }
}

void clearQueque()
{   
    if(isEmpty()==-1){
        s_error_queque();
    }else if(isEmpty()==0){
        s_kosong();
    }else{
        while(head!=NULL)
        {   
            if(head=tail)
                tail=tail->next;

            bantu=head;
            head=head->next;
            free(bantu);
        }
        s_clear();
        max=-1;
        counter=0;
        nomer=1;
    }
}

void maxQueque()
{   
    system("cls");
    
    //  variabel
        int tambahan;

    if(max==-1){
        printf("\n +-----------------------------------+");
        printf("\n |  Masukan Jumlah Antrian Hari Ini  |");
        printf("\n +-----------------------------------+");
        printf("\n\n Jumlah Antrian  : ");
        scanf ("%d",&max);
        getchar();
        counter=max;
    }else{
        printf("\n +-----------------------------------+");
        printf("\n |  Masukan Jumlah Tambahan Antrian  |");
        printf("\n +-----------------------------------+");
        printf("\n\n Tambahan Antrian : ");
        scanf ("%d",&tambahan);
        getchar();
        max= max +tambahan;
        counter = counter+tambahan;
    }
}