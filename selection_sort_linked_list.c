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
void selection_sort_ll(struct node *head){
//find minimum element ->add it to sorted list. remove it from unsorted list. Find minimu element from the modified unsorted list


struct node *start=head;
struct node *iter=NULL;
 

while (start){         
    iter= start->next; //at every iteration, we conisder the given node to have the minimum value. If any other node after that node has a value less than the present node, we simply exhange the value and continue. 
    while (iter){
        if(start->value > iter->value){
            int temp = start->value;
            start->value= iter->value;
           iter->value= temp;

        }
        iter=iter->next;}
    start=start->next;
    
}

}








/*=================================================*/
int main(){
int *a=generateArray(10);
NodeAddress list=linkedListfromArray(a, 10);
printLinkedList(list);
selection_sort_ll(list);
printf("\n List after sorting : \n");
printLinkedList(list);
}
