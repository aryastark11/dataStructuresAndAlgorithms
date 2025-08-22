/* This code contains STACK Data Structure implemented using ARRAYS.

STACK Data Structure can also be implemeneted using LinkedLists.

The time complexity of Array is as follows:
Push - 
Pop -
*/
#include <iostream>
using namespace std;

// defining global variables.
int const MAX = 5; // max Stack size // Need to be known before hand.
int Stack[MAX];
int rear = -1, front=-1;

void Push(int x){
    if (rear == MAX-1){
        std::cout<<"Stack is full";
    }
    else {
        if (front == -1){
            front = 0;
        }
        rear++;
        Stack[rear] = x;
    }
    return;
    
}

int Pop(){
    int output;
    if (front == -1){
        std::cout<<"Stack is empty";
        return -1;
    }
    else {
        output = Stack[rear];
        rear--;
        return output;
    }
}

int TopOfStack(){
    if (front == -1){
        std::cout<<"Stack is empty";
        return -1;
    }
    else {
        return Stack[rear];
    }
}

int main(){
    std::cout<<Pop()<<std::endl; // Stack is empty
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    std::cout<<"top = "<<TopOfStack()<<std::endl; // returns 4
    std::cout<<Pop()<<std::endl; // returns 4
    std::cout<<"top = "<<TopOfStack()<<std::endl; // returns 3
    Push(5);
    std::cout<<"top = "<<TopOfStack()<<std::endl; // returns 5
    std::cout<<Pop()<<std::endl; // returns 5
    std::cout<<Pop()<<std::endl; // returns 3
}