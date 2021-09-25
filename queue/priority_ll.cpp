/*
    Author : Kaiser Sakhi
    Date : 04-09-2021
    Environment : UBUNTU 20.04
*/

// Program : implementation of priority Queue using linked list

/*

    i was woking and it occured to me that i shold make a program like this
    Alhumdulilah, DONE!
    lets assume, lower number has higher priority

*/

#include <iostream>
#include <climits>
struct Node{
    std::string job;
    int priority;
    Node *next;
};

class PriorityQueueLL{
    Node *front;
    Node *rear;
    int length;
public:
    PriorityQueueLL(){
        this->front = this->rear = nullptr;
        this->length = 0;
    }
    
    bool enqueue(std::string job, int priority){
        Node *node = new Node;
        node->job = job;
        node->priority = priority;
        node->next = nullptr;

        // when queue is empty at this
        if (this->rear == nullptr){
            this->front = this->rear =node;
            ++length;
            return true;
        }else{

            Node *current = this->front;
            Node *tailingPtr = nullptr;

            // this loop will find the correct postion for the new node
            while(current != nullptr){
                if(current->priority <= node->priority){
                    tailingPtr = current;
                    current = current->next;
                    continue;
                }
                break;
            }
            
            if(current == this->front){
                // with this condition, tailingptr will be null
                node->next = current;
                this->front = node; 
                   
            }else if(tailingPtr == this->rear){
                // with this condintion , current will be null
                node->next = current;
                tailingPtr->next = node;
                this->rear = node;
            }else{
                // this means, element has to be inserted  somewhere in the middle
                node->next = current;
                tailingPtr->next = node;
            }
            ++length;
            return true;
        }

        return false;
    }

    Node dequeue(){
        Node de_node;
        de_node.job = "null";
        de_node.priority = INT16_MIN;
        de_node.next = nullptr;

        if (!this->isEmpty() ){
            Node *temp = this->front;
            de_node = *temp;

            if (this->front == this->rear)
                this->front = this->rear = nullptr;
            else
                this->front = this->front->next;

            delete temp;
            --this->length;
        }

        return de_node;
    }
    bool isEmpty(){
        return (this->rear == nullptr);
    }

    ~PriorityQueueLL(){
        if (this->rear != nullptr){

            Node *current = this->front;

            while(this->front != nullptr){
                current = this->front;
                this->front = this->front->next;
                delete current;
            }
        }
    }
};

int main(){
    PriorityQueueLL q;
    q.enqueue(std::string("Drink Kashir Tea"), 3);
    q.enqueue("Eat Apple!", 3); 
    // here, first of all i love kashir chai,
    // drink kashir tea will have more priority than eating apple, FCFS
    q.enqueue(std::string("Read a book"), 2);
    q.enqueue(std::string("Watch Intersteller or any other good movie"), 10);
    q.enqueue(std::string("Connect with ..."), 1);
    q.enqueue(std::string("Criticise my own self "), 4);

    for (int i = 1; i <= 7 ; ++i){
        std::cout<<i<<" : "<<q.dequeue().job<<"\n";
    }   

    return 0;
}