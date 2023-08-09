#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    node* next;
}node;

node* make_node(int value){
    node* new_node = (node*)calloc(1,sizeof(node));
    new_node->value = value;
    return new_node;
}

node* insert(node* head,int value, int index){
    int curr_index = 1;
    node* current = head;
    while(current->next!=NULL&&curr_index!=index){
        current=current->next;
        curr_index++;
    }
    //brings to one node before index
    node* new_ll = make_node(value);
    node* next = current->next;
    current->next = new_ll;
    new_ll->next = next;
    return new_ll;
}

void pop(node* head,int index){
    int curr_index = 1;
    node* current = head;
    while(current->next!=NULL&&curr_index!=index){
        current=current->next;
        curr_index++;
    }
    node* to_del = current->next;
    if(to_del!=NULL){
        current->next = to_del->next;
        free(to_del);
    }
    //current is at end need to go back one step to delete end
    else{
        index=1;
        current = head;
        while(current->next!=NULL&&index!=curr_index){
            current=current->next;
            index++;
        }
        to_del = current->next;
        if(to_del!=NULL){
            current->next = to_del->next;
            free(to_del);
        }

    }
    
}

void delete_ll(node *head){
    node* current = head;
    while (current != NULL){
        node* next = current->next;
        free(current);
        current = next;
    }
}

void printinfo(node *head){
    node *current = head;
    while(current!=NULL){
        printf("<%d|%p>\t",current->value,current->next);
        current=current->next;
    }
    printf("\n\n");
}

int size_ll(node* head){
    node* current = head;
    int length=1;
    while (current->next!=NULL){
        current=current->next;
        length++;
    }
    return length;
}

void rev_print(node* head){
    int len=size_ll(head);
    int i,j;
    node*current;
    for(i=len-1;i>=0;i--){
        current = head;
        for(j=0;j<i;j++){
            current=current->next;
        }
        printf("%d\t",current->value);
    }
}

node* reverse(node* head){
    node* prev = head;
    node* current = prev->next;
    node* next = current->next;
    prev->next = NULL;
    while(current!=NULL){
        current->next = prev;
        prev = current;
        current = next;
        if(next!=NULL){
            next = next->next;
        }
    }
    return prev;
}
/*
int main(){
    node* head = make_node(1);
    insert(head,2,2);
    insert(head,4,2);
    insert(head,3,2);
    printinfo(head);
    head = reverse(head);
    printinfo(head);
    delete_ll(head);
}
*/