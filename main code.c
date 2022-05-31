#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> //standard library
#include <string.h> //untuk strcmp dan strcopy
#include <conio.h>
#include <windows.h>

typedef struct {
  char id[20];
  char nama[50];
  char penerbit[30];
  char pengarang[30];
  int terjual;
  int jumlah;
  int harga;
}
dataBuku;
 
typedef struct snode_t {
    dataBuku data;
    struct snode_t *next;
} SListNode;

typedef struct slist_t {
    unsigned _size;
    SListNode *_head;
} SinglyList;


long penjualan = 0;
dataBuku book[30];
  
#include "Fungsi Umum.h"
#include "Buku.h"


int main() {
  int i, x;
  long penjualan = 0;
  dataBuku book[30];

  for (i = 0; i < 30; i++) {
    strcpy(book[i].id, "");
    strcpy(book[i].nama, "");
    strcpy(book[i].penerbit, "");
    strcpy(book[i].pengarang, "");
    book[i].harga = 0;
    book[i].jumlah = 0;
  }
  system("cls");
  system("Color 02");
  printf("\n\n\n\n\n\n\n");
  printf("\n\t\t\t\t\t=========================================="); //mencetak tampilan awal program
  printf("\n\t\t\t\t\t\t        Stok Buku\t\t");
  printf("\n\t\t\t\t\t\t     Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t      Diprogram oleh:\t\t\n");
  printf("\n\t\t\t\t\t\t  Raden Muhammad Adib Haryo\t\t\n\t\t\t                         Raizha Rayhananta Prayoga\t\t\n\t\t\t                          Raihan Fakhar Arifin\n");
  printf("\n\t\t\t\t\t------------------------------------------");
  printf("\n\t\t\t\t\t       Tekan 'ENTER' untuk memulai\n");
  getch();

  system("cls");
  printf("\t\t");
  printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLoading"); // untuk mencetak halaman loading
  printf("\n\n\t\t\t\t      ");
  int n=3; // input untuk animasi laoding
  loading(n);
  menu(book);
  return 0;
}
int loading(int n){

	if(n>0){
		system ("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Tunggu Beberapa saat (%d) \t\t\n",n);
  		printf("\n\n\t\t\t\t      ");
  		for (int i = 0; i < 43; i++) { //for loop untuk mencetak animasi loading
    		printf(".");
    		Sleep(n);
		}	
		return n - loading(n-1);
	}
	else if (n==0){
		return n;
	}
}



