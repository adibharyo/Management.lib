
void menu(dataBuku book[]) {
  int pilihMenu;
  long penjualan = 0;
  system("cls");
  do {
    printf("\n\t\t\t\t\t=========================================="); //Mencetak menu
    printf("\n\t\t\t\t\t\t\t    MENU\t\t");
    printf("\n\t\t\t\t\t  		Toko Buku Hebat\t\t");
    printf("\n\t\t\t\t\tJalan Raya Pantura No. 19, Tegal, Jawa Tengah\t\t");
    printf("\n\t\t\t\t\t==========================================");
    printf("\n\n");
    printf("\t\t\t\t\t\t[1] Input Buku\n");
    printf("\t\t\t\t\t\t[2] Print Indeks\n");
    printf("\t\t\t\t\t\t[3] Cari Buku\n");
    printf("\t\t\t\t\t\t[4] Edit Indeks\n");
    printf("\t\t\t\t\t\t[5] Hapus Buku\n");
    printf("\t\t\t\t\t\t[6] Pencatatan Penjualan\n");
    printf("\t\t\t\t\t\t[7] Total Keuntungan\n");
    printf("\t\t\t\t\t\t[8] Best Seller\n");
    printf("\t\t\t\t\t\t[9] Keluar\n");
    printf("\n\t\t\t\t\t------------------------------------------\n");
    printf("\n\t\t\t\t\tPilihanmu --> ");
    scanf("%d", & pilihMenu);
    if (pilihMenu < 1 || pilihMenu > 8) {
      puts("Masukkan angka sesuai menu");
    }
    switch (pilihMenu) {
    case 1:
      inputBuku(book, &penjualan);
      break;
    case 2:
      printBuku(book);
      break;
    case 3:
      cariBuku(book);
      break;
    case 4:
      editBuku(book);
      break;
    case 5:
      delBuku(book);
      break;
    case 6:
      jual(book, & penjualan);
      break;
    case 7:
      penghasilan(penjualan);
      break;
    case 8:
      sortingBuku(book);
      break;
    }
  }
  while (pilihMenu != 9);
  system("cls");
  printf("\n\n\n\n\n\n\n\n\n");
  printf("\t\t\t\t\t  Thankyou for using this program");
  printf("\n\n\n\n\n\n\n\n\n");
}
void input(int * p) {
  do {
    scanf("%d", p);
    if ( * p < 0)
      printf("\t\t\t\t\t  Input tidak boleh negatif\n");
  } while ( * p < 0);
}
void keluar() {
  printf("\t\t\t\t\t  Press any key to continue.....");
  getch();
  system("cls");
}
