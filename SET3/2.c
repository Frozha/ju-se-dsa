#include<stdio.h>
#include<stdlib.h>
#include"display.h"
//#define MOD(a) a>0?a:(-1*a)

int left_subtree_inorder_index(int* pre, int* in){
    int length = sizeof(pre);
    if(length == 0)return -1;
    else if(length == 1)return 0;
    int i= 0;
    queue* pending = init(length);
    do{
       if(in_queue_at(*pending,pre[i])==-1){
            enqueue(pending,pre[i]);
        }
        else{
            remove(pending,pre[i]);
        }
        if(in_queue_at(*pending,in[i])==-1){
            enqueue(pending,in[i]);
        }
        else{
            remove(pending,in[i]);
        }
        i++;
    } while (pending->tail!=0&&i<length);
    if(pending->tail==0){delete(pending);return i-1;}
    else{delete(pending);return-1;}
}

int smallest_subarr_indx(int* pre, int* in){
    int length = sizeof(pre);
    if(length == 0) return -1;
    if(length == 1) return pre[0]==in[0]?0:-1;
    queue* pending = init(length);
    int i=0;
    do
    {
        if(in_queue_at(*pending,pre[i])==-1){
            enqueue(pending,pre[i]);
        }
        else{
            remove(pending,pre[i]);
        }
        if(in_queue_at(*pending,in[i])==-1){
            enqueue(pending,in[i]);
        }
        else{
            remove(pending,in[i]);
        }
        i++;
    } while (pending->tail!=0&&i<length);
    int k = pending->tail;
    delete(pending);
    if(k!=0){return -1;}
    else return i-1;
}

int* subarray(int* arr, int a, int b){
    int* subarr;
    if(a < b){
        subarr = (int*)calloc((b - a), sizeof(int));
        int i;
        for(i = a; i < b; i++){
            subarr[i - a] = arr[i];
        }
    }
    else if(a==b){
        subarr = (int*)calloc(1,sizeof(int));
        *subarr = arr[a];
    }
    else {
        subarr = NULL;   
    }
    return subarr;
}
/*
treenode* pre_in_to_treenode(int* pre,int* in,int r){
    int len = sizeof(pre);
    queue* preord = init(pre);
    queue* inord = init(in);

    return i;
}

*/


queue** create_treeconv_buffer(int length){
    int i = 2;
    int j = 1;
    int current_lvl=0;
    for(;i-1<length;i*=2){current_lvl++;}
    queue** buffer = (queue**)calloc(current_lvl+1,sizeof(queue*));
    if(buffer==NULL)goto z;
    for(j=0;j<=current_lvl;j++){
        buffer[j] = init(pow(2,j));
        if(buffer[j]==NULL)goto y;
    }
    return buffer;
    y:
    while(j!=0){
        j--;
        delete(buffer[j]);
    }
    z:
    free(buffer);
    printf("mem alloc for buffer failed");
    return NULL;
}

void treeconv(int* pre, int* in, int length, int current_level, queue** buffer){
    int root_indx = left_subtree_inorder_index(pre,in);
    int root_dat=-1;
    if(root_indx>=0&&root_indx<length){root_dat = in[root_indx];}
    else{
        printf("root indx = %d Root - %d, level - %d\n",root_indx, root_dat,current_level);
        //enqueue(buffer[current_level],root_dat);
        return;
    }
    printf("root indx = %d Root - %d, level - %d\n",root_indx, root_dat,current_level);
    //enqueue(buffer[current_level],root_dat);
    if(length>1){
        int* l_subtree_pre = subarray(pre,1,root_indx+1);
        int* l_subtree_in = subarray(in, 0,root_indx);
        treeconv(l_subtree_pre,l_subtree_in,root_indx,current_level+1,buffer);
        int* r_subtree_pre = subarray(pre,root_indx+1,length);
        int* r_subtree_in = subarray(in, root_indx+1, length);
        treeconv(r_subtree_pre,r_subtree_in,length-root_indx-1,current_level+1,buffer);
        free(l_subtree_pre);
        free(l_subtree_in);
        free(r_subtree_pre);
        free(r_subtree_in);
    }
}
/*
void display(queue** buffer,int length_of_preorder){
    int i,level=0;
    for(;i-1<length_of_preorder;i*=2){level++;}
    for(i=0;i<=level+1;i++){
        display(buffer[i]);
    }
}
*/
void remove_buffer(queue** buffer, int length_of_preorder){
    int i,level=0;
    for(;i-1<length_of_preorder;i*=2){level++;}
    i = level+2;
    while(i!=0){
        i--;
        delete(buffer[i]);
    }
    free(buffer);
}

int main() {
    int pre[] = {1,2,4,5};
    int in[] = {4,5,2,1};
    //printf("%d",minDepth(pre));
    
    int i,j;
    queue** buffer= create_treeconv_buffer(4);
    treeconv(pre,in,8,0,buffer);
    display2(buffer,3);
    remove_buffer(buffer,8);
    
}