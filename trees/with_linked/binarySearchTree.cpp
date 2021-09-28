/*
    Author : Kaiser Sakhi
    Date : 25-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary search tree with linked representation

#include "./includes/bst.h"

int main(){
    BinarySeachTree<int> bst;
    bst.insertRecursive(20);
    bst.insertRecursive(10);
    bst.insertRecursive(30);
    bst.insertRecursive(15);
    bst.remove(20);
    bst.inorder();
    bst.levelOrder();
    return 0;
}