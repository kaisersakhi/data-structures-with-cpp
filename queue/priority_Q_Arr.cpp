/*
    Author : Kaiser Sakhi
    Date : 04-09-2021
    Environment : UBUNTU 20.04
*/

// Program : implementation of priority Queue using array

/*

    lets assume, lower number has higher priority

*/
#include <iostream>

class PriorityQueue{
private:
    int *que;
    unsigned int size;
    int front;
    int rear;
public:
    PriorityQueue(unsigned int size){
        this->size = size;
        this->que = new int[this->size];
        this->front = this->rear = -1;
    }

    bool enqueue(int element){
        if (!this->isFull()){
            if (this->isEmpty()){
                this->que[++this->rear] = element;
                return true;
            }

            int index = this->front;

            // this loop will find the proper position of the element in the queue;
            // index will before the the element is greater than the cureent 
            while((index ) < this->rear){
                if (this->que[index + 1] > element){
                    ++index;
                    break;
                }
                ++index; 
            }
        
            // we have to insert element at index + 1

            // but before that, we need to shift all the elements to the right 

            // shift all elements from index+1 to rear+1
            // if elements 
            if (index == this->rear){
                // if index is same as rear, that means there is no element to be shifted
                // the elementtt  to be inserted has the lowest priority of all elements
                // only increment index
                ++index; 
            }else{
                // else, if index < rear, that means we found the  location before rear 
                for (int i = this->rear + 1  ; i > index ; --i){
                    this->que[i] = this->que[i-1];
                }
            }
            ++this->rear;
            //  at this point we will have vacant postion in the queue where 
            // the elemetn should be inserted , according to its priority
            // and if the element has same priority then the element will
            // be insert on FCFS basis

            this->que[index] = element;
            return true;             
        }
        return false;
    }

    int dequeue(){
        if (this->isEmpty()) return -1;

        return this->que[++this->front];
    }

    bool isEmpty(){
        return (this->rear == this->front);
    }

    bool isFull(){
        return (this->rear == this->size -1);
    }

    void printAll(void){

        for (int i = this->front + 1 ; i <= this->rear ; ++i){
            std::cout<< this->que[i] << " ";
        }
        std::cout<<std::endl;
    }

    ~PriorityQueue(){
        // if(this->que != nullptr)
        //     delete this->que;
    }
};

int main(){
    PriorityQueue pq(5);
    pq.enqueue(5);
    pq.enqueue(6);
    pq.enqueue(1);
    pq.enqueue(2);
    pq.enqueue(7);
    pq.printAll();
    std::cout<<pq.dequeue()<<" \n";
    std::cout<<pq.dequeue()<<" \n";
    std::cout<<pq.dequeue()<<" \n";
    std::cout<<pq.dequeue()<<" \n";
    std::cout<<pq.dequeue()<<" \n";
    std::cout<<pq.dequeue()<<" \n";

    return 0;
}