#include"lnkdlst.c"

int main(){
    //head creation
    node *head = make_node(1);
    
    //inserts node at index
    insert(head,1,2);
    insert(head,2,3);
    insert(head,3,4);
    printf("linked list after insertion : \n");
    printinfo(head);

    //delete at index
    pop(head,1);
    printf("linked list after deletion : \n");
    printinfo(head);
    
    //number of elements in list
    printf("number of elements in linked list : %d\n",size_ll(head));
    printf("printing in reverse : ");
    rev_print(head);
   
    //reverse linked list
    printf("\nreversing linked list : ");
    head = reverse(head);
    printinfo(head);

    delete_ll(head);
}	
