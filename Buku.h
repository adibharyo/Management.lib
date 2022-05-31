#include "linkedlist.h"
void inputBuku(dataBuku book[], int *penjualan) {
  int sentinel;
  int i, j, x, cek;
  system("cls");

  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t  INPUT BUKU\t\t");
  printf("\n\t\t\t\t\t  		Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  printf("\n\t\t\t\t\t1.Masukkan jumlah buku yang ingin di input\n");
  printf("\n\t\t\t\t\t2.Masukkan kode buku yang ingin di input\n");
  printf("\n\t\t\t\t\t3.Mengisi kode buku beserta informasi sebanyak \n\t\t\t\t\t  jumlah buku yang ingin di input\n");
  printf("\n\t\t\t\t\t==========================================\n");	
  printf("\n\t\t\t\t\t  Berapa Buku yang ingin anda tambahkan? ");
  scanf("%d", & sentinel);
  printf("\t\t\t\t\t------------------------------------------\n");
  for (x = 0; x < 30; x++) {
    if (!strcmp(book[x].id, "")) {
      for (i = x; i < x + sentinel; i++) {
        int y = 0;
        while (y == 0) {
          int a = 0;
          printf("\t\t\t\t\t  Produk ke-%d\n", i + 1);
          printf("\t\t\t\t\t  Kode Buku : ");
          scanf(" %255[^\n]s", book[i].id); {
            for (j = 0; j < i; j++) {
              cek = strcmp(book[i].id, book[j].id);
              if (cek == 0) {
                printf("Kode sudah digunakan!\n");
                a = 1;
              }
            }
          }
          if (a != 1) {
            y = 1;
          }
        }
        fflush(stdin);
        printf("\t\t\t\t\t  Nama Buku : ");
        scanf(" %255[^\n]s", book[i].nama);
        fflush(stdin);
        printf("\t\t\t\t\t  Nama Penerbit: ");
        scanf(" %255[^\n]s", book[i].penerbit);
        fflush(stdin);
        printf("\t\t\t\t\t  Nama Pengarang: ");
        scanf(" %255[^\n]s", book[i].pengarang);
        fflush(stdin);
        printf("\t\t\t\t\t  Jumlah Stok Tersedia : ");
        input( & book[i].jumlah);
        printf("\t\t\t\t\t  Jumlah Buku Terjual : ");
        input( & book[i].terjual);
        printf("\t\t\t\t\t  Harga Buku : ");
        input( & book[i].harga);
        printf("\t\t\t\t\t------------------------------------------\n");
      	*penjualan = *penjualan + (book[i].harga * book[i].terjual);
	  }
      break;
    }
  }
  if(sentinel!=0){
  	printf("\n\t\t\t\t\t  Penambahan Produk Berhasil!\n");
  }
  keluar();
}

void printBuku (dataBuku book[]){
	system("cls");
	
	printf("\n\t\t\t\t\t==========================================");	
    printf("\n\t\t\t\t\t\t\t  PRINT INDEKS\t\t");
    printf("\n\t\t\t\t\t  	Toko Buku Hebat\t\t");
    printf("\n\t\t\t\t\t==========================================\n\n");
  	printf("\n\t\t\t\t\tFunction ini akan mengeprint seluruh \n\t\t\t\t\t informasi mengenai buku-buku yang sudah di input\n");
  
  SinglyList listBuku;
  slist_init(&listBuku);
  
	for (int i = 0; i < 30; i++){
		if(strcmp(book[i].id,"")){
      slist_insert_sort_harga(&listBuku, book[i]);
		}
	}
  printList(&listBuku);

			printf("\n\t\t\t\t\t==========================================\n\n");

	keluar();
}

void sortingBuku(dataBuku book[]) {
	system("cls");
  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\tBUKU BEST SELLER\t\t");
  printf("\n\t\t\t\t\t\t  	Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\tFunction ini akan mengurutkan buku berdasarkan \n\t\t\t\t\tjumlah buku yang terjual\n");
  
  SinglyList listBuku;
  slist_init(&listBuku);
  printf("\n\t\t\t\t\t------------------------------------------\n");
  printf("\n\t\t\t\t\tHasil sorting berdasarkan penjualan buku terbanyak : \n");
	for (int i = 0, k = 1; i < 30; i++){
		if(strcmp(book[i].id,"")){
      slist_insert_sort_terjual(&listBuku, book[i]);
		}
	}
  printList(&listBuku);
			printf("\n\t\t\t\t\t==========================================\n\n");

	keluar();
}

void cariBuku(dataBuku book[]) {
  int i, j, pilih,cek;
  char temp[10];
  system("cls");

  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t  CARI BUKU\t\t");
  printf("\n\t\t\t\t\t  	Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  printf("\n\t\t\t\t\t1.Function ini akan menampilkan informasi \n\t\t\t\t\t  buku berdasarkan kode yang diinput\n");
  printf("\t\t\t\t\t2.Ketik exit untuk kembali ke menu utama\n\n");
  printf("\t\t\t\t\tMasukkan kode buku yang anda cari: ");
  scanf(" %9[^\n]s", temp);
  fflush(stdin);
  cek=strcmp(temp, "exit");
  if(cek!=0){
	  for (i = 0; i < 30; i++) {
	    if (!strcmp(temp, book[i].id)) {
	      printf("\t\t\t\t\t  Buku ditemukan!\n");
	      printf("\n\t\t\t\t\t------------------------------------------\n");
	      printf("\t\t\t\t\t  Kode Buku : %s\n  ", book[i].id);
	      printf("\t\t\t\t\t  Nama Buku : %s\n", book[i].nama);
	      printf("\t\t\t\t\t  Nama Pengarang : %s\n", book[i].pengarang);
	      printf("\t\t\t\t\t  Nama Penerbit : %s\n", book[i].penerbit);
	      printf("\t\t\t\t\t  Jumlah Buku : %d\n", book[i].jumlah);
	      printf("\t\t\t\t\t  Harga Buku : %d\n", book[i].harga);
	      printf("\n\t\t\t\t\t------------------------------------------\n\n");
	      break;
	    }
	  }
  }

  if (i == 30)
    printf("\t\t\t\t\t  Kode tidak ditemukan!\n");
  keluar();
}

void editBuku(dataBuku book[]) {
  int i, j, pilih,cek;
  char temp[10];
  system("cls");

  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t  EDIT INDEKS\t\t");
  printf("\n\t\t\t\t\t  	Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  printf("\n\t\t\t\t\t1.Function ini memungkinkan pengguna mengubah \n\t\t\t\t\t  informasi dari buku yang telah tersimpan\n");
  printf("\t\t\t\t\t2.Ketik exit untuk kembali ke menu utama\n\n");
  printf("\t\t\t\t\tMasukkan kode buku yang ingin anda ubah: ");
  scanf(" %9[^\n]s", temp);
  fflush(stdin);
  cek=strcmp(temp, "exit");
  if(cek!=0){
	  for (i = 0; i < 30; i++) {
	    if (!strcmp(temp, book[i].id)) {
	      printf("\t\t\t\t\t  Buku ditemukan!\n");
	      printf("\t\t\t\t\t Pilih yang ingin anda ubah");
	      printf("\n\t\t\t\t\t  [1] Kode Buku ");
	      printf("\n\t\t\t\t\t  [2] Nama Buku ");
	      printf("\n\t\t\t\t\t  [3] Nama Penerbit ");
	      printf("\n\t\t\t\t\t  [4] Nama Pengarang ");
	      printf("\n\t\t\t\t\t  [5] Jumlah Stok Buku");
	      printf("\n\t\t\t\t\t  [6] Jumlah Buku Terjual");
	      printf("\n\t\t\t\t\t  [7] Harga Buku");
	      printf("\n\t\t\t\t\t->");
	      input( & pilih);
	      switch (pilih) {
	      case 1:
	        printf("\t\t\t\t\t  Masukkan kode buku baru: ");
	        scanf(" %255[^\n]s", book[i].id);
	        fflush(stdin);
	        break;
	      case 2:
	        printf("\t\t\t\t\t  Masukkan nama buku baru: ");
	        scanf(" %255[^\n]s", book[i].nama);
	        fflush(stdin);
	        break;
	      case 3:
	        printf("\t\t\t\t\t  Masukkan nama penerbit baru: ");
	        scanf(" %255[^\n]s", book[i].penerbit);
	        fflush(stdin);
	        break;
	      case 4:
	        printf("\t\t\t\t\t  Masukkan nama pengarang baru: ");
	        scanf(" %255[^\n]s", book[i].pengarang);
	        fflush(stdin);
	        break;
	      case 5:
	        printf("\t\t\t\t\t  Masukkan jumlah stok buku baru : ");
	        input( & book[i].jumlah);
	        break;
	      case 6:
	        printf("\t\t\t\t\t  Masukkan jumlah buku terjual yang baru : ");
	        input( & book[i].terjual);
	        break;
	      case 7:
	        printf("\t\t\t\t\t  Masukkan harga buku baru: ");
	        input( & book[i].harga);
	        break;
	      default:
	        printf("\t\t\t\t\t  Pilih angka sesuai menu\n");
	        break;
	      }
	      printf("\t\t\t\t\t  Produk berhasil diubah!\n");
	      break;
	    }
	 	 }
  }
  if (i == 30)
    printf("\t\t\t\t\t  Kode tidak ditemukan!\n");
  keluar();
}

void delBuku(dataBuku book[]) {
  int i, j,cek;
  char kode[50];
  system("cls");

  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t   HAPUS BUKU\t\t");
  printf("\n\t\t\t\t\t  		Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  
  printf("\n\t\t\t\t\t1.Function ini memungkinkan pengguna menghapus \n\t\t\t\t\t  buku dari database\n");
  printf("\t\t\t\t\t2.Ketik exit untuk kembali ke menu utama\n\n");
  printf("\t\t\t\t\tMasukkan kode produk yang ingin anda hapus: ");
  scanf(" %49[^\n]s", kode);
  cek=strcmp(kode, "exit");
  if(cek!=0){
	  for (i = 0; i < 30; i++) {
	    if (!strcmp(book[i].id, kode)) {
	      for (j = i; j < 29; j++) {
	        book[j] = book[j + 1];
	      }
	      strcpy(book[29].id, "");
	      strcpy(book[29].nama, "");
	      strcpy(book[29].pengarang, "");
	      strcpy(book[29].penerbit, "");
	      book[29].harga = 0;
	      book[29].jumlah = 0;
	      book[29].terjual = 0;
	
	      printf("\t\t\t\t\t  Produk berhasil dihapus!\n\n");
	      break;
	    }
	  }
  }
  
  if (i == 30)
  printf("\t\t\t\t\t  Kode tidak ditemukan!\n");
  keluar();
}

void jual(dataBuku book[], long *penjualan) {
  int i,cek;
  char temp[10];
  unsigned int beli;
  system("cls");

  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t   JUAL BUKU\t\t");
  printf("\n\t\t\t\t\t  		Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  printf("\n\t\t\t\t\t1.Function ini berguna untuk menghitung \n\t\t\t\t\t  keuntungan dari buku yang terjual\n");
  printf("\t\t\t\t\t2.Ketik exit untuk kembali ke menu utama\n\n");
  printf("\t\t\t\t\tMasukkan kode produk yang ingin anda jual: ");
  scanf(" %9[^\n]s", temp);
  fflush(stdin);
  cek=strcmp(temp, "exit");
  if (cek!=0){
	  for (i = 0; i < 30; i++) {
	    if (!strcmp(temp, book[i].id)) {
	      printf("\t\t\t\t\t  Produk ditemukan!\n");
	      printf("\t\t\t\t\t  Kode Buku : %s\n  ", book[i].id);
	      printf("\t\t\t\t\t  Nama Buku : %s\n", book[i].nama);
	      printf("\t\t\t\t\t  Nama Pengarang : %s\n", book[i].pengarang);
	      printf("\t\t\t\t\t  Nama Penerbit : %s\n", book[i].penerbit);
	      printf("\t\t\t\t\t  Jumlah Stok Buku : %d\n", book[i].jumlah);
	      printf("\t\t\t\t\t  Jumlah Buku Terjual : %d\n", book[i].terjual);
	      printf("\t\t\t\t\t  Harga Buku : %d\n", book[i].harga);
	      do {
	        printf("\t\t\t\t\t  Masukkan jumlah barang yang terjual: ");
	        scanf("%d", & beli);
	        if (beli > book[i].jumlah) {
	          printf("\t\t\t\t\t  Jumlah penjualan lebih banyak daripada jumlah barang. Tidak boleh!\n");
	        }
	      } while (beli > book[i].jumlah);
	
	      *penjualan = *penjualan + book[i].harga * beli;
	      book[i].jumlah -= beli;
	      book[i].terjual += beli;
	      printf("\t\t\t\t\t  Penjualan berhasil!\n");
	      break;
	     }
		}
  }
  if (i == 30)
    printf("\t\t\t\t\t  Kode tidak ditemukan!\n");
  keluar();
}

void penghasilan(long penjualan) {
	system("cls");
  printf("\n\t\t\t\t\t==========================================");
  printf("\n\t\t\t\t\t\t\t   TOTAL KEUNTUNGAN\t\t");
  printf("\n\t\t\t\t\t  		Toko Buku Hebat\t\t");
  printf("\n\t\t\t\t\t==========================================\n");
  printf("\n\n\n\n\n\n");
  printf("\t\t\t\t\t  Hasil penjualan yang didapatkan adalah: %ld\n", penjualan);
  printf("\n\n\n\n\n\n");
  keluar();
}
