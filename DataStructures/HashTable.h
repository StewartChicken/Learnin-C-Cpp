#include <iostream>
#include <list> //This hashmap implementation utilizes linked lists of pairs of pairs
                //to contain the key, value, and size

using namespace std;

//Hashtable capacity
//Capacity is only at 10 because the data sets, for which I will be using K-N-N
//to analyze, should not exceed 10 classifications
#define CAPACITY 10

//Hashtable to implement K-Nearest-Neighbors algorithm
//Keys = integers (classifications)
//Values = arrays of integers (data)

class HashMap{
    private:
        //List of pairs "CAPACITY" units long
        //Each 'pair' is a key value pair. The linked list contains these pairs which in turn
        //represents the Hash Map data structure
        //Each list contains a pair of a pair: the inner pair contains the to-be-hashed key/value 
        //while the outer pair contains that inner pair as well as the size of the array value
        list<pair<pair<int, int*>, int>> table[CAPACITY]; 

    public:

        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, int* value, int size);
        void removeItem(int key);
        int* findItem(int key);
        int findItemSize(int key);
        void printTable(); //Prints constants of table

};

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

void HashMap::insertItem(int key, int* value, int size){
    int hashValue = hashFunction(key);

    //'cell' is a reference directly to the list at index 'hashValue' with the 
    //automatic type of list<pair<int, int*>>
    auto& cell = table[hashValue];
    auto iterator = begin(cell); 
    bool keyExists = false;

    for(; iterator != end(cell); iterator ++){
        if(iterator -> first.first == key){
            keyExists = true;
            iterator -> first.second = value;
            iterator -> second = size;
            cout << "Key already exists. Value replaced" << endl;
            break;
        }
    }
    
    if(!keyExists){
        //key, value, size
        pair<pair<int, int*>, int> tempPair;
        tempPair.first.first = key;
        tempPair.first.second = value;
        tempPair.second = size;
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
        if(iterator -> first.first == key){
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

int* HashMap::findItem(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterator = begin(cell);

    for (; iterator != end(cell); iterator ++){
        if(iterator -> first.first == key){
            return iterator -> first.second;
        }
    }

    cout << "Item not found" << endl;
    return NULL;
}

int HashMap::findItemSize(int key){
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto iterator = begin(cell);

    for(; iterator != end(cell); iterator ++){
        if(iterator -> first.first == key){
            return iterator -> second;
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
            cout << "Key: " << iterator -> first.first << endl;
            cout << "Value: ";
            for(int j{}; j < iterator -> second; j ++){
                cout << *(iterator -> first.second + j) << " ";
            }
            cout << endl;
        }

    }

    cout << "Done" << endl;
    return;
}
