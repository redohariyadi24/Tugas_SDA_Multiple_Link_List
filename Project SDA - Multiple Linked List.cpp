#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
       char type[10];
       int qty;
       struct data *next;
       struct data *prev;
}*curr, *head, *tail;

void add_depan(char type[], int qty)
{
       curr = (struct data*)malloc(sizeof(struct data));
       strcpy(curr->type, type);
       curr->qty = qty;

       if(head == NULL) 
       {
              head = tail = curr;
       }
       else
       {
              curr->next = head;
              head->prev = curr;
              head = curr;
       }
       tail->next = NULL;
       head->prev = NULL;
}

int view()
{
       int idx = 0;
       if(head == NULL)
       {
       	printf("List Kosong\n");
	   }
       else if(head != NULL) 
       {
              curr = head;
              while(curr != NULL)
              {
                     printf(curr->type);
                     curr = curr->next;
                     idx++;
              }
       }
       
       return idx;
}

void take_order()
{
       if(curr == head)
       {
              head = head->next;
              free(curr);
              if(head != NULL)
              {
                     head->prev = NULL;
              }
       }
       else if(curr == tail)
       {
              curr = tail;
              tail = tail->prev;
              free(curr);
              tail->next = NULL;
       }
       else
       {
              struct data *temp;
              temp = head;
              while(temp->next != curr)
              {
                     temp = temp->next;
              }

              curr->next->prev = curr->prev;
              temp->next = curr->next;
              free(curr);
       }
}

int main()
{
       int pilih;

       do
       {
              do
              {
                     system("cls");
                     puts(" Multiple Link list");
                     puts(" -----------------------");
                     puts(" 1. Lihat List");
                     puts(" 2. Tambah data");
                     puts(" 3. Hapus data");
                     puts(" 4. Keluar");
                     printf(" >> Masukkan pilihan: ");
                     scanf("%d", &pilih); fflush(stdin);
              }
              while(pilih < 1 || pilih > 4);
             
              system("cls");

              switch(pilih)
              {
              case 1:
                     //menampilkan data
                     view();
                     break;

              case 2:
                     char type[10];
                     int qty;

                     //add data dari depan
                     do
                     {
                           printf("Masukkan data yang ingin ditambahkan: ");
                           scanf("%[^\n]", type); fflush(stdin);
                     }
                     while(strlen(type) < 3 || strlen(type) > 30);

                     printf("Sukses ditambahkan");
                     add_depan(type, qty);
                     getchar();
                     break;

              case 3:
                     int posisi;
                     int total = view();

                     do
                     {
                           printf("Masukan data yang diinginkan: ", total);
                           scanf("%d", &posisi); fflush(stdin);
                     }
                     while(posisi < 1 || posisi > total);

                     curr = head;
                     for(int i = 1 ; i < posisi ; i++)
                     {
                           curr = curr->next;
                     }

                     take_order();
                     printf("Sukses menghapus");
                     getchar();
                     break;
              }
       }while(pilih != 4);
       return 0;
}
