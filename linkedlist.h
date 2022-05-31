void slist_init(SinglyList *list) 
{
    list->_head = NULL;
    list->_size = 0;
}

bool slist_isEmpty(SinglyList *list) {
    return (list->_head == NULL);
}

void slist_pushBack(SinglyList *list, dataBuku value)
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;
        newNode->next = NULL;
        
        if (slist_isEmpty(list)) 
            list->_head = newNode;
        else {
            SListNode *temp = list->_head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void slist_pushFront(SinglyList *list, dataBuku value) 
{
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode));
    if (newNode) {
        list->_size++;
        newNode->data = value;

        if (slist_isEmpty(list)) newNode->next = NULL;
        else newNode->next = list->_head;
        list->_head = newNode;
    }
}

void slist_insertAt(SinglyList *list, int index, dataBuku value)
{
    
    if (slist_isEmpty(list)) {
        slist_pushBack(list, value);
        return;    
    }
    else if (index == 0) {
        slist_pushFront(list, value); 
        return;
    }
    
    SListNode *newNode = (SListNode*) malloc(sizeof(SListNode)); 
    if (newNode) {
        SListNode *temp = list->_head;
        int _i = 0;
        while (temp->next != NULL && _i < index-1) {
            temp = temp->next;
            _i++;
        }
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        list->_size++;
    }
}

void slist_insert_sort_harga(SinglyList *list, dataBuku value)
{
    if (slist_isEmpty(list)) {
        slist_insertAt(list, 0, value);
        return;    
    }
    
    SListNode *temp = list->_head;
    int i=0;
    while (temp != NULL && value.harga > temp->data.harga) {
      i++;
      temp = temp->next;
    }
    
    slist_insertAt(list, i, value);
}

void slist_insert_sort_terjual(SinglyList *list, dataBuku value)
{
    if (slist_isEmpty(list)) {
        slist_insertAt(list, 0, value);
        return;    
    }
    
    SListNode *temp = list->_head;
    int i=0;
    while (temp != NULL && value.terjual < temp->data.terjual) {
      i++;
      temp = temp->next;
    }
    
    slist_insertAt(list, i, value);
}

void printList(SinglyList *list){
    if (!slist_isEmpty(list)) {
      SListNode *temp = list->_head;
      int i=0;
      for (int i=0; i<list->_size; i++){
        printf("\n\t\t\t\t\t==========================================\n\n");
        printf("\t\t\t\t\t  Buku %d\n\n", i+1);
        printf("\t\t\t\t\t  Kode Buku : %s\n  ", temp->data.id);
        printf("\t\t\t\t\t  Nama Buku : %s\n", temp->data.nama);
        printf("\t\t\t\t\t  Nama Pengarang : %s\n", temp->data.pengarang);		
        printf("\t\t\t\t\t  Nama Penerbit : %s\n", temp->data.penerbit);
        printf("\t\t\t\t\t  Jumlah Buku : %d\n", temp->data.jumlah);
        printf("\t\t\t\t\t  Harga Buku : %d\n", temp->data.harga);
        printf("\t\t\t\t\t  Jumlah Terjual : %d\n", temp->data.terjual);
        temp=temp->next;
      }
    }
}
