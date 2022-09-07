#include <iostream>
using namespace std;

class Sort{

    int* array;
    int size;

public:

    Sort(int* arr, int size);

    int* bubbleSort();
    int* selectionSort();
    int* insertionSort();
    
    void quickSort(int arr[], int leftIndex, int rightIndex); //Recursive: needs parameters (in the context of this class)
    int partition(int arr[], int leftIndex, int rightIndex);

    void mergeSort(int arr[], int left, int right);
    void merge(int arr[], int left, int middle, int right); //For mergeSort function. Merges two arrays/data points together based on their magnitudes

};

Sort::Sort(int *arr, int size){
    this -> array = arr;
    this -> size = size;

}

//For quickSort method
int Sort::partition(int arr[], int leftIndex, int rightIndex){ //Finds the pivot location of the last number in the array

    int pivot = arr[rightIndex]; //Uses function argument 'size', not class size
    int i = leftIndex - 1; //Will eventually equal the final index of the pivot value
    
    for(int j = leftIndex; j < rightIndex; j ++){
        if(arr[j] < pivot){
            i ++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i ++;
    arr[rightIndex] = arr[i];
    arr[i] = pivot;

    return i;
        
}

//Quick sort is a recursively called sorting algorithm which utilizes a pivot value
//(the last index of each array/subarray in this implementation) to continually sort
//an array as it breaks it down into subarrays consisting of numbers smaller/larger than
//the pivot value
//O(nlog(n)) average time complexity
void Sort::quickSort(int arr[], int leftIndex, int rightIndex){ 
    
    if(rightIndex <= leftIndex){ // Base case
        return;
    }

    int pivot = partition(arr, leftIndex, rightIndex); //Finds the pivot's location in the array and 
    quickSort(arr, leftIndex, pivot - 1);              //and puts the lesser valued numbers on the left
    quickSort(arr, pivot + 1, rightIndex);             //and the greater valued numbers on the right of the pivot

}

//Merges two arrays together in ascending order assuming they are sorted 
void Sort::merge(int arr[], int left, int middle, int right){
    int s1 = middle - left + 1; //Left subarray index
    int s2 = right - middle; //Right subarray index

    //Temp arrays
    int *tempLeft = new int[s1];
    int *tempRight = new int[s2];

    //Populating the temp array
    for(int k = 0; k < s1; k ++){
        tempLeft[k] = arr[left + k];
    }

    for(int l = 0; l < s2; l ++){
        tempRight[l] = arr[middle + 1 + l];
    }

    int i = 0; //Tracks left subarray index
    int j = 0; //Tracks right subarray index
    int k = left; //Tracks index of element insertion into main array

    //Sorting
    while(i < s1 && j < s2){
        if(tempLeft[i] <= tempRight[j]){
            arr[k] = tempLeft[i];
            i ++;
        }else{
            arr[k] = tempRight[j];
            j ++;
        }
        k ++;
    }

    while(i < s1){
        arr[k] = tempLeft[i];
        i ++;
        k ++;
    }

    while(j < s2){
        arr[k] = tempRight[j];
        j ++;
        k ++;
    }

    delete[] tempLeft;
    delete[] tempRight;

}
//Merge sort is a recursively called sorting algorithm that repeatedly breaks the array
//into smaller and smaller sub-arrays until each array is of length one. Then it sorts and
//recombines each sub array into larger and larger arrays until the initial array is achieved
//in its sorted state
//O(nlog(n)) time complexity
void Sort::mergeSort(int arr[], int left, int right){ // Requires arguments bc the function will be called recursively
    if(left >= right){ // Base case
        return;
    }
    int middle = (left + right) / 2;
    Sort::mergeSort(arr, left, middle); //Recursive calling
    Sort::mergeSort(arr, middle + 1, right);
    Sort::merge(arr, left, middle, right);
    
}

//Starting at index 1 and moving right, continually compares
//the current index with each value to its left to determine if it is larger.
//If so, the larger value is shifted to the right and the temp value is 
//inserted into the empty slot
//O(n^2) worst case time complexity
int* Sort::insertionSort(){
    for(int i = 1; i < size; i ++){
        int temp = array[i];
        for(int j = i - 1; j >= 0; j --){
            if(array[j] > temp){
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int k = 0; k < size; k ++){
        cout << array[k] << " ";
    }

    return array;
}

//Sorts an array by tracking the minimum value and moving it to the lowest unsorted
//index of the array during a single iteration. Repeats iterations until the array
// is sorted
//O(n^2) average time complexity
int* Sort::selectionSort(){
    int insertionIndex = 0; //Tracks the lowest unsorted index (increases with each iteration)
    int replaceIndex; //Tracks the index of the lowest unsorted value
    int temp;

    bool sorted = false;
    while(!sorted){
        bool alteration = false;
        int min = array[insertionIndex];
        for(int i = insertionIndex; i < size; i ++){
            if(array[i] < min){
                alteration = true;
                min = array[i];
                replaceIndex = i;

            }
        }

        temp = array[insertionIndex];
        array[insertionIndex] = min;
        array[replaceIndex] = temp;

        insertionIndex ++;

        if(!alteration){
            sorted = true;
            break;
        }

    }

    for(int k = 0; k < size; k ++){
        cout << array[k] << " ";
    }
    
}

//Compares pairs of two elements (starting at indeces 0 and 1) and switches
//them if they are out of order. Runs through entire array swapping pairs of
//two displaced values and restarts once it reaches the end. 
//Loops until array is sorted
//O(n^2) average time complexity
int* Sort::bubbleSort(){
    bool sorted = false;

    while(!sorted){
        bool alteration = false;
        for(int i = 0; i < size - 1; i ++){
            if(array[i] > array[i + 1]){
                alteration = true;
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        if(!alteration){
            sorted = true;
            break;
        }

    }

    for(int k = 0; k < size; k ++){
        cout << array[k] << " ";
    }

    return array;
    
}
