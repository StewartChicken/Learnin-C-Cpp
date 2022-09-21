/*
This Hash Table implementation uses an array of linked list elements which contains an int/vector 
pair to represnt key/value pairs within a hash table. Each vector contains int/int pair elements to represent the X/Y
coordinates of each data point. This HashTable will be used for a basic KNN implementation, so it only allows 
int/vector<pair<int, int>> pairs to be inserted as keys/values 
*/
#include <iostream>
#include <list> 
#include <vector>

using namespace std;

//Hashtable capacity
//Capacity is only at 10 because the data sets, for which I will be using K-N-N
//to analyze, should not exceed 10 classifications
#define CAPACITY 10

//Hashtable to implement K-Nearest-Neighbors algorithm
//Keys = integers (classifications)
//Values = vectors of pairs of ints (data)

class HashMap{
    private:
        /*
        List of pairs "CAPACITY" units long
        Each 'pair' is a key value pair. The linked list contains these pairs which in turn
        represents the Hash Map data structure. Each pair contains an int (key/classification)
        and a vector (value/data), which in turn contains a pair of ints (x/y coordinates)
        */
        list<pair<int, vector<pair<int, int>>>> table[CAPACITY]; 

    public:

        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, vector<pair<int, int>> data);
        void removeItem(int key);
        vector<pair<int, int>> findItem(int key);
        int findItemSize(int key);
        int getNumElements() const; //Returns the number of key/value pairs
        void printTable(); //Prints contents of table

};

//Returns how many elements are filled within the hash map
int HashMap::getNumElements() const{
    int fullCells = 0;
    
    for(int i{}; i < CAPACITY; i ++){
        if(table[i].size() > 0){
            fullCells ++;
        }
    }

    return fullCells;
}

bool HashMap::isEmpty() const{
    int sum{};

    for(int i{}; i < CAPACITY; i ++){
        sum += table[i].size();
    }

    if(!sum){
        return true;
    }

    return false;
}

//Generates a hash value based on which key is being accessed 
int HashMap::hashFunction(int key){
    return key % CAPACITY;
}

void HashMap::insertItem(int key, vector<pair<int, int>> data){
    int hashValue = hashFunction(key);

    //'cell' is a reference directly to the list at index 'hashValue' with the 
    //automatic type of list<pair<int, vector<pair<int, int>>>>
    auto& cell = table[hashValue];
    auto iterator = begin(cell); 
    bool keyExists = false;

    for(; iterator != end(cell); iterator ++){
        if(iterator -> first == key){
            keyExists = true;
            iterator -> second = data;
            cout << "Key already exists. Value replaced" << endl;
            break;
        }
    }
    
    if(!keyExists){
        //key, data
        pair<int, vector<pair<int ,int>>> tempPair;
        tempPair.first = key;
        tempPair.second = data;

        cell.emplace_back(tempPair);
    }

    return;

}

void HashMap::removeItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterator = begin(cell);
    bool keyExists = false;

    for(; iterator != end(cell); iterator ++){
        if(iterator -> first == key){
            keyExists = true;
            iterator = cell.erase(iterator);
            cout << "Pair removed" << endl;
            break;
        }
    }

    if(!keyExists){
        cout << "Item not found" << endl;
    }

    return;
}

vector<pair<int, int>> HashMap::findItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterator = begin(cell);

    for (; iterator != end(cell); iterator ++){
        if(iterator -> first == key){
            return iterator -> second;
        }
    }

    cout << "Item not found" << endl;
    vector<pair<int, int>> returnVector;
    return returnVector;
}

int HashMap::findItemSize(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterator = begin(cell);

    for(; iterator != end(cell); iterator ++){
        if(iterator -> first == key){
            return iterator -> second.size();
        }
    }

    cout << "Item not found" << endl;

    return 0;
}

void HashMap::printTable(){
    for (int i{}; i < CAPACITY; i ++){
        if(table[i].size() == 0) continue;

        auto iterator = table[i].begin();
        for (; iterator != table[i].end(); iterator ++){
            cout << "Key: " << iterator -> first << endl;
            cout << "Values: " << endl;
            for(int j{}; j < iterator -> second.size(); j ++){
                cout << (iterator -> second)[j].first << ", " << (iterator -> second)[j].second << endl;
            }
            cout << endl;
        }

    }

    cout << "Done printing table contents" << endl;
    return;
}
