
/*
    Author : Kaiser Sakhi
    Date : XX-08-2021
    Environment : WSL Ubuntu 20
*/
#include "../Linear/Arrays/includes/arrayList.h"
#include <iostream>

struct Stack{
    ArrayList<int> *arr;
    int size = 0;
    int top = -1;
}stck;

bool push(int element){
    if (stck.top < stck.size){
        // this means there is room to push new element
        ++stck.top;
        stck.arr->add(element);
        return true;
    }
    return false;

}

int pop(){
    if (stck.top >= 0){
        int el = stck.arr->get(stck.top);
        stck.arr->remove(stck.top);
        --stck.top;
        return el;
    }
    return -1;
}



int main(){
    stck.size  = 10;
    stck.arr = new ArrayList<int>(stck.size);

    push(1);
    push(22);
    push(77);

    for (int i = 0; i < 3 ; ++i){
        std::cout<<pop()<<" ";
    }    

    delete stck.arr;

    return 0;

}

