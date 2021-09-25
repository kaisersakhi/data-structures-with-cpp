/*
    Author : Kaiser Sakhi
    Date : 17-08-2021
    Environment : WSL Ubuntu 20
*/
// Program : To implement multiple stack
#include<iostream>

class MultipleStack{
    int top1; 
    int top2;
    int size;
    int *stck;

public:

    MultipleStack(int size){

        if (size > 0 ){
            this->size = size;
            this->top1 = -1;
            this->top2 = (this->size / 2 ) - 1;
            this->stck = new int[this->size];
        }else{
            this->stck = nullptr;
        }
    }

    bool pushIntoStackOne(int element){
         if (!this->isStackOneFull()){
             this->stck[++top1] = element;
             return true;
         }
         return false;
    }

     bool pushIntoStackTwo(int element){
         if (!this->isStackTwoFull()){
             this->stck[++top2] = element;
             return true;
         }
         return false;
    }

    int popFromStackOne(){
        
        if (!this->isStackOneEmpty()){
            return this->stck[this->top1--];
        }
        return -1;
    }

    int popFromStackTwo(){
        
        if (!this->isStackTwoEmpty()){
            return this->stck[this->top2--];
        }
        return -1;
    }

    bool isStackOneFull(){
        if (this->top1 == (int)(this->size / 2 -1)){
            return true;
        }
        return false;
    }

    bool isStackTwoFull(){
        return (this->top2 == (int)(this->size - 1));
    }

    bool isStackOneEmpty(){
        return (this->top1 < 0);
    }
    bool isStackTwoEmpty(){
        return (this->top2 < (int)this->size / 2);
    }

    int peekAtStackOne(){
        if (!this->isStackOneEmpty()){
            return this->stck[this->top1];
        }
        return -1;
    }
    
    int peekAtStackTwo(){
        if (!this->isStackTwoEmpty()){
            return this->stck[this->top2];
        }
        return -1;
    }

    ~MultipleStack(){
        if (this->stck != nullptr)
            delete this->stck;
    }
};

int main(){
    MultipleStack stack(9);

    stack.pushIntoStackOne(1);
    stack.pushIntoStackTwo(4);

    std::cout<<"Peek at Stack one : "<<stack.peekAtStackOne()<<"\n";
    std::cout<<"Peek at Stack Two : "<<stack.peekAtStackTwo()<<"\n";
    return 0;
}