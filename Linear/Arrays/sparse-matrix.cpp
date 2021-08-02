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

    SparseMatrix *add(SparseMatrix &sp){//c a = 10; b = 20  
        SparseMatrix *sumSp  = nullptr;

        if (this->rowSize == sp.rowSize && this->colSize == sp.colSize){
            sumSp = new Record[this->len + sp.len];
            int k = 0; 
            int j = 0;
            for (int i = 0 ; i < this->rowSize ; ++i){
                for ( int j = 0 ; j < this->colSize ; ++j){
                    if (this->record[k].row  < sp.record[j].row){
                        if (this->record[k].col )
                    }
                }
            }
        }
    }

    //copy constructor 
    SparseMatrix(SparseMatrix &sp){
        if (sp != nullptr){
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
    }

    ~SparseMatrix(){
        if (record != nullptr){
            delete []this->record;
        }
    }



    

};


int main(){
    Matrix mat(3, 3, true);
    // mat.insert(1,  0 , 0);
    // mat.insert(2 , 0, 1);
    // mat.insert(3 , 1, 0);
    // mat.insert(4 , 1, 1);
   

    SparseMatrix sp1(mat);
    SparseMatrix sp2(mat);

    //SparseMatrix add = sp1.add(sp2);
    sp1.display();

    return 0;
}