/* This code contains QUEUE Data Structure implemented using ARRAYS.

QUEUE Data Structure can also be implemeneted using LinkedLists.

The time complexity of Array is as follows:
The time complexity of Array is as follows:
Enqueue - 
Dequeue -
*/


#include <iostream>
using namespace std;

// defining global variables.
int const MAX = 5; // max Queue size
int queue_Q[MAX];
int rear = -1, front=-1;

void enQueue(int x){
    if (rear == MAX-1){
        std::cout<<"Queue is full. Cannot ENQUEUE"<<endl;
        return;
    }
    else {
        if (front == -1){
            front = 0;
        }
        rear++;
        queue_Q[rear] = x;
    }
}

int deQueue(){
    if (front == -1 or rear == -1){
        std::cout<<"Queue is empty. Cannot DEQUEUE"<<endl;
        return front;
    }
    int output = queue_Q[front];
    // move Queue towards left. 1 2 3 4 5
    // 2 3 4 5
    for(int i = front+1; i < rear; i++)
    {
        queue_Q[i-1] = queue_Q[i];
    }
    return output;
}


int main(){
    std::cout<<deQueue()<<std::endl; // Queue is empty
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    std::cout<<deQueue()<<std::endl; // returns 1 
    enQueue(10); /// Queue is full
    std::cout<<deQueue()<<std::endl; // returns 2
    std::cout<<deQueue()<<std::endl; // returns 3
    std::cout<<deQueue()<<std::endl; // returns 4
}