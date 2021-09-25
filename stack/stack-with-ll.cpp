/*
    Author : Kaiser Sakhi
    Date : XX-08-2021
    Environment : WSL Ubuntu 20
*/

#include "./includes/stack_ll.h"

int main(){

    StackLL<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    std::cout<<stack.peek(2)<<"\n";
    for (int i = 0; i < 5; ++i){
        std::cout<<stack.pop()<<" ";
    }
    



    return 0;
}