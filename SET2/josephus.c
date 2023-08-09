#include "lnkdlst.c"

node* set(int n){
    node* head = (node*)calloc(1,sizeof(node));
    head->value=1;
    int i=2;
    for(;i<n;i++){
        insert(head,i,n);
    }
    node* last = insert(head,n,n);
    last->next = head;
    return head;
}

void remove_target_node(node* head, node* target){
    node *current = head;
    //current goes to one before target;
    while(current->next!=target){
        current = current->next;
    }
    current->next = target->next;
    free(target);
}

int josephus(int num_of_people,int step_size){
    node* head = set(num_of_people);
    node* current = head;
    int i;
    while(current->next!=current){
        printf("%d removes %d\n",current->value,current->next->value);
        remove_target_node(current,current->next);
        for(i=0;i<step_size;i++){
            current=current->next;
        }
    }
    printf("%d wins \n",current->value);
    int val=current->value;
    free(current);
    return val;
}

int main(){
    josephus(16,1);
}