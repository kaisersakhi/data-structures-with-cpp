/*
    Author : Kaiser Sakhi
    Date : 03-07-2021
    Environment : VS Code Ubunutu 20.04
*/


#include "includes/matrix.h"

struct Record{
    int row;
    int col;
    int element;
};

// struct Integer{ int a;};

class SparseMatrix{
    int rowSize; //m
    int colSize; //n
    int len; // # of non zero elemnets
    Record *record;

public :
    SparseMatrix(){
        this->rowSize = 0;
        this->colSize = 0;
        this->len = 0;
        this->record = nullptr;
    }
    SparseMatrix(Matrix &m){ // assume m as a simple matrix it can be or has to be a sparse matrix
        this->rowSize =  m.getRowSize(); // row size of orginal matrix 
        this->colSize = m.getColSize(); // column size of orginal mat
        this->len = 0; // 
        this->record = nullptr;
        // this loop will find non zero elemnets in given matrix
        for (int i = 0 ; i < this->rowSize; ++i){
            for (int j = 0; j < this->colSize ; ++j){
                if (m.get(i, j) != 0){ // whenever there is a non-zero 
                    ++len;  // then increment length 
                }
            }
        }
        // at this point we have # of non-elements, and are ready to craete the array of type record 
        // inside heap , and we will store the pointer in this.record
        this->record = new Record[len];
        int k = 0;

        for (int i = 0; i < this->rowSize; ++i){
            for (int j = 0; j < this->colSize ; ++j){
                if (m.get(i, j) != 0){
                    int e = m.get(i, j);
                    record[k].element = e;
                    record[k].row = i;
                    record[k].col = j;
                    ++k;
                }
            }
        }
    }

    void display(){
        int k = 0;
        for (int i = 0; i < this->rowSize; ++i){
            for (int j = 0; j < this->colSize ; ++j){
                if(this->record[k].row == i && this->record[k].col == j){
                    std::cout<<record[k].element<<" ";
                    ++k;
                }else{
                    std::cout<<0<<" ";
                }
            }
            std::cout<<"\n";
        }
    }

    SparseMatrix *operator+(SparseMatrix &sp){//c a = 10; b = 20  
        SparseMatrix *sumSp  = nullptr;

        if (this->rowSize == sp.rowSize && this->colSize == sp.colSize){
            sumSp = new SparseMatrix;
            sumSp->record = new Record[this->len + sp.len];
            sumSp->rowSize = this->rowSize;
            sumSp->colSize = this->colSize;
            int k = 0; 
            int j = 0;
            int i = 0;

            int minLength = (this->len > sp.len) ? sp.len : this->len;

            //asume that Matrix A is that which this class has, and Matrix B supplied as an argument

            for (; k < minLength ;){
                if (this->record[i].row > sp.record[j].row){
                    sumSp->record[k] = sp.record[j];
                    ++k;
                    ++j;
                }else if(this->record[i].row < sp.record[j].row){
                    sumSp->record[k++] = this->record[i++];
                }else{

                    if (this->record[i].col > sp.record[j].col){
                        sumSp->record[k++] = sp.record[j++];
                    }else if (this->record[i].col < sp.record[j].col){
                        sumSp->record[k++] = this->record[i];
                    }else{
                        sumSp->record[k] = this->record[i++];
                        sumSp->record[k++].element += sp.record[j++].element;
                    }
                }
            }

            if (this->len > sp.len){
                for ( int l = i ; l < this->len ; ++l){
                    sumSp->record[l] = this->record[i++];
                }
                sumSp->len = i;
            }else{
                for ( int l = j ; l < sp.len ; ++l){
                    sumSp->record[l] = sp.record[j++];
                }
                sumSp->len = j;
            }


        }

        return sumSp;
    }

    //copy constructor 
    SparseMatrix(SparseMatrix &sp){
            if (sp.rowSize > 0 && sp.colSize > 0){
                this->rowSize = sp.rowSize;
                this->colSize = sp.colSize;
                this->len = sp.len;
                this->record = new Record[len];
                for (int i = 0; i < this->len ; ++i){
                    this->record[i] = sp.record[i];
                }
            }
    }

    ~SparseMatrix(){
        if (record != nullptr){
            delete []this->record;
        }
    }



    

};