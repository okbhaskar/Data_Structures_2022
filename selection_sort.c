#include <stdio.h>

/*Selection Sort using Arrays -> Set first index as minimum. 
Compare all the i+1 indexes (until last index) with element at i index.
Every time the element at i+1th index is less than the initial i (minimum) index
we assumed, exchange the values of these indexes (not the elements at this stage).
After the whole array is traversed, IF minimum index is the same as i (which we assumed)
at start, move on to the next minimum index. However, if minimum index isn't same,
we swap the element at the first position and the minimum index so that we always have
the minimum element at the first index*/

//Function to swap elements if an index is found to have an element less than the element at minimum index.
void swap_elements(int array[], int index_1, int index_2){
    int holder = array[index_1];
    array[index_1]=array[index_2];
    array[index_2]=holder;
}
// n is the size of array i.e. number of elements.
void selection_sort_array(int array[], int n){
    for (int i=0; i<n; i++){
        int least_index=i; //initialised i as the index having the element with least value.
        for (int j=i+1; j<n; j++){
            if(array[j]<array[least_index]){least_index=j;}
        }
        if (least_index!=i){swap_elements(array,i, least_index);}
    }
}

//function to print array
void print_array(int array[], int n){
    for (int i=0; i<n; i++){printf("%d\n", array[i]);}
}



int main(){
    int array[]={20,10,30,60,50,40};
    int n=6;
    print_array(array, 6);
    selection_sort_array(array, 6);
    printf("Sorted array is \n");
    print_array(array,6);
}
