

#include<iostream>
#include<cmath>
class ArrayBT{
    int size;
    int *a_tree;
    int index;
public :
    ArrayBT(int size){
        this->size = size;
        this->a_tree = new int[this->size];
        this->index = -1;
    }

    bool insert(int el){

        if (this->index == this->size -1){
            // no room for new elements in array
            return 0;
        }

     
        this->a_tree[++this->index] = el;
        return 1;
        
    }

    void initialize(int value = 0){
        for (int i = 0; i < this->size ; ++i)   
            this->a_tree[i] = value;
    }

    void printAll(){
        /*

    //     */

       //i will go from 0 to floor(log(this->size))
       std::string spaces = "   ";
       for (int i = 0 ; i < 2; ++i){

           if (i == 0)
            std::cout<<"                       "<<this->a_tree[i]<<"\n";

           for (int k = 0; k < this->size * 2 - this->size - i; ++k){
               std::cout<<"   ";
           }
            int l = i ;

           for (int j = 0 ; j <pow(2,i) ; j++){
               if (l > this->size) return;
               printChildrens(l,spaces);
               ++l;
               
                // std::cout<<this->a_tree[2*i+1];
                // std::cout<<spaces<<this->a_tree[2*i+2]<<" ";
                spaces+= " ";
                // ++i;
           }
           
           std::cout<<std::endl;
       }

    // for (int i = 0; i < this->size; ++i){
        
    // }
    }

    void preorder(){this->preorder_recursive(0);}
    void inorder(){this->inorder_recursive(0);}
    void postorder(){this->postorder_recursive(0);}
    ~ArrayBT(){
        delete[] this->a_tree;
    }


private:
    void printChildrens(int i , std::string s){
        
        // std::cout<<this->a_tree[i]<<"\n";
        if (2*i+1 >= this->size) return ;
        std::cout<<this->a_tree[2*i+1]<<s<<this->a_tree[2*i+2]<<" ";
    }

    void preorder_recursive(int index){
        if (this->a_tree[index] != 0 && index < this->size){
            std::cout<<this->a_tree[index]<<" ";
            preorder_recursive(2*index+1);
            preorder_recursive(2*index+2);
        }
    }
    
    void inorder_recursive(int index){
        if (this->a_tree[index] != 0 && index < this->size){
            inorder_recursive(2*index+1);
            std::cout<<this->a_tree[index]<<" ";
            inorder_recursive(2*index+2);
        }
    }
    void postorder_recursive(int index){
        if (this->a_tree[index] != 0 && index < this->size){
            postorder_recursive(2*index+1);
            postorder_recursive(2*index+2);
            std::cout<<this->a_tree[index]<<" ";
        }
    }

};

int main(){
    ArrayBT tree(7);
    tree.initialize();
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.printAll();
    std::cout<<"\n Preorder Traversal :- ";
    tree.preorder();
    std::cout<<"\n";
    std::cout<<"\n Inorder Traversal :- ";
    tree.inorder();
    std::cout<<"\n";
    std::cout<<"\n Postorder Traversal :- ";
    tree.postorder();
    std::cout<<"\n";
    return 0;
}

