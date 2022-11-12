//linked lists implemented using struc.
#include <stdio.h>
#include <stdlib.h>

struct node //has two parts, one stores the value, the other has the address for the next node.
{
    int value;
    struct node *next;
};

int main(){
    struct node *head= NULL; //initialising both the nodes to NULL
    struct node *two= NULL;

    head= (struct node*)malloc(sizeof(struct node)); //alloccating space for first node
    two= (struct node*)malloc(sizeof(struct node)); //alloccating space for first node

    head->value= 10; 
    head->next= two; //second part of the first node should point towards the second node

    two->value=20;
    two->next=NULL; //as this is the last node, the second part should point towards NULL as there are no more elements. 

    printLinkedList(head);

}

void printLinkedList(struct node* a){ //input is the head node 
    while(a!=NULL){  //would a->next->next != NULL work ?
        printf(" %d ", a->value);
        a=a->next; 

    }
    return 0;
}

