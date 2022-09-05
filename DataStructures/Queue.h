//Implementation of a circular queue

#include <iostream>

using namespace std;

//Queue class
class Queue{

    int* array; //Queue's array
    int capacity; //Queue's max capacity
    int front; //Front index
    int rear; //Rear index
    int size; //Current size of queue

public:

    Queue(int size); //Constructor
    ~Queue(); //Destructor

    void enqueue(int n); //Add ints to queue
    int dequeue(); //Remove first index of queue
    
    int getFront(); //Returns front index
    int getRear(); //Returns rear index
    int getSize(); //Returns the current size of the queue
    bool isEmpty(); //Returns if queue is empty
    bool isFull(); //Returns if queue is full

    void printQueue(); //Prints all of queue's contents

};

Queue::Queue(int size){ //Constructor
    this -> capacity = size;
    front = 0;
    rear = -1;
    size = 0;
    array = new int[capacity];
}

Queue::~Queue(){ //Destructor
    cout << "Deleting Queue" << endl;
    delete[] array;
}

void Queue::enqueue(int n){ //Adds elements to rear of queue

    if(isFull()){
        cout << "enqueueing " << n << endl;
        rear = (rear + 1) % capacity;
        array[rear] = n;
        
    }else{
        cout << "enqueueing " << n << endl;
        rear = (rear + 1) % capacity;
        array[rear] = n;
        size ++;
    }    
}    

int Queue::dequeue(){ //Removes first element in queue

    if(isEmpty()){
        cout << "Queue is empty";
    }else{
        int value = array[front];
        cout << "dequeueing " << value << endl; 

        front = (front + 1) % capacity;
        size --;
        return value;
    }

}

int Queue::getFront(){ //Returns front
    cout << "Front: " << array[front] << endl;
    return array[front];
}

int Queue::getRear(){ //Returns rear
    cout << "Rear: " << array[rear] << endl;
    return array[rear];
}

int Queue::getSize(){ //Returns size
    cout << "Size: " << size << endl;
    return size;
}

bool Queue::isEmpty(){ //Returns queue empty state
    return size == 0;
}

bool Queue::isFull(){ //Returns queue full state
    return size == capacity;
}

void Queue::printQueue(){ //Prints queue contents
    cout << "Printing Queue Contents" << endl;
    for(int i = 0; i < size; i ++){
        cout << array[i] << " ";
    }
    cout << endl;
    cout << "Done" << endl;
}
