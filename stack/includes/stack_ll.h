

/*
    Author : Kaiser Sakhi
    Date : 10-08-2021
    Environment : WSL Ubuntu 20
*/
#include<iostream>


// stack implementation using linked list
template <class Type>
struct StackNode{
    Type data;
    StackNode *next;
};

template <class Type>
class StackLL{
    StackNode<Type> *top;
    int size;
    int topIndex;

public:

    StackLL(int size){
        this->top = nullptr;
        this->size = size; 
        this->topIndex = -1;
    }

    bool push(Type element ){

        if (this->topIndex < this->size){
            StackNode<Type> *newNode = new StackNode<Type>;
            newNode->data = element;
            newNode->next = nullptr;

            if (this->top == nullptr){
                this->top = newNode;
                ++this->topIndex;
                return 1;
            }

            newNode->next = this->top;
            this->top = newNode;
            ++this->topIndex;
            return 1;
        }

        return 0;

    }

    Type pop(){
        Type el;
        if (this->topIndex >= 0){
            el =  this->top->data;
            StackNode<Type> *temp = this->top;
            this->top = this->top->next;
            --this->topIndex;
            delete temp;
        }
        return el;
    }

    Type peek(int index  = 0){
        //peek will always return top if index is not specifed 
        Type el;
        if (index >= 0 && index <= this->topIndex){
            StackNode<Type> *current = this->top;
            for (int i = 0; i < index ; ++i){
                current = current->next;
            }
            el = current->data;
        }
        return el;
    }


    bool isEmpty(){
        return (this->topIndex < 0);
    }
    bool isFull(){
        return (this->topIndex >= this->size);
    }

    ~StackLL(){

        if (this->top != nullptr){
            StackNode<Type> *temp = nullptr;
            while(top != nullptr){
                temp = this->top;
                this->top = this->top->next;
                delete temp;
            }

        }
    }

};