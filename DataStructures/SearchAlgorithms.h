#include <iostream>
using namespace std;

class Search{ //Class containing three search algorithms

    int* array; 
    int size;
    int search; //To be found integer value

public:

    Search(int* arr, int size, int search); //Constructor

    int linearSearch(); //Three search algorithms to-be-implemented
    int binarySearch();
    int interpolationSearch();

    void printArr();

};

void Search::printArr(){ //Prints contents of array
    for(int i = 0; i < size; i ++){
        cout << array[i] << " ";
    }
}

Search::Search(int* arr, int size, int search){ //Constructor
    this -> array = arr;
    this -> size = size;
    this -> search = search;
}

//Does not need to be sorted
int Search::linearSearch(){

    for(int i = 0; i < size; i ++){ //Searches indeces one by one until value is found. O(n) complexity
        if(array[i] == search){
            cout << "Element found at index: " << i << endl;
            return i;
        }
    }

    cout << "Element not found in array" << endl;
    return -1;
}

//Needs to be sorted
//Continually divides the data into two portions, comparing the desired value
//to the mid way point at each step. Deletes the half that does not contain the value
//O(logn) time complexity
int Search::binarySearch(){ 
    int beginning = 0; 
    int end = size;

    while(beginning <= end){
        int index = ((beginning + end) / 2);

        if(search == array[index]){
            cout << "Element found at index " << index << endl;
            return index;
        }else if(search > array[index]){
            beginning = index + 1;
        }else{
            end = index;
        }
    }

    cout << "Element not found in array" << endl;
    return -1;

}

//Needs to be sorted/uniformly distributed
//Creates a 'probe' value based on how close the desired value is to the
//high end/low end of the data. Instead of placing the 'probe' directly
//in between the high/low values (like binary search), interpolation
//search will adjust its probe to search the most likely area the value 
//might be. 
//O(log(logn)) time complexity (average case)
int Search::interpolationSearch(){

    int high = size - 1;
    int low = 0;

    while(search >= array[low] && search <= array[high] && low <= high){

        int probe = low + (high - low) * (search - array[low]) / (array[high] - array[low]); //Probe formula

        if(array[probe] == search){
            cout << "Element found at index " << probe << endl;
            return probe;
        }else if(array[probe] < search){
            low = probe + 1;
        }else{
            high = probe - 1;
        }
    }
    cout << "Element not found in array" << endl;
    return -1;
}
