#include"linked_list.c"

node *stack = NULL;

void push(int element){
    if(stack == NULL){
        //empty stack condition
        stack = give_node(element);
    }
    else{
        stack = insert(stack,element,size(stack));
    }
}

int peep(){
    node*current = stack;
    int i=0;
    while(current->next!=NULL){
        current=current->next;
    } 
    return current->data;
}

int pop(){
    int retval = peep();
    int end = size(stack)-1;
    stack = delete_index(stack,end);
    return retval;
}

int isempty(){
    if(stack==NULL)return 1;
    else return 0;
}


int main(){
    char choice;
    int element;

    do {
        printf("Stack Menu:\n");
        printf("a. Push element\n");
        printf("b. Pop element\n");
        printf("c. Peep (Top) element\n");
        printf("d. Check if stack is empty\n");
        printf("e. Get stack size\n");
        printf("f. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(element);
                break;

            case 'b':
                if (!isempty()) {
                    int popped = pop();
                    printf("Popped element: %d\n", popped);
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            case 'c':
                if (!isempty()) {
                    int top = peep();
                    printf("Top element: %d\n", top);
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            case 'd':
                if (isempty()) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;

            case 'e':
                printf("Stack size: %d\n", size(stack));
                break;

            case 'f':
                end(stack);  // Free memory used by the linked list
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please choose again.\n");
        }
    } while (choice != 'f');

    return 0;

}