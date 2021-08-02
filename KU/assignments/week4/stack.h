/*
    Author : Kaiser Sakhi
    Date : 02-08-2021
    Environment : Wsl Ubuntu 20
*/


#include <iostream>

class Stack{
    std::string *stck;
    int size;
    int top;

public:
    Stack(unsigned int size){
        if (size < 100){
            this->size = size;
            this->stck = new std::string[this->size];
            this->top = -1;
        }
    }

    bool push(std::string data){

        if (this->top < this->size){
            this->stck[++this->top] = data;
            return 1;
        }
        return 0;
    }

    std::string pop(){

        if (this->top > -1)
            return this->stck[this->top--];
        
        return std::string("");
    }

    std::string peek(){
        if (this->top > -1){
            return this->stck[this->top];
        }
        return std::string("");
    }

    ~Stack(){
        if (this->size > 0){
            delete []this->stck;
        }
    }
    
};