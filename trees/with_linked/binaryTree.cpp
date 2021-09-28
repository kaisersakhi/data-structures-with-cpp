/*
    Author : Kaiser Sakhi
    Date : 19-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary tree with linked representation
#include "./includes/binary_tree.h"

int main(){
    BinaryTree<int> bt;
    bt.insert(20);
    bt.insert(15);
    bt.insert(25);
    bt.insert(10);
    bt.insert(18);    
    bt.insert(22);
    bt.insert(30);
    bt.insert(9);
    // this will skip 2 as being the parent of 4 & 5,  
    // i use paper to do 
    // bt.skipCurrentParent(); 
    // bt.skipCurrentParent(); 
    // bt.insert(8);
    // bt.insert(9);
    std::cout<<"Recursive Preoder : ";
    bt.preorder();
    std::cout<<"Iterative Preoder : ";
    bt.iterative_preorder();
    std::cout<<"Level Order Traversal : ";
    bt.levelOrder();
    std::cout<<"Height Of The Tree is : "<<bt.getHeight()<<"\n";

    std::cout<<"Inorder Predecessor of Root is : "<<bt.getRootInorderPredecessor()<<"\n";

    std::cout<<"Searching.... for 5\n";
    TreeNode<int> *temp = bt.search(5);
    if (temp != nullptr){
        // that means we found the elemetn in the tree
        std::cout<<"Element Found! \n";
    }else{
        std::cout<<"Element Not Found!\n";
    }

    std::cout<<"Deleting.... 2\n";
    bt.remove(20);
    bt.levelOrder();
    std::cout<<"\n";
    return 0;
}

