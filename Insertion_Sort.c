void insertion_sort(int array[], int n){
    for (int i=1; i<n; i++){ //assume sorted until index 1. After n-1 passes, the array is sorted until n-1 places.
        int check_element=array[i];
        int j=i;
        while (check_element<array[j-1] && j>0){
            array[j]=array[j-1];
            array[j-1]=check_element;
            j=j-1;
        }
       
       }


    }

    //function to print array
void print_array(int array[], int n){
    for (int i=0; i<n; i++){printf(" %d ", array[i]);}
    }


    int main(){
        int array[]={30,20,50,70,60,10};
        int n=6;
        printf("Array before sorting is \n");
        print_array(array, n);
        insertion_sort(array, n);
        printf("\n Array after sorting is \n");
        print_array(array, n);
    }










