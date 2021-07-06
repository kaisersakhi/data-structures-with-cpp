/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/

// Write a program in C++ to find smallest element in array
#include<iostream>
int getMin(int *, int);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int length = 9;
    std::cout<<"The smallest in the array is : "<<getMin(arr, length);
    return 0;
}

int getMin(int *arr, int len){
    int mini = arr[0];

    for (int i = 0 ; i < len ; ++i){
        if (arr[i] < mini)
            mini = arr[i];
    }

    return mini;
}