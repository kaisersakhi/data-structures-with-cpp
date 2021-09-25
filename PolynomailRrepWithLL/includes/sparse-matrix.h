/*
    Author : Kaiser Sakhi
    Date : 03-08-2021
    Environment : Wsl Ubuntu 20

*/


#include "./../../LinkedList/includes/singlyLinkedList.h"
#include "./../../Linear/Arrays/includes/matrix.h"


struct Item{   // [ col | data | nextPtr]
    int col;
    int data; 
    Item *next;

    //friend std::ostream &operator<< (std::ostream &out,Item &item);
};

// std::ostream &operator<< (std::ostream &out, Item &item){
//     out<<item.col<< " "<<item.data;
//     return out;
// }




class SparseMatrixLL{
    int rowSize;
    int colSize;
    int size; // no of non zero elements
    Item **itemArray;



public:

    SparseMatrixLL(int rowSize, int colSize){
        this->rowSize = rowSize;
        this->colSize = colSize;
        this->size = 0;
        itemArray = new Item*[rowSize]; // create pointer array of items 
    }

    SparseMatrixLL(Matrix &mat){
        this->rowSize = mat.getRowSize();
        this->colSize = mat.getColSize();
        this->size = 0; // no. of non zero elements
        itemArray = new Item*[this->rowSize];

        Item *current = nullptr;
        for (int i = 0; i < this->rowSize; ++i){

            for (int j = 0 ; j < this->colSize ; ++j){

                if (mat.get(i, j) != 0){

                    // if current is null , that means , this is going to be the first node in the row list 
                    // then direactly attach this node
                    if (current == nullptr){

                        itemArray[i] = new Item;
                        itemArray[i]->col = j;
                        itemArray[i]->next = nullptr;
                        itemArray[i]->data = mat.get(i,j);  
                        current = itemArray[i];  
                        ++this->size;

                    }else{

                        // else, attach to current's next 
                        current->next = new Item;
                        current = current->next;
                        current->col = j;
                        current->data = mat.get(i, j);
                        current->next = nullptr;
                        ++this->size;

                    }
                }
            }
            // make current null after each row, because it should only point to CURRENT row's list
            current = nullptr;
        }
    }


    void display(){

        if (this->size > 0){
            Item *current = nullptr;

            for (int i = 0 ; i < this->rowSize; ++i){

                current = itemArray[i];

                for (int j = 0; j < this->colSize ; ++j){
                    
                    //i = some ; j = some 
                    if (current != nullptr){

                        if (current->col == j){
                            std::cout<<current->data<<" ";
                            current = current->next;
                            continue;
                        }
                        
                    }
                    std::cout<<0<<" ";

                    
                }
                std::cout<<"\n";
            }

        }
    }

    SparseMatrixLL *operator+(SparseMatrixLL &list2){

        SparseMatrixLL *sum = nullptr; 

        if (this->rowSize == list2.rowSize && this->colSize == list2.colSize){

            Item *p = nullptr; // p will point to each node in each colum of each row, of list 1
            Item *q = nullptr; // q will point ot each node in each colum of each row, of list 2
            Item *current = nullptr; // current will point to sum list

            sum = new SparseMatrixLL(this->rowSize, this->colSize); // create the list, with rowsize

            // simple N^2 loop
            for (int i = 0 ; i < this->rowSize; ++i){
                p = this->itemArray[i]; //  first make p point to list1
                q = list2.itemArray[i]; // q point ot list2
                
                for (int j = 0 ; j < this->colSize ;  ++j){

                    // if p and q are both null, that means , there is nothing to be added 
                    // and break the loop nad continue to the next row
                    if (p == nullptr && q == nullptr ){
                        break;
                    }
                    
                     Item *newItem = new Item;
                     
                        // newItem->data = 
                     newItem->next = nullptr;
                    
                    if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) { // exclusive or
                        // if control is here, that means either p is or q is null , but not both
                    
                        // if p is not null, then append p's data to sum mat directly
                        if(p != nullptr){
                            newItem->data = p->data;
                            newItem->col = p->col;
                        }else{ // if p is null, that means , q is not null, then append q's data to sum list directly
                            newItem->data = q->data;
                            newItem->col = q->col;
                        }
                        // now we have to attach newItem to the list
                        // if current is null , that means there is no item in the list
                        // then directly attach newItem to array[i], 
                        if (current == nullptr){// if current is null 
                            sum->itemArray[i] = newItem;
                            current = newItem;
                        }else{
                            // if current is pointin on something , then attach to its next
                            current->next = newItem;
                            current = newItem;
                        }
                        // increment size of sum list
                        ++sum->size;


                    }else{ // there is possiblity to add the nodes
                        /*
                            we already checked all the possible null's with p and q
                            #1->P and Q are both nul
                            #2->Either P is null Or Q is null
                            Now, if control is in this block that means, both  P and Q are not null 
                        */

                        // Now check column positions 
                        if (p->col < q->col ){ // if p is preceeding q, then add p's data
                           newItem->data = p->data;
                           newItem->col = p->col;
                           p = p->next;

                        }else if (p->col > q->col){ // if q is preceeding p, then add q's data

                           newItem->data = q->data;
                           newItem->col = q->col;
                           q = q->next;

                        }else if( p->col == q->col ){ // if both p and q are on same column, then add them 
                            // and insert the sum in newItems data 
                         
                           newItem->data = p->data + q->data;
                           newItem->col = p->col;
                           p = p->next;
                           q = q->next;

                        }
                        // }else{ // if none of the above conditions met, that means 

                        //     delete newItem;
                        //     continue;
                        // }

                        if (current == nullptr){// if current is null 
                            sum->itemArray[i] = newItem;
                            current = newItem;
                        }else{
                            current->next = newItem;
                            current = newItem;
                        }
                        ++sum->size;
                        
                    } // end of if else

                } // end of j loop

                current = nullptr;
            }// end of i loop
        }


        return sum;
    }

    ~SparseMatrixLL(){
        if (size > 0){
            Item *current = nullptr;

            for (int i = 0; i < this->rowSize; ++i){
                current = itemArray[i];
                for (int  j = 0 ; j < this->colSize ; ++j ){
                    if (current != nullptr){
                        itemArray[i] = current->next;
                        delete current;
                        current = itemArray[i];
                        continue;
                    }
                    break;
                }
            }
            delete []itemArray;
        }
    }
};
