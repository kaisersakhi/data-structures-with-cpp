/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/


// program to reverse a string 

#include<iostream>
#include<cstring>

void strReverse(char *);

int main(){
    char name[] = "Kaiser Sakhi Bhat";
    std::cout<<"String Before Reverse : "<<name;
    strReverse(name);
    std::cout<<"\nString After Reverse : "<<name;

    return 0;
}

void strReverse(char *str){
    int len = strlen(str);
    int i = 0, j = len -1;
    char temp;
    while(i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        ++i;
        --j;
    }
}

