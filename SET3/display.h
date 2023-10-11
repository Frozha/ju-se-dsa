/*
@frozha - hrithvik kondalkar - jadavpur university 2026
-----------------------------------------------------------------------
to display a binary tree in terminal

level = 0
1

level = 1 
. _ 1 _ .
( . . . )
2 . . . 3 

level = 2
. . . _ _ _ 1 _ _ _ 
. . ( . . . . . . . )  
. _ 2 _ . . . . . _ 3 _ 
( . . . ) . . . ( . . . ) 
4 . . . ? . . . 6 . . . 7  

level = 3
. . . . . . . _ _ _ _ _ _ _ 1 _ _ _ _ _ _ _ 
. . . . . . ( . . . . . . . . . . . . . . . ) 
. . . _ _ _ 2 _ _ _ . . . . . . . . . _ _ _ 3 _ _ _ 
. . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) 
. _ 4 _ . . . . . _ ? _ . . . . . _ 6 _ . . . . . _ 7 _ 
( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) 
8 . . . 9 . . . ? . . . ? . . . 12. . . 13. . . 14. . . 15 // enter backspace char '\b' after printing double digs 

level = 4
. . . . . . . . . . . . . . . _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 1 _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ 
. . . . . . . . . . . . . . ( . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ) 
. . . . . . . _ _ _ _ _ _ _ 2 _ _ _ _ _ _ _ . . . . . . . . . . . . . . . . . _ _ _ _ _ _ _ 3 _ _ _ _ _ _ _
. . . . . . ( . . . . . . . . . . . . . . . ) . . . . . . . . . . . . . . . ( . . . . . . . . . . . . . . . )
. . . _ _ _ 4 _ _ _ . . . . . . . . . _ _ _ ? _ _ _ . . . . . . . . . _ _ _ 6 _ _ _ . . . . . . . . . _ _ _ 7 _ _ _
. . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) . . . . . . . ( . . . . . . . ) . . . . . . . ( . . . . . . . )
. _ 8 _ . . . . . _ 9 _ . . . . . _ ? _ . . . . . _ ? _ . . . . . _ 12_ . . . . . _ 13_ . . . . . _ 14_ . . . . . _ 15_
( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . ) . . . ( . . . )
16. . . 17. . . 18. . . 19. . . ? . . . ? . . . ? . . . ? . . . 24. . . 25. . . 26. . . 27. . . 28. . . 29. . . 30. . . 31

...

[genralizing]
level = n (latest_level)
(current_level is r)
A(n) = 2(n+1) //number of rows 
B(n) = 2^(n+2)-3 //number of columns 
C(n,r) = (2^(n - r))-1 // number of underscores on each side of node
D(n,r) = 2^(n-r)-1 // number of spaces before left most node (before all underscores)
E(n,r) = 2^r // number of nodes per level 
F(n,r) = 2^(n-r+1)+1 //number of spaces between 2 nodes (after underscores) 
G(n,r) = 2^(n-r+1)+1-2 //number of spaces between 2 brackets is

spaces and nodes and parenth are printed with a prespace in them.
ex: ' 0', ' (', etc.
note: ' .'->'  '

node row print(n,r):nrp(n,r)
insert D(n,r) spaces and do a->d (2^r) times 
    a. insert C(n,r) underscores
    b. insert node
    c. insert C(n,r) underscores
    d. insert F(n,r) spaces

bracket row print(n,r):brp(n,r)
insert D(n,r)-1 spaces and then do a -> d (2^r) times 
    a. insert open parenth
    b. insert G(n,r) spaces
    c. insert close parenth
    d. insert G(n,r) spaces

ALGORITHM : 
0. nrp(n,0);
1. set latest row as n and current row as r=1
2. brp(n,r)->newline->nrp(n,r)
3. increment r by one if not equal to n then goto 2. else goto 4.
4. end

*/
#include <stdio.h>
#include"queue.h"
#include"tree.h"
int pow(const int a, const int b){
    int result=1;
    if(b==0){
        return result;
    }
    else if(b>0){
        int i;
        for(i=0;i<b;i++){
            result*=a;
        }
        return result;
    }
    else return -1;
}

#define A(n) (2 * ((n) + 1)) 
#define B(n) (pow(2, (n) + 2) - 3)
#define C(n, r) (pow(2, (n) - (r)) - 1)
#define D(n, r) (pow(2, (n) - (r)) - 1)
#define E(n, r) pow(2, r) 
#define F(n, r) (pow(2, (n) - (r) + 1) + 1) 
#define G(n, r) (pow(2, (n) - (r) + 1) - 1)

int maxDepth(treenode* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = maxDepth(node->left_child);
        int rightDepth = maxDepth(node->right_child);
        return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
    }
}

void nrp(queue* q, int n, int r) {
    int i, j,counter;
    for (i = 0; i < D(n, r); i++) {
        printf("  ");
    }
    for (i = 0,counter = 0; i < pow(2, r);i++) {
        for (j = 0; j < C(n, r); j++) {
            printf("_ ");
        }
        if(counter<q->tail){
            if((q->data)[counter]==-1){
                printf("? ");
                counter++;
            }
            else{
                printf("%d ",(q->data)[counter]); // Node
                counter++;
                if(((q->data)[counter])/10!=0){
                printf("\b");
                }
            }
        }
        else if(counter>=q->tail&&counter<q->buffer_size){
            printf("? ");
            counter++;
        }

        for (j = 0; j < C(n, r); j++) {
            printf("_ ");
        }
        for (j = 0; j < F(n, r); j++) {
            printf("  ");
        }
    }
    printf("\n");
}

void brp(int n, int r) {
    int i, j;
    for (i = 0; i < D(n, r) - 1; i++) {
        printf("  ");
    }
    for (i = 0; i < pow(2, r); i++) {
        printf("( "); // Open Parenthesis
        for (j = 0; j < G(n, r); j++) {
            printf("  ");
        }
        printf(") "); // Close Parenthesis
        for (j = 0; j < G(n, r); j++) {
            printf("  ");
        }
    }
    printf("\n");
}

void display2(queue** buffer, int max_lvl) {
    nrp(buffer[0], max_lvl, 0); // Display root node
    int r = 1; // Current row starts from 1
    while (r <= max_lvl) {
        brp(max_lvl, r-1); // Display branches for the current row
        nrp(buffer[r], max_lvl, r); // Display nodes for the current row
        r++; // Increment row
    }
}
