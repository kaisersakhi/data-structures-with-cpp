#include "../matrix.h"

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
        this->rowSize =0; // row size of orginal matrix 
        this->colSize =0; // column size of orginal mat
        this->len = 0; // 
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

    SparseMatrix *add(SparseMatrix &sp){//c a = 10; b = 20  
        SparseMatrix *sumSp  = nullptr;

        if (this->rowSize == sp.rowSize && this->colSize == sp.colSize){
            sumSp = new SparseMatrix;
            sumSp->record = new Record[this->len + sp.len];
            sumSp->rowSize = this->rowSize;
            sumSp->colSize = this->colSize;
            int k, j , i;
            k = j = i = 0;
            int limit = (this->len < sp.len) ? this->len : sp.len;
            for (; k < limit ;){
                if (this->record[i].row < sp.record[j].row){
    
                    sumSp->record[k++] = this->record[i++];

                }else if(this->record[i].row > sp.record[j].row){

                    sumSp->record[k++] = sp.record[j++];

                }else{ // when they are equal

                    if (this->record[i].col < sp.record[j].col){
                        sumSp->record[k++].element = this->record[i++].element;
                      
                    }else if (this->record[i].col > sp.record[j].col){
                        sumSp->record[k++] = sp.record[j++];
                    }else{ // if columns are same then add
                        sumSp->record[k] = this->record[i++];
                        sumSp->record[k].element += sp.record[j++].element;
                    }
                }
            }
            if (this->len > sp.len){ // if first record is longer the copy remaining elements
                for (int l = i; l < this->len ; ++l){
                    sumSp->record[k++] = this->record[l];
                }
            }else if (sp.len > this->len){ // if second record is longer then copy the remaining elements from the second array

                for(int l = j ; l < sp.len ; ++l){
                    sumSp->record[k++] = this->record[l];
                }

            }

            sumSp->len = k;
            
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


int main(){
    Matrix mat(3, 3, true);
    // mat.insert(1,  0 , 0);
    // mat.insert(2 , 0, 1);
    // mat.insert(3 , 1, 0);
    // mat.insert(4 , 1, 1);
   

    SparseMatrix sp1(mat);
    SparseMatrix sp2(mat);

    SparseMatrix *addSm = sp1.add(sp2);
    //
    //sp1.display();
    addSm->display();
    delete addSm;
    return 0;
}