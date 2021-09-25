/*
    Author : Kaiser Sakhi
    Date : 25-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary search tree with linked representation

#include "./includes/binary_tree.h"

template <class T>
class BinarySeachTree : public BinaryTree<T>{
    /*
        Properties we have in base class
            TreeNode<Type> *root;
            int nodeCount;
            //QueueLL<TreeNode*>
            QueueLL<TreeNode<Type>*> *q; // queue is not needed here 
    */
public:

    BinarySeachTree(){
        delete BinaryTree<T>::q;
        BinaryTree<T>::q = nullptr;
    }

    bool insert(T element){

        TreeNode<T> *newNode = new TreeNode<T>;
        newNode->data = element;
        newNode->left_child = nullptr;
        newNode->right_child = nullptr;
    
        if (BinaryTree<T>::root == nullptr){
            BinaryTree<T>::root  = newNode;
            BinaryTree<T>::nodeCount++;
            return 1;
        }else{
            TreeNode<T> *current = BinaryTree<T>::root;
            TreeNode<T> *tailingPointer = nullptr;
            
            while(current != nullptr){
                if (current->data > newNode->data){
                    tailingPointer = current;
                    current = current->left_child;
                }else{
                    tailingPointer = current;
                    current = current->right_child;
                }
            }

            if (tailingPointer->data > newNode->data){
                tailingPointer->left_child = newNode;
            }else{
                tailingPointer->right_child = newNode;
            }
            ++BinaryTree<T>::nodeCount;

        }

        return 0;
    }
};

int main(){
    BinarySeachTree<int> bst;
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(15);
    bst.remove(20);
    bst.inorder();
    bst.levelOrder();
    return 0;
}