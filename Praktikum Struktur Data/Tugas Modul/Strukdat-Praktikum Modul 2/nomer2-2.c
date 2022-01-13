#include <stdio.h>
#include <stdlib.h>

// Prototipe
void tambah_data();
void tampilkan_data();

typedef struct Data
{
    char nama[20];
    struct Data *next;
    struct Data *prev;

}data;

//Deklarasi Variabel Struct
data *head,*tail;
data *baru;
data *temp1;

int main()
{
    head = NULL;
    tail = NULL;

    // Fungsi
    tambah_data();
}

void tambah_data()
{   
    int count;

    printf ("Masukan Jumlah Data Yang Ingin Dimasukan : ");
    scanf ("%d",&count);
    getchar();

    // Alokasi Struct Dinamis
    for (int i=0;i<count;i++){
        
        baru= (data*)malloc(sizeof(data));

        printf ("Masukan nama : ");
        scanf ("%[^\n]",&baru->nama);
        getchar();

        if(head==NULL){   
            baru->next= baru->prev = baru;
            head=baru;
        }
        
        // Melacak dan Menandai Lokasi Node Treakhir
        tail = head->prev;
        baru->next=head;
        head->prev=baru;
        baru->prev=tail;
        tail->next=baru;
    }

    tampilkan_data(count);
}

void tampilkan_data(int x)
{   
    int cek=0;

    // 2 Dari Depan
    temp1 = head;
    tail=head->next->next;

    while (temp1!=NULL)
    {   
        if(temp1!=tail)
            printf("%s ",temp1->nama);
        else
            break;

        temp1 = temp1->next;
    }

    // Sisanya belakang
    tail = head->next;
    temp1 = head->prev;

    while (temp1!=NULL)
    {   
        if (temp1!=tail)
            printf ("%s ",temp1->nama);
        else
            break;

        temp1= temp1->prev;
    }
}