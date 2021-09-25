/*
    Author : Kaiser Sakhi
    Date : 03-09-2021
    Environment : UBUNTU 20.04
*/

// Program : implementation of circular queue using array


#include<iostream>

class CircularQueue{
    int *que;
    int front;
    int rear;
    int size;
    
public:
    CircularQueue(unsigned int size){
        // +1 for the location which will be ocuppied by front pointer
        this->size = size + 1;
        this->que = new int[this->size]; 
        
        this->front = this->rear = 0;
        
    }

    bool enqueue(int element){
        
        if (this->isFull()){
            std::cout<<"Failed to enqueue, queue is full !\n";
            return 0;
        }
        this->rear = (this->rear + 1 ) % this->size;
        this->que[this->rear] = element;
        return true;
    }

    int dequeue(){
        
        if (this->isEmpty()){
            std::cout<<"Queue is already empty!\n";
             return -1;
        }
        this->front = (this->front + 1) % this->size;
        return this->que[this->front];
    }
    bool isEmpty(){
        return (this->front == this->rear);
    }
    bool isFull(){
        return (this->rear + 1 ) % this->size == this->front;
    }

    void printAll(){
        if (this->isEmpty()){
            return;
        }
        int i = this->front;

        while (i != this->rear){
            i = (i + 1) % this->size;
            std::cout<<this->que[i]<<" ";
        }
    }
    ~CircularQueue(){
        if (this->que != nullptr)
            delete[] this->que;
    }

};

int main(){
    CircularQueue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.enqueue(6);
    q.printAll();
    return 0;
}