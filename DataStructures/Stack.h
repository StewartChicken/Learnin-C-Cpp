#include <iostream>

using namespace std;

//Stack class
class Stack{

    int* array = NULL; //Array that contains the data (dynamic)
    int top; //Top index
    int capacity; //Max capacity

    
public:

    Stack(int size); //Constructor
    ~Stack(); //Destructor
    
    //Classes methods
    void push(int n); 
    int pop();
    int peek();
    
    int size();
    bool isFull();
    bool isEmpty();

};

Stack::Stack(int size){ //Constructor
        this -> capacity = size;

        array = new int[capacity];
        top = -1;
        capacity = size;
}

Stack::~Stack(){ //Destructor
    cout << "Deleting Stack" << endl;
    delete[] array;
}

void Stack::push(int n){ //Pushes data onto stack
    if(isFull()){
        cout << "Stack is full" << endl;
    }else{
        top ++;
        cout << "Pushing: " << n << endl;
        array[top] = n;
    }

}

int Stack::pop(){ //Pops data from stack
    if(isEmpty()){
        cout << "Stack is empty" << endl;
    }else{
        top --;
        cout << "Popping: " << array[top] << endl;
        return array[top];
    }
    
}

int Stack::peek(){ //Returns top element
    if(isEmpty()){
        cout << "Stack is empty" << endl;
    }else{
        cout << array[top] << endl;
        return array[top];
    }
}

int Stack::size(){ //Returns number of elements within stack
    cout << "size = " << top + 1 << endl;
    return top + 1;
}

bool Stack::isFull(){ //Returns whether the stack is full or not
    cout << (top + 1 == capacity) << endl;
    return top + 1 == capacity;
}

bool Stack::isEmpty(){ //Returns whether the stack is empty or not
    cout << (top == -1) << endl;
    return top == -1;
}
