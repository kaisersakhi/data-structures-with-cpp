/*
    Author : Kaiser Sakhi
    Date : 03-08-2021
    Environment : Wsl Ubuntu 20

*/

#include "./includes/sparse-matrix.h"

int main(){

    //Matrix A
    Matrix mat(3,3);

    // Matrix::insert(element, rowIndex, ColumnIndex);
    mat.insert(2,0,0); mat.insert(0,0,1);  mat.insert(1,0,2);

    mat.insert(0,1,0); mat.insert(0,1,1);  mat.insert(0,1,2);
    
    mat.insert(4,2,0); mat.insert(0,2,1);  mat.insert(0,2,2);

   
    // Matrix B
    Matrix mat2(3,3);

    // Matrix::insert(element, rowIndex, ColumnIndex);
    mat2.insert(4,0,0); mat2.insert(3,0,1);  mat2.insert(1,0,2);

    mat2.insert(0,1,0); mat2.insert(3,1,1);  mat2.insert(0,1,2);
    
    mat2.insert(4,2,0); mat2.insert(0,2,1);  mat2.insert(10,2,2);


    /*              
         [2  0  1]             [4  3  1 ]
     A=> [0  3  0]   , B =>    [0  3  0 ] 
         [4  0  0]             [4  0  10]
                     
    */

    SparseMatrixLL sparseList(mat);
    SparseMatrixLL sparseList2(mat2);

    std::cout<<"Matrix A \n";
    sparseList.display();
    std::cout<<"Matrix B \n";
    sparseList2.display();

    SparseMatrixLL *sum = sparseList + sparseList2;

    if (sum != nullptr){
        std::cout<<"Sum Matrix , A+B\n";
        sum->display();
        delete sum;
    }
    return 0;
}





//              Spegatti Code , hahaha
/*

        void addOrCopy(Item **sumArray, Item **current, Item **p, Item **q, int i , int j , bool qGreater = false){
        
        if ((*current) == nullptr){
            *sumArray = new Item;
            *current = *sumArray;
            (*current)->col = j;
            if ((*p) == nullptr){
                (*current)->data = (*q)->data;
                (*q) = (*q)->next;
            }else if ((*q) == nullptr){
                (*current)->data = (*p)->data;
                (*p) = (*p)->next;
            }else{
                (*current)->data = ((*p)->data + (*q)->data);
                (*p) = (*p)->next;
                (*q) = (*q)->next;
            }
            // current->data =  q ? (q->data; q = q->next) : p->data;
            //q = q ? q->next : p->next;
            //(*current)->next = nullptr;
        }else{

            (*current)->next = new Item;
            (*current) = (*current)->next;
            (*current)->col = j;

            //ERROR HERE:- this should work on both , if p is null and when q is to be inserted
            //regardless what the p is having in it
            if ((*p) == nullptr || !qGreater){
                (*current)->data = (*q)->data;
                (*q) = (*q)->next;
            }else if ((*q) == nullptr || qGreater){
                (*current)->data = (*p)->data;
                (*p) = (*p)->next;
            }else{
                (*current)->data = ((*p)->data + (*q)->data);
                (*p) = (*p)->next;
                (*q) = (*q)->next;
            }
            //current->data =  q ? q->data : p->data;// q->data;
            // q = q ? q->next : p->next;
            //(*current)->next = nullptr;
        }
    }


        if (current == nullptr){
            sum->itemArray[i] = new Item;
            current = sum->itemArray[i];
            current->col = j;
            if (p == nullptr){
                current->data = q->data;
                q = q->next;
            }else if (q == nullptr){
                current->data = p->data;
                p = p->next;
            }
            // current->data =  q ? (q->data; q = q->next) : p->data;
            //q = q ? q->next : p->next;
            current->next = nullptr;
        }else{

            current->next = new Item;
            current = current->next;
            current->col = j;
            if (p == nullptr){
                current->data = q->data;
                q = q->next;
            }else if (q == nullptr){
                current->data = p->data;
                p = p->next;
            }
            //current->data =  q ? q->data : p->data;// q->data;
            // q = q ? q->next : p->next;
            current->next = nullptr;
        }



*/