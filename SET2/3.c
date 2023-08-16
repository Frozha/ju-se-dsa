#include"doublelnkdlst.c"

int main(){
    //head creation
    node *head = (node*)calloc(1,sizeof(node));
    head->value = 1;
    head->previous = NULL;
    head->next = NULL;
    
    //inserts node at index
    insert(head,1,2);
    insert(head,2,3);
    insert(head,3,4);
    printf("linked list after insertion : \n");
    printinfo(head);

    //delete at index
    pop(head,1);
    head = pop(head,0);
    printf("linked list after deletion : \n");
    printinfo(head);
    
    //number of elements in list
    printf("number of elements in linked list : %d\n",size_ll(head));
    printf("printing in reverse : ");
    rev_print_ll(head);
   
    //reverse linked list
    printf("\nreversing linked list : ");
    head = reverse(head);
    printinfo(head);

    delete_ll(head);
}
