/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/

// Write a program in C++ to find largest element in array
#include<iostream>
int getMax(int *, int);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int length = 9;
    std::cout<<"The largest in the array is : "<<getMax(arr, length);
    return 0;
}

int getMax(int *arr, int len){
    int maxi = arr[0];

    for (int i = 0 ; i < len ; ++i){
        if (arr[i] > maxi)
            maxi = arr[i];
    }

    return maxi;
}