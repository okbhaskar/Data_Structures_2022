#include <stdio.h>
#include <stdlib.h>
#include<time.h>

struct node //has two parts, one stores the value, the other has the address for the next node.
{
    int value;
    struct node *next;
};

int * generateArray(int n){
    int * t=malloc(n * sizeof(int));
    if(t){ //if memory was allocated, only then fill array
    for (int i=0; i<n; i++){
        t[i]=rand()%1000; //write t[i]=i for just 0,1,2,3,4,5,..9]. Random numbers prduced are huge, thus mod 1000 t0 limit the range from 0-999.
    }}
    return t; 
}
typedef struct node * NodeAddress; //new data dtype nodeaddress 

//for loop valid only if memory allocation is successful. Only execute if t isn't null
NodeAddress linkedListfromArray(int *a, int n){
    int i;
    NodeAddress head=NULL;
    NodeAddress temp=NULL;

    if (n>0){
        head=malloc(sizeof(struct node));
        head->value=a[0];
        head->next=NULL;
        temp=head;
    }

    
    for(i=1; i<n; i++){
        temp->next = malloc(sizeof(struct node));
        temp=temp->next;
        temp->value = a[i];
        temp->next = NULL;
    }

    return head;

}

//Function to print a linked list. Same as the function used in implementing_linked_lists.c
void printLinkedList(struct node* a){ //input is the head node 
    while(a!=NULL){  //would a->next->next != NULL work ?
        printf(" %d ", a->value);
        a=a->next; 

    }
}

/*Functions up until now have been borrowed from previous codes and Professor's lecture (generating random array)*/
/*==================================================*/
//choose pivot. Left of Pivot are all less than. Right of pivot are all greater than pivot.
//20 - 6 - 9 - 7 - 10 say
/*Chooose pivot (10) start with head until tail - 1. Traverse and compare every element with pivot. Maintain two pointers  */
/*Iter and next_big; if a[iter]>pivot, no problem, move to next element i++. If a[iter]<pivot, next_big = ++next_big, swap(a[iter] and a[next_big])*/
/*End when only one element in linked list.*/


NodeAddress get_tail(NodeAddress head){
    while (head!=NULL && head->next!=NULL){
        head=head->next;
    }
    return head;
}

NodeAddress partition(NodeAddress start, NodeAddress end){
    NodeAddress iter = start ;
    NodeAddress point = start;
    int pivot = end->value;
    while (iter != end){
        if (iter->value > pivot && iter!=end){
            iter=iter->next;
        }
        else{
            point=point->next;
            int temp=point->value;
            point->value = iter->value;
            iter->value = point->value;
            iter=iter->next;
        }

    }
    point=point->next;
    end->value=point->value;
    point->value= pivot;
    return point;
}


void quicksort(NodeAddress head, NodeAddress tail){
    NodeAddress pivot = partition(head, tail);
    quicksort(head, pivot);
    quicksort(pivot->next, tail);
}




/*==============================================*/

int main(){
int *a=generateArray(10);
NodeAddress list=linkedListfromArray(a, 10);
printLinkedList(list);
NodeAddress p = get_tail(list);
quicksort(list, p);
printLinkedList(list);

}