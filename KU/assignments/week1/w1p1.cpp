/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/

// Write a program in C++ to Reverse an Array


#include <iostream>



void reverse(int *);
void display(int *);
void swap(int *, int *);

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    std::cout<<"Before Reversing the array: ";
    display(arr);
    reverse(arr);
    std::cout<<"\nAfter Reversing the array: ";
    display(arr);
    return 0;
}

void display(int *arr){
    for (int i = 0 ; i < 9 ; ++i){
        std::cout<<arr[i]<<" ";
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int *arr){
    int i = 0, j = 8 ;

    while (i < j){
        swap(&arr[i], &arr[j]);
        ++i;
        --j;
    }
}

