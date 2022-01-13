#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int angka;
    struct Node *leftChild;
    struct Node *rightChild;

}node;

//  Prototipe Fungsi dan Prosedur
    void insertTree();
    void lihatTree();
    void cerminTree();

node *root,*baru,*tmp,*sekarang,*patokan;

int main()
{   
    //  Variabel
        int jumlah,nilai; 
        root= NULL;

    printf("Masukan Jumlah Tree : ");
    scanf("%d",&jumlah);
    getchar();

    for(int i=0;i<jumlah;i++){
        printf("Bilangan ke [%d] : ",i);
        scanf("%d",&nilai);
        getchar();

        //  Memasukan Data
            insertTree(nilai);
    }

    system("cls");
    printf("\nLintasan Tree : ");
    lihatTree(root);

    printf("\nLintasan Cermin : ");
    cerminTree(root);
    lihatTree(root);

}

void insertTree(int data) 
{   
    baru=(node*)malloc(sizeof(node));
    baru->angka=data;
    baru->leftChild=NULL;
    baru->rightChild=NULL;

    if(root==NULL)
        root=baru;
    else{
        sekarang=root;
        patokan=NULL;

        while (1)
        {
            patokan=sekarang;

            //  Pergi Ke Kiri
                if(data < patokan->angka)
                {
                    sekarang=sekarang->leftChild;
                    if(sekarang==NULL){
                        patokan->leftChild=baru;
                        return;
                    }
                }

            //  Pergi Ke Kanan
                else
                {
                    sekarang=sekarang->rightChild;
                    if(sekarang==NULL){
                        patokan->rightChild=baru;
                        return;
                    }
                }
        }
        
    }

}

void lihatTree(node *root)
{   
    if(root!=NULL){
        lihatTree(root->leftChild);
        lihatTree(root->rightChild);
        printf("%d ",root->angka);
    }
}

void cerminTree(node *root)
{
    if(root!=NULL){
        cerminTree(root->leftChild);
        cerminTree(root->rightChild);
        node *temp=root->leftChild;
        root->leftChild=root->rightChild;
        root->rightChild=temp;
    }

    // if(root!=NULL){
    //     lihatTree(root->rightChild);
    //     lihatTree(root->leftChild);
    //     printf("%d ",root->angka);
    // }
}