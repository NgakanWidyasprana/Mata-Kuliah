#include <stdio.h>
#include <stdlib.h>

//Prototipe Fungsi
void tambah();
void display();

// Deklarasi struct
typedef struct DATA
{
    int angka;
    struct DATA *next;

}data;

// Deklarasi pointer struct
data *head;
data *baru;
data *cek;

int main()
{   
    // Mengosongkan Head
    head = NULL;

    // Variabel
    int x;

    //Terus meminta Inputan Hingga menekan ctrl+z
    // Karena merupakan EOF

    while (scanf("%d",&x)!=EOF)
    {
        tambah(x);
    }

    display();
}

void tambah(int tmp)
{   
    // Menambahkan dari depan
    
    baru = (data*)malloc(sizeof(data));

    baru->angka=tmp;
    baru->next=head;
    head=baru;
}

void display()
{   
    cek=head;
    printf ("Hasil : ");

    while(head!=NULL)
    {
        printf ("%d --> ",cek->angka);
        cek = cek->next;
    }
}