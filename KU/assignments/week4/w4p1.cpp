/*
    Author : Kaiser Sakhi
    Date : 02-08-2021
    Environment : Wsl Ubuntu 20
*/

#include "./stack.h"

int main(){

    Stack stack(10); // i want a stack of size 10
    stack.push(std::string("Bhat"));
    stack.push(std::string("Sakhi"));
    stack.push(std::string("Kaiser"));

    for (int i = 0; i < 3 ; ++i){
        std::cout<<stack.pop()<<" ";
    }
    std::cout<<std::endl;
    return 0;
}