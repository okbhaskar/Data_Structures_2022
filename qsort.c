

#include <stdio.h>


// function to find the partition position
int partition(int array[], int low_index, int high_index) {
  
  
  int key = array[high_index]; //compare every element with the key. 
  
  
  int point1 = (low_index - 1);//two pointers used. One to iterate through the array, other which always points to the next greater element after key.

  
  
  for (int point2 = low_index; point2 < high_index; point2++) {
    if (array[point2] < key) {
        
      point1++;
      
      
      int temp = array[point1];
      array[point1]=array[point2] ; //swapping elements
      array[point2]= temp;
    }}
    //after loop, put key in position such that all elements to the left are smaller and all elements to the right are greater.
    array[high_index]=array[point1+1];
    array[point1+1]=key;
  

  

  
  
  return (point1+1);
}

void qsort(int array[], int low_index, int high_index) {
  if (low_index< high_index) {
    

    int point = partition(array, low_index, high_index);
    
    qsort(array, low_index, point - 1);
    
    qsort(array, point + 1, high_index);
  }
}


void parray(int array[], int n) {
  for (int i = 0; i < n; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  int array[] = {90,80,85,12,32,54,40};
  
  int n = 7;
  

  parray(array, n);

  qsort(array, 0, n-1);
  
  parray(array, n);
}