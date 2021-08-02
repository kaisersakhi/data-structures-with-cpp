/*
    Author : Kaiser Sakhi
    Date : 16-JUN-2021
    Environment : WSL UBUNTU20
*/

//Resizeable Array

//YT PlayList :- https://www.youtube.com/playlist?list=PLZBpoXlqdg16v1VrwrT6PVZIOpD2zwHNq : with Name Dynamic Array

#include <iostream>
#include "includes/arrayList.h"

int main(){
    ArrayList kaiser(5);
    for (int i = 5; i >= 1; --i){
        kaiser.add(i);
    }

    //kaiser.remove(1);

    //std::cout<<"Over FLow Elmemnt : "<< kaiser.shiftRight()<<"\n";
   // kaiser.rotateRight();
    kaiser.reverse();
    // kaiser.popAll();
    for (int i = 0 ; i < kaiser.length(); i++){
        std::cout<<kaiser.get(i)<<"\n";
    }

    //std::cout<<"Minimum is : "<<kaiser.min()<<"\n";

    return 0;
}
