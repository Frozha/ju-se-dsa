#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    node* previous;
    node* next;
}node;

//c:part
int size_ll(node* head){
    node* current = head;
    int length=1;
    while (current->next!=NULL){
        current=current->next;
        length++;
    }
    return length;
}

void add_node(node* head, int val){
    //adds node to end
    node *current = head;
    //traverse linked list till null
    while(current->next!=NULL){
        current=current->next;
    }
    node *newnode =(node*)calloc(1,sizeof(node));
    newnode->value = val;
    current->next = newnode;
    newnode->previous = current;
    newnode ->next = NULL;
}

void printinfo(node *head){
    node *current = head;
    while(current!=NULL){
        printf("<%p|%d|%p>\t",current->previous,current->value,current->next);
        current=current->next;
    }
    printf("\n\n");
}

void print_ll(node *head){
    node *current = head;
    while(current!=NULL){
        printf("%d\t",current->value);
        current=current->next;
    }
    printf("\n");
}

//d:part
void rev_print_ll(node *head){
    node *current = head;
    while(current->next!=NULL){
        current=current->next;
        //takes to end
    }
    while(current!=NULL){
        printf("%d\t",current->value);
        current=current->previous;
    }
    printf("\n");
}

//a:part
void insert(node *head,int index,int value){
    node *current = head;
    for(int i=0;i<index-1;i++){
        if(current!=NULL){
            current=current->next;
        }
        else{
            printf("out of bounds");
        }
    }
    node *newnode = (node*)calloc(1,sizeof(node));
    newnode->value=value;
    newnode->previous = current;
    newnode->next = current->next;
    if(current->next!=NULL){
        current->next->previous = newnode;
    }
    current->next = newnode;  
}

//b:part
node* pop(node* head, int index){
    int curr_index = 0;
    node* current = head;
    node* newhead=head;
    while(curr_index!=index && current!=NULL){
        current = current->next;
        curr_index++;
    }
    //if index is 0 ie. head is to be popped
    if(current->previous != NULL){
        current->previous->next = current->next;
    }
    else{
        newhead=current->next;
    }
    
    //if index is end of list
    if(current->next != NULL){
        current->next->previous = current->previous;
    }
    free(current);
    return newhead;
}

//e:part
node* reverse(node* head){
    node* next=head->next;
    node* current = head;
    while (next!=NULL){
        current->next = current->previous;
        current->previous = next;
        current = current->previous;
        next = current->next;
    }
    current->next = current->previous;
    current->previous = NULL;

    return current;
}

void delete_ll(node *head){
    node* current = head;
    while (current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
}

int main(){
    node *head = (node*)calloc(1,sizeof(node));
    head->value = 1;
    head->previous = NULL;
    head->next = NULL;
    add_node(head,2);
    add_node(head,3);
    printinfo(head);
    head = pop(head,0);
    printinfo(head);
    rev_print_ll(head);
    delete_ll(head);
}
