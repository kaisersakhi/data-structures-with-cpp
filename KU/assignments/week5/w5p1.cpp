/*
    Author : Kaiser Sakhi
    Date : 12-08-2021
    Environment : WSL Ubuntu 20
*/


//program to implement iterrative quick sort using stack 

#include <iostream>
#include <climits>


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





int partition(int, int);
void quickSort(int, int);
void swap(int*, int*);
void printArray();
int arr[] = {9, 8, 6, 12, 15, 2, 1, INT_MAX};

int main(){
    quickSort(0,7);
    printArray();
    return 0;
}

int partition(int l, int h){
    
    if (l < h){
        int i = l;
        int j = h;
        int pivot = arr[l];

        while( i < j){

            do { i++; }while(arr[i] < pivot);
            
            do {--j;  }while(arr[j] > pivot);

            if (i < j)
                swap(&arr[i], &arr[j]);
        }

        
        swap(&arr[l], &arr[j]);
        return j;
    }
    return -1;
}

void quickSort(int l, int h){
    
    Stack stack(10);
    // stack.push(h);
    stack.push(h);
    stack.push(l);
    int k = stack.peek();
    if (l < h){
        do{
            int a = stack.pop();
            int b = stack.pop();
            l = a;
            h = b;

            int j = partition(l, h);
                 //printArray();
           // h = j+1;
            printArray();
            if (j != -1){
                stack.push(h);
                stack.push(j+1);
                stack.push(j);
                stack.push(l);
            }
        //std::cout<<"Head "<<l<<" "<<j<<"\n";
        //std::cout<<"Tail "<<j+1<<" "<<h<<"\n";
       // quickSort(l,j); 
       // quickSort(j+1, h);
        }while(!stack.isEmpty());
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(){
     
    for (int i = 0; i < 7 ; ++i){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}