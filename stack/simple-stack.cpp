/*
    Author : Kaiser Sakhi
    Date : XX-08-2021
    Environment : WSL Ubuntu 20
*/

//Implemtation of stack

#include <iostream>

class Stack{
    int top;
    int size;
    int *stck;
    std::string recentError;

public:
    Stack(int size){
        
        if (size > 0){
            this->size = size;
            this->top = -1;
            this->stck = new int[this->size];

        }else{
            this->size = 0;
            this->top = -1;
            this->stck = nullptr;
        }
    }

    bool push(int element){

        if (this->isFull()){
            this->recentError = std::string("Stack Overflow!");
            return false;
            // stack is full or stack overflow
        }
        this->stck[++this->top] = element;
        return true;
    }

    int pop(){
        if (this->top < 0){
            this->recentError = std::string("Stack Underflow!");
            return -1;
        }
        
        //int popedElement = this->stck[this->top];
       // --this->top;
       return this->stck[this->top--];
    }

    bool isEmpty(){
        if (this->top < 0)
            return true;
        return false;
    }

    int peek(int index = -1){
        index = (index == -1) ? this->top : index;
        if (!this->isEmpty() && index >= 0 && index < this->size){
            return this->stck[index];
        }
        return -1;
    }

    bool isFull(){
        if (this->top == this->size -1)
            return true;
        return false;
    }
    void printRecentError(){
        std::cout<< this->recentError<<"\n";
    }

    ~Stack(){
        if (this->stck != nullptr){
            delete []this->stck;
        }
    }
};


int main(){
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    stack.push(90);
    
    for (int i = 0; i < 5 ; ++i){
        std::cout<<stack.pop()<<" ";
    }
    stack.pop();
    stack.printRecentError();
    std::cout<<std::endl;
    
    return 0;
}