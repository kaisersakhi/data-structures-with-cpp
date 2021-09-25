/*
    Author : Kaiser Sakhi
    Date : 03-09-2021
    Environment : UBUNTU 20.04
*/

// Program : implementation of queue using array

#include<iostream>
#include<climits>

class QueueArray{
    int *que;
    int front;
    int rear;
    int size;
public:
    QueueArray(int size){

        if (size > 0){
            this->que = new int[size];
            this->front = -1;
            this->rear = -1;
            this->size = size;
        }else{
            this->que = nullptr;
            this->front = -1;
            this->rear = -1;
            this->size = 0;
        }
    }
    bool enqueue(int element){

        if (this->isFull() || this->que == nullptr){
            std::cout<<"Failed to enqueue, queue is either full or non-instantiated!\n";
            return false;
        }
        this->que[++this->rear] = element;
        return true;
    }
    int dequeue(){
        
        if (this->isEmpty() || this->que == nullptr){
            std::cout<<"Queue is already empty!\n";
            return INT16_MIN;
        }
        return this->que[++this->front];
    }

    int getFrontElement(){
        if (!this->isEmpty())
            return (this->que[this->front + 1]);
        return -1;
    }
    int getRear(void){
        if (!this->isEmpty())
            return (this->que[this->rear]);
        return -1;
    }
    bool isFull(){
        return (this->rear == this->size -1);
    }
    bool isEmpty(){
        return (this->front == this->rear);
    }

    int operator[](int index){
        if (index >= 0 && index < this->size && !this->isEmpty()){
            return this->que[index];
        }
        std::cout<<"\nError : Accessing queue out of bounds!\n";
        return -1;
    }

    ~QueueArray(){
        if (this->que != nullptr){
            delete[] this->que;
        }
    }
};

int main(){

    QueueArray q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    // for (int i = 0; i < 6 ; ++i){
    //     std::cout<<q[i]<<" ";
    // }
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<q.dequeue()<<"\n";
    std::cout<<std::endl;
    return 0;
}


/*

    Drawbakc of implementing a queue using an array

    1.  Queue can be full and empty at the same time , mean, when we 
    are dequeueing we are moving foraward to the end ,
    dequeuing all the element after queue is full, gives rise to this condition

    2. Every Location can be used only once


    SOLUTIONS TO THE ABOVE ISSUES 

        1.  Ressetin the pointer, when front and rear pointer are pointing to the end
        of the queue, rest the pointer to start again
            ->this methos doesn't gurantee, using of empty locations

        2. Circular Queue

    and the best solution is CIRCULAR QUEUE, LETS DO IT!


*/