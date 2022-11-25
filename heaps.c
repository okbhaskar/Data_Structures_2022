#include <stdio.h>

/*Max-heaps are a form of priority queue*/
/*invariant max heap - parent always greater than or equal to either of it's children*/
/*heapify- correct a single violation of heap invariant in a subtree's root*/

/*Convert array A[1...n] into a MAX heap */
/*build_max_heap(A):
    for (i = n/2) downto 1 (ALL LEAVES ARE ALREADY GOOD. N/2 LAST PARENT)
        do max_heapify(A, i)*/

//swap function to swap elements when they violate invariant conditions.

void swap(int *one, int *two){
    int temp = *one;
    *one = *two;
    *two = temp;
}

void siftdown(int array[], int size, int i){
    int root = i;
    int left_c = 2*i+1;
    int right_c= 2*i+2;

    if (left_c<size && array[left_c]>array[root]){
        root= left_c;
    }

    if (right_c<size && array[right_c]>array[root]){
        root=right_c;
    }
    if (root !=i){
        swap(&array[i], &array[root]); //swap if either right or left child is greater than the root.

        siftdown(array, size, root); //after swapping check again for the element which is at the child node now (after swapping).
    }

}

void buildheap(int array[], int size){

    for (int i = size/2 - 1; i>=0; i--){ // parent of the last leaf node

        siftdown(array, size, i);


    }
}

void printheap(int array[], int size){
    for (int i=0; i<size; i++){
        printf(" %d ", array[i]);
    }
}

int main(){
    int array[]={12,3,4,54,23,9,19};
    int size=7;
    printheap(array, size);
    printf("\n");
    buildheap(array, size);
    printheap(array, size);
}