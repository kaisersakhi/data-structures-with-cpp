/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/

// write a program in c++ to compare 2 strings 

#include<iostream>
#include<cstring>

bool compare(char *, char *);

int main(){
    char st1[] = "Kaiser";
    char st2[] = "kaiser";
    if (compare(st1, st2)){
        std::cout<<st1<< " and " << st2 << " are same!";
    }else{
        std::cout<<st1<< " and " << st2 << " are not same!";
    }
    return 0;
}

bool compare(char *str1,char *str2){
    if (strlen(str1) != strlen(str2))
        return false;

    for (int i = 0, j = 0 ;  str1[i] != '\0' ; ++i, ++j){
        if (tolower(str1[i])!= tolower(str2[j])){
            return false;
        }
    }
    return true ;
}