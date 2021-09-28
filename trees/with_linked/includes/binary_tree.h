/*
    Author : Kaiser Sakhi
    Date : 19-09-2021
    Environment : WSL Ubuntu 20
*/

// Program to implement a binary tree with linked representation

#include "../../tree_node.h"
#include "../../../queue/includes/queue_ll.h"
#include "../../../stack/includes/stack_ll.h"

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
        if(this->q != nullptr) 
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
    void inorder(){this->inorder_recursive(this->root); std::cout<<"\n";}
    void postorder(){this->postorder_recursive(this->root);  std::cout<<"\n";}

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


    //lets for now, only get the inorderpredecessor of root node only

    Type getRootInorderPredecessor(){
        Type res ;
        TreeNode<Type> *result =  this->getInorderPredecessor(this->root);
        if (result != nullptr) 
            return result->data;
        return res;
    }

    TreeNode<Type> *search(Type key){
        return this->search_lo(key);
    }

    void remove(Type key){
        TreeNode<Type> *res = this->search_lo(key);

        if (res == nullptr){
            return;
        }
        this->deleteNode(res);
    }



protected:
    void preorder_recursive(TreeNode<Type> *node){

        if(node != nullptr){
            std::cout<<node->data<<" ";
            preorder_recursive(node->left_child);
            preorder_recursive(node->right_child);
        }
    }

    void postorder_recursive(TreeNode<Type> *node){

        if(node != nullptr){
            postorder_recursive(node->left_child);
            postorder_recursive(node->right_child);
            std::cout<<node->data<<" ";
        }
    }

    void inorder_recursive(TreeNode<Type> *node){

        if(node != nullptr){
            inorder_recursive(node->left_child);
            std::cout<<node->data<<" ";
            inorder_recursive(node->right_child);
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


    TreeNode<Type>  *getInorderPredecessor(TreeNode<Type> *node){
        

        if (node == nullptr)
            return node;
        if (node->left_child == nullptr){
            // result = node->data;
            return node;
        }
        node = node->left_child;

        while (node->right_child != nullptr){
            node = node->right_child;
        }

        return node;
    }

    TreeNode<Type>  *getInorderSucessor(TreeNode<Type> *node){
        

        if (node == nullptr)
            return node;
        if (node->right_child == nullptr){
            // result = node->data;
            return node;
        }
        node = node->right_child;

        while (node->left_child != nullptr){
            node = node->left_child;
        }

        return node;
    }

    // TreeNode<Type> *search()
   

    TreeNode<Type>* search_lo(Type key){
       
       // for now lets assume key would be a premitive type
       /*
            This is a pure binary tree with only one restriction , i.e , a node can at atmost 2 childrens
            so, binary search will not work here, we have to use level order here to find a node
            or this is BREADTH FIRST SEARCH
       */


        if (this->root == nullptr) return this->root;

        if (this->root->data == key) return this->root;

        QueueLL<TreeNode<Type> *> q;
        q.enqueue(this->root);
        TreeNode<Type> *current = nullptr;
        while (!q.isEmpty()){
            current = q.dequeue();
            if (current == nullptr) continue;
            
            if(current->data == key) return current;

            if (current->left_child != nullptr)
                q.enqueue(current->left_child);
            if (current->right_child != nullptr)
                q.enqueue(current->right_child);
            
        }

        return nullptr;
    }

    void deleteNode(TreeNode<Type> *node){
        
        TreeNode<Type> *q = nullptr;

        if (node == nullptr) return;

        if (node->left_child == nullptr && node->right_child == nullptr){
            TreeNode<Type> *parent = this->getParent(node);

            if (parent == nullptr){
                // that means current node is the root node
                delete this->root;
                this->root = nullptr;
                this->nodeCount = 0;
                return;
            }
            if(parent->left_child == node){
                parent->left_child = nullptr;
            }else{
                parent->right_child = nullptr;
            }

            delete node;
            --this->nodeCount;
            return;

        }else{

            if (this->getHeight_recursive(node->left_child) > this->getHeight_recursive(node->right_child)){
                q = this->getInorderPredecessor(node);
                node->data = q->data;
                deleteNode(q);
            }else{
                q = this->getInorderSucessor(node);
                node->data = q->data;
                deleteNode(q);
            }
        }
    }//deleteNode ends here

        
    TreeNode<Type>* getParent(TreeNode<Type> *node){
 

        if (node != nullptr){
            if (node == this->root){
                return node;
            }
            TreeNode<Type> *current = nullptr;
            QueueLL<TreeNode<Type> *> q;
            q.enqueue(this->root);

            while(!q.isEmpty()){
                current = q.dequeue();
                if (current->left_child == node || current->right_child == node){
                    return current;
                }
                if (current->left_child != nullptr){
                    q.enqueue(current->left_child);
                }
                if (current->right_child != nullptr){
                    q.enqueue(current->right_child);
                }
            }
        }
        return nullptr;

    }

};






























