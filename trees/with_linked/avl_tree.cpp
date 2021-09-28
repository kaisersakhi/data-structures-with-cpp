/*
    Author : Kaiser Sakhi
    Date : 26-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary search tree with linked representation

#include "./includes/bst.h"


template<class T>
class AVL : public BinarySeachTree<T>{
public:
    void insert(T d){
        BinaryTree<T>::root = this->insert_recursive(BinaryTree<T>::root,d);
    }

    // int getHeight(){
    //     return this->getNodeHeight(BinaryTree<T>::root);
    // }

protected:
    TreeNode<T>* insert_recursive(TreeNode<T> *node, T data){

        if (node == nullptr){
            BinaryTree<T>::nodeCount++;
            return new TreeNode<T>(data, nullptr, nullptr,1);
        }
        if (data < node->data){
            node->left_child = insert_recursive(node->left_child,data);
        }else{
            node->right_child = insert_recursive(node->right_child, data);
        }

        node->node_height = this->getNodeHeight(node);

        int balanceFactorOfParent = this->getBalancingFactor(node);
        int balanceFactorOfLeftSubtree = this->getBalancingFactor(node->left_child);
        int balanceFactorOfRightSubtree = this->getBalancingFactor(node->right_child);


        // std::cout<<"Balance Factor of '"<<node->data<<"' is "<<balanceFactorOfParent<<"\n";

        if (balanceFactorOfParent == 2 && balanceFactorOfLeftSubtree == 1){
            //Perform LL rotation
            std::cout<<"Performing LL Rotation.... \n";
            return LL_Rotation(node);

        }else if (balanceFactorOfParent == 2 && balanceFactorOfLeftSubtree == -1){
            //Perform LR rotation
            std::cout<<"Performing LR Rotation.... \n";
            return LR_Rotation(node);

        }else if (balanceFactorOfParent == -2 && balanceFactorOfRightSubtree == -1){
            
            //Perform RR rotation
            std::cout<<"Performing RR Rotation.... \n";
            return RR_Rotation(node);

        }else if (balanceFactorOfParent == -2 && balanceFactorOfRightSubtree == 1){
            
            //Perform RL rotation
            std::cout<<"Performing RL Rotation.... \n";
            return RL_Rotation(node);
        }

        return node;
    } // insert function ends here

    int getNodeHeight(TreeNode<T> *node){
        int leftHeight;
        int rightHeight;

        leftHeight = (node != nullptr && node->left_child != nullptr) ? node->left_child->node_height : 0;
        rightHeight = (node != nullptr && node->right_child != nullptr) ? node->right_child->node_height : 0;

        return (leftHeight > rightHeight ) ? leftHeight + 1 : rightHeight + 1;

    }

    int getBalancingFactor(TreeNode<T> *node){
        int leftHeight;
        int rightHeight;

        leftHeight = (node != nullptr && node->left_child != nullptr) ? node->left_child->node_height : 0;
        rightHeight = (node != nullptr && node->right_child != nullptr) ? node->right_child->node_height : 0;

        return leftHeight - rightHeight;
    }

    TreeNode<T> *LL_Rotation(TreeNode<T> *p){
        TreeNode<T> *q = p->left_child;
        TreeNode<T> *r = q->right_child;

        q->right_child = p;
        p->left_child = r;

        p->node_height = this->getNodeHeight(p);
        q->node_height = this->getNodeHeight(q);

        if (BinaryTree<T>::root == p){
            BinaryTree<T>::root = q;
        }

        return q;
    }
    TreeNode<T> *LR_Rotation(TreeNode<T> *p){
        TreeNode<T> *q = p->left_child;
        TreeNode<T> *r = q->right_child;

        p->left_child = r->right_child;
        q->right_child = r->left_child;
        r->right_child = p;
        r->left_child = q;

        p->node_height = this->getNodeHeight(p);
        q->node_height = this->getNodeHeight(q);
        r->node_height = this->getNodeHeight(r);
        if (BinaryTree<T>::root == p){
            BinaryTree<T>::root = r;
        }

        return r;
    }
    TreeNode<T> *RR_Rotation(TreeNode<T> *p){
        TreeNode<T> *q = p->right_child;
        TreeNode<T> *r = q->left_child;

        p->right_child = q->left_child;
        q->left_child = p;

        p->node_height = this->getNodeHeight(p);
        q->node_height = this->getNodeHeight(q);

        if (BinaryTree<T>::root == p){
            BinaryTree<T>::root = q;
        }

        return q;
    }
    TreeNode<T> *RL_Rotation(TreeNode<T> *p){
        TreeNode<T> *q = p->right_child;
        TreeNode<T> *r = q->left_child;

        p->right_child = r->left_child;
        q->left_child = r->right_child;
        r->left_child = p;
        r->right_child = q;

        p->node_height = this->getNodeHeight(p);
        q->node_height = this->getNodeHeight(q);
        r->node_height = this->getNodeHeight(r);
        if (BinaryTree<T>::root == p){
            BinaryTree<T>::root = r;
        }

        return r;
    }
};


int main(){
    AVL<int> avlTree;
    avlTree.insert(5);
    avlTree.insert(10);
    avlTree.insert(20);
    avlTree.insert(30);
    avlTree.insert(35);
    avlTree.insert(40);
    avlTree.insert(45);
    avlTree.insert(50);
    avlTree.insert(55);
    avlTree.insert(60);
    avlTree.insert(65);
    avlTree.insert(70);
    avlTree.insert(75);
    avlTree.insert(80);
    avlTree.insert(85);
    avlTree.insert(90);
    avlTree.insert(95);
    avlTree.insert(4);
    avlTree.insert(3);
    avlTree.insert(2);
    avlTree.insert(1);
    avlTree.insert(37);
    avlTree.insert(36);
    // avlTree.insert(2);
    // avlTree.insert(1);
    
    std::cout<<"Height of tree is : "<<avlTree.getHeight()<<" \n";
    std::cout<<"Level Order is : ";
    avlTree.levelOrder();
    std::cout<<"Inorder is : ";
    avlTree.inorder();
    std::cout<<"Preorder is : ";
    avlTree.preorder();
    std::cout<<"Postorder is : ";
    avlTree.postorder();

    return 0;

}