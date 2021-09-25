/*
    Author : Kaiser Sakhi
    Date : 19-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary tree with linked representation
#include "./includes/binary_tree.h"

int main(){
    BinaryTree<int> bt;
    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    // this will skip 2 as being the parent of 4 & 5,  
    // i use paper to do 
    bt.skipCurrentParent(); 
    bt.insert(4);
    bt.insert(5);
    std::cout<<"Recursive Preoder : ";
    bt.preorder();
    std::cout<<"Iterative Preoder : ";
    bt.iterative_preorder();
    std::cout<<"Level Order Traversal : ";
    bt.levelOrder();
    std::cout<<"Height Of The Tree is : "<<bt.getHeight()<<"\n";
    return 0;
}

