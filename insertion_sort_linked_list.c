#include<stdio.h>
#include<stdlib.h>
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
/*===========================================================*/


/*we can only access any node from the head, thus, we maintain two separate lists, first is our original list and the second is 
a partially sorted list. our job will be done when partially sorted list is the same length as the first list.*/

struct node* sorted = NULL; //initially, no elements have been sorted.


void place (struct node *insertwhat){

    if (sorted == NULL || sorted->value > insertwhat->value) { //when the sorted list is empty or the first element is greater than the element which is supposed to be placed.
        insertwhat ->next = sorted;
        sorted = insertwhat;
    }
    else{
        struct node *pointer = sorted;

        while (pointer->next != NULL && insertwhat->value > pointer-> next-> value){ //we have to locate the node where our present element will be placed so that the list remains sorted.
            pointer=pointer-> next;
        }
        insertwhat->next= pointer->next; //once node is located, we just place our element in this place and link it accordingly.
        pointer->next= insertwhat;   
    
    }
}


void insertion_sort_LL(struct node *a){ //input for the function should be the head node)
    
    struct node *present = a; //we have to iterate through the entire list. present is just an iterator.

    while (present!=NULL){
        struct node *nextnode = present->next; //we take one element from the first list in every pass and place it in its correct position in the partially sorted list. We have to make sure to save the next value of pointer after we're done saving the present element.

        place(present); /*place present node in its correct position*/

        present= nextnode; //next element's turn

    }

    a = sorted; //after all the elements have been placed in the partially sorted list (which is now completely sorted) we return this sorted list to the user.
    }


/*==============================================*/
int main(int argc, char **argv){
    int *a ;
    int n=10;
    NodeAddress list; 
    srand(time(NULL)); //giving seed to srand, wont be repeated as some time would have passed when the program is re-run.,
    a=generateArray(n); //address of beginning of the array
    list=linkedListfromArray(a,n);
    printLinkedList(list);

    insertion_sort_LL(list);
    printf("\n Sorted list is \n");
    printLinkedList(list);

}
