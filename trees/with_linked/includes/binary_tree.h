/*
    Author : Kaiser Sakhi
    Date : 19-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary tree with linked representation

#include "../tree_node.h"
#include "../../queue/includes/queue_ll.h"
#include "../../stack/includes/stack_ll.h"

template <class Type>
class BinaryTree{

protected:
    TreeNode<Type> *root;
    int nodeCount;
    //QueueLL<TreeNode*>
    QueueLL<TreeNode<Type>*> *q;
public:
    BinaryTree(){
        this->root = nullptr;
        this->nodeCount = 0;
        this->q = new QueueLL<TreeNode<Type>*>;
    }

    //skipCurrentParent , is a fn which i will use for skiping a node , which 
    //may become parent of new node , this will help me in not making a tree complete
    void skipCurrentParent(){   
        if (!this->q->isEmpty())
            this->q->dequeue();
    }

    bool insert(Type element){
        
        //first crete new node 
        TreeNode<Type> *newNode = new TreeNode<Type>;
        newNode->data = element; // set the data for the new node
        newNode->left_child = newNode->left_child = nullptr; // set both left and right childrens to null

        // if root is null, that means , tree is empty 
        if (root == nullptr){
            // if root is null, then this is the first element for the tree
            this->root = newNode;
            ++this->nodeCount;
            // after setting the root, enqueue the new newNode
            this->q->enqueue(this->root);
            // return true;
            return 1;
        }else{
            // else, if root is not null, that means there is/are some node[s] in the tree;
            // that also means there are nodes inside the frontier
            // then get the front from the queue
            TreeNode<Type> *current = this->q->getFront();
            // if for some resons current is null , return false;
            if (current == nullptr)
                return 0;
            
            // if current of left chilc is null, then make it point to newNode
            if(current->left_child == nullptr){
                current->left_child = newNode;
                ++this->nodeCount;
                // also enqueu this
                this->q->enqueue(newNode);
                return 1;
            }else{
                // else if left is not null, then right is 
                current->right_child = newNode;
                ++this->nodeCount;
                //enqueu newNode
                this->q->enqueue(newNode);
                //dequeue current node
                this->q->dequeue();
                return 1;
            }
        }
        return 0;
    }

    void preorder(){this->preorder_recursive(this->root); std::cout<<"\n";}


    ~BinaryTree(){
        delete this->q;

        if (this->root != nullptr){
            // QueueLL<TreeNode<Type>*> tempQ;
            this->removeAllNode_recursive(this->root);
        }

    }

    int getHeight(){return this->getHeight_recursive(this->root);}

    void iterative_preorder(){
        if (this->root != nullptr){
            StackLL<TreeNode<Type> *> stack(this->nodeCount);
            TreeNode<Type> *current = this->root;

            while (current != nullptr || !stack.isEmpty()){

                if (current != nullptr){
                    std::cout<<current->data<<" ";
                    stack.push(current);
                    current = current->left_child;
                }else{
                    current = stack.pop();
                    current = current->right_child;
                }
            }
            std::cout<<std::endl;
        }
    }

    void levelOrder(){
        
        if(this->root != nullptr){

            QueueLL<TreeNode<Type> *> q;

            q.enqueue(this->root);
            TreeNode<Type> *temp = nullptr;
            while(!q.isEmpty()){
                temp = q.dequeue();
                std::cout<<temp->data<<" ";
                if (temp->left_child != nullptr)
                    q.enqueue(temp->left_child);
                if (temp->right_child != nullptr)  
                    q.enqueue(temp->right_child);
            }
            std::cout<<std::endl;
        }
    }

protected:
    void preorder_recursive(TreeNode<Type> *node){

        if(node != nullptr){
            std::cout<<node->data<<" ";
            preorder_recursive(node->left_child);
            preorder_recursive(node->right_child);
        }
    }

    void removeAllNode_recursive(TreeNode<Type> *node){
        if (node != nullptr){
            removeAllNode_recursive(node->left_child);
            removeAllNode_recursive(node->right_child);
            delete node;
        }
    }

    int getHeight_recursive(TreeNode<Type> *node){
        int x, y;
        
        if (node != nullptr){
            x = getHeight_recursive(node->left_child);
            y = getHeight_recursive(node->right_child);

            if (x > y)
                return x + 1;
            else 
                return y + 1;
        }
        return 0;
    } 

};