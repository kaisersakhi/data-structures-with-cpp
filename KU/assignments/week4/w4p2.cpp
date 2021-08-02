/*
    Author : Kaiser Sakhi
    Date : 02-08-2021
    Environment : Wsl Ubuntu 20
*/

#include "./stack.h"
#include <cstring>
bool matchBrackets(std::string);

int main(){
    std::string expression = "(( a + b ) * c ) * (d - e)";
    
    if (matchBrackets(expression))
        std::cout<<"Expression is perfect!\n";
    else 
        std::cout<<"Brakets do not match!";
    
    return 0;
}
bool matchBrackets(std::string exp){

    Stack stack(exp.size());

    
    for (auto i : exp){

        if (strcmp(&i, "(") == 0 ){
            stack.push(std::string(1,i));
        }else if (strcmp(&i, ")") == 0 ){
            if (stack.pop().length() == 0){
                return false;
            }
        }
    }
    if (stack.peek() == "")
        return true;
    return false;
}