/*
    Author : Kaiser Sakhi
    Date : 20-JUN-2021
    Environment : WSL UBUNTU18
*/

// program to implement Matrix with basic operations 


/*

                Everything Explained Here :
                    https://www.youtube.com/watch?v=TwyEZs_TWes
                    https://www.youtube.com/watch?v=W6HiVVwevWQ
                    https://www.youtube.com/watch?v=Xn8xU3kK5Nw
                    https://www.youtube.com/watch?v=WpSydDDXOVU
                    https://www.youtube.com/watch?v=T-V7Zy8aT-Q
                    https://www.youtube.com/watch?v=Xn8xU3kK5Nw
                    https://www.youtube.com/watch?v=0JVfh3m7oMY

*/

#include <iostream>

class Matrix{
    int *mat;
    int rowSize; //n
    int colSize; //m
   // long arrayBaseAddress;
    long calculate(int i , int j){
        return ((long)mat + (i * colSize + j ) * sizeof(int)); // heart of this class 
    }

    void toIdentity(){
        if (this->rowSize == this->colSize){
            for (int i = 0; i < this->rowSize ; ++i){
                for (int j = 0; j < this->colSize ; ++j){
                    if (i == j)
                        this->insert(1, i, j);
                    else
                        this->insert(0, i , j);
                }
            }
        }
    }

public:
    // Matrix(){
    //     this->mat = nullptr;
    //     this->rowSize = 0;
    //     this->colSize = 0;
    //     //this->arrayBaseAddress = 0;
    // }

    Matrix(int rowSize, int colSize, bool isIdentity = false){    
        if (!(rowSize < 1 || colSize < 1)){
            this->rowSize = rowSize;
            this->colSize = colSize;
            mat = new int[this->rowSize * this->colSize];
            //this->arrayBaseAddress =  mat->getBaseAddress();
        }else{ 
            mat = nullptr;
            this->rowSize = 0;
            this->colSize = 0;
            //this->arrayBaseAddress = 0;
        }
        if(isIdentity){
            this->toIdentity();
        }
    }

    bool insert(int el, int i, int j){
        if(i < this->rowSize && j < this->colSize && i > -1 && j > -1){
            *((int *)calculate(i, j)) = el;
            return true;
        }
        return false;
    }



    void display(){
        for (int i = 0 ; i < this->rowSize ; i++){
            for (int j = 0; j < this->colSize ; ++j){
                std::cout<<*((int *)calculate(i, j))<<" ";
            }
            std::cout<<"\n";
        }
    }

    // matrix addition 
    Matrix *  operator+(Matrix &m){ //m = mat2
        Matrix *m1  = nullptr;
        if (this->rowSize == m.rowSize && this->colSize == m.colSize){
            m1 = new Matrix(this->rowSize, this->colSize);
            for (int i = 0 ; i < this->rowSize ; ++i){
                for (int j= 0 ; j < this->colSize ; ++j){
                    m1->insert(( this->get(i,j) + m.get(i, j) ) , i , j) ;    // C[i][j] = A[i][j] + B[i][j];
                }
            }
        }
        return m1;
    }

    // this member funciton will calculate product of 2 matrices the self and the provided as an argument
    Matrix *operator *(Matrix &m1){
        Matrix *product = nullptr; // create the null pointer

        if (this->colSize != m1.rowSize)  // if the column size of first matrix is not equal to row size of second matrix , then
            return product; // multiplication not possible 

        product = new Matrix(this->rowSize, m1.colSize); //create matrix of dimension ( row_size of first matrix and column size of second matrix) || m1Xn1 2. m2Xn2  

        for (int i = 0 ; i < this->rowSize ; i++){ // this will loop every row of A
            for ( int j = 0; j < m1.rowSize ; ++j){ // this will loop every element of ith row of A
                    product->insert(0, i ,j);   // initilize C[i][j] = 0
                    for (int k = 0; k < m1.colSize ; ++k){ // this loop will loop every column of A or Row of second column 

                        // muliply each 2 terms of 1st and second matrix and add the previous value at C[i][j], then store back the sum  
                        product->insert(   ( product->get(i,j) + ( this->get(i, k) * m1.get(k, j) )) , i , j )  ;                // C[i][j] += A[i][k] * B[k][j]; 
                    }
            }
        }
        return product; // return product or product 
    }

    // this member function will transpose this matrix and return the pointer to the result
    void transpose(){

        // Matrix *newMat = nullptr;
        // if (this->mat != nullptr){
        //     newMat = new Matrix(this->colSize, this->rowSize);
        //     for (int i = 0; i < this->rowSize; ++i){
        //         for (int j = 0 ; j < this->colSize; ++j){
        //             newMat->insert(this->get(i, j) , j , i);
        //         }
        //     }
        //     // TO DO THIS WAS THE ERROR 
        // //    delete this->mat;
        // }

        // return newMat;

        if (this->rowSize == 1 || this->colSize){
            int temp = this->colSize;
            this->colSize = this->rowSize;
            this->rowSize = temp;
            return;
        }
        if (this->mat != nullptr){
            int *newMat = new int[this->colSize * this->rowSize];
            for (int i = 0  ; i < this->rowSize ; ++i){
                for (int j = 0; j < this->colSize ; ++j){
                    long addr = ((long)mat)+ (this->colSize*sizeof(int)*j ) + (i * sizeof(int)); // formula for tanspose 
                    // std::cout<<addr<<"\n";
                    *(int *)((long)newMat + (i * colSize + j ) * sizeof(int))  = *((int *)(addr)); // formula for row major
                }
            }
            delete []this->mat;
            this->mat = newMat;
            int temp = this->colSize;
            this->colSize = this->rowSize;
            this->rowSize = temp;
        }



    }
    //this member function will return a specified element from the matrix
    int get(int i, int j){
        return *((int *)calculate(i,j));
    }

    //copy constructor 
    Matrix(Matrix &m){
        this->colSize = m.colSize;
        this->rowSize = m.rowSize;
        this->mat = new int[this->colSize * this->rowSize];
        for (int i = 0; i < (this->colSize * this->rowSize); ++i){
            this->mat[i] = m.mat[i];
        }
    }


    bool isLowerTriangular(){
        if(this->rowSize != this->colSize){
            return false;
        }

        for (int i = 0; i < this->rowSize; ++i){
            for (int j = 0 ; j < this->colSize ; ++j){
                if(i < j){
                    if (this->get(i, j) != 0){
                        return false;
                    }
                }
            }
        }

        return true;
    }

    int trace(){
        int sum = 0;

        for (int i = 0; i < this->rowSize ; ++i){
            for (int j = 0; j < this->colSize ; ++j){
                if (i == j){
                    sum += this->get(i,j);
                }
            }
        }

        return sum;
    }


    bool operator==(Matrix &m){
        if ( this->rowSize == m.rowSize && this->colSize == m.colSize){
            for (int i = 0; i < this->rowSize ; ++i){
                for (int j = 0 ; j < this->colSize; ++j){
                    if (this->get(i, j) != m.get(i ,j)){
                        return false;
                    }
                }
            }
        }else{
            return false;
        }
        return true ;
    }

    // destructor 
    ~Matrix(){
        //if mat is pointing at some valid location
        if (this->mat != nullptr)
            delete this->mat;
    }
};


int main(){
    Matrix mat(2,2); // int mat[3][2] = {1,2,3,4,5,6};
    mat.insert(1, 0 , 0); // mat[0][0] = 1;
    mat.insert(0, 0 , 1); // mat[0][1] = 2;
    mat.insert(3, 1 , 0); // mat[1][0] = 1;
    mat.insert(4, 1 , 1); // mat[1][1] = 1;
    // mat.insert(5, 2 , 0); // mat[2][0] = 1;
    // mat.insert(6, 2 , 1); // mat[2][1] = 1;
    mat.display();
    mat.transpose();
    std::cout<<"After Transpose : \n";
    mat.display();

//     Matrix mat2(3, 2);
//     mat2.insert(1, 0 , 0); // mat[0][0] = 1;
//     mat2.insert(2, 0 , 1); // mat[0][1] = 2;
//     mat2.insert(3, 1 , 0); // mat[1][0] = 1;
//     mat2.insert(4, 1 , 1); 
//     mat2.insert(5, 2 , 0); // mat[2][0] = 1;
//     mat2.insert(6, 2 , 1); // mat[2][1] = 1;

//     Matrix *sumMat = mat + mat2;
//    // sumMat->display();

//     if (sumMat != nullptr){
//         //sumMat->display();
//         delete sumMat;
//     }

//     Matrix *product = mat * mat2;

//     if (product != nullptr){
//         product->display();
//         delete product;
//     }else{
//         std::cout<<"Dimension did not match! Try Again!\n";
//     }

//     std::cout<<"Transpose Is : \n";

    // Matrix *matTranspose =  mat.transpose();

    // if (matTranspose != nullptr){
    //     matTranspose->display();
    //     delete matTranspose;
    // }

    // sumMat.display();

    if (mat.isLowerTriangular()){
        std::cout<<"Matrix is lower Triangular!\n";
    }else{
        std::cout<<"Matrix is not lower Triangular!\n";
    }

    std::cout<<"Trace of mat is : "<<mat.trace()<<"\n";

    Matrix identityMat(3,3,true);
    std::cout<<"Identity Matrix : \n";
    identityMat.display();

   // A = A`

    Matrix A(3, 3, false);
    A.insert(-2, 0, 0);
    A.insert(3, 0, 1);
    A.insert(-4, 0, 2);
    A.insert(3, 1, 0);
    A.insert(1, 1, 1);
    A.insert(0, 1, 2);
    A.insert(-4, 2, 0);
    A.insert(0, 2, 1);
    A.insert(8, 2, 2);

    Matrix ATranspose = A;
    
    // A.insert(10, 0 , 0);
    std::cout<<"Matrix A:\n";
    A.display();
    std::cout<<"Matrix A Transpose:\n";
    ATranspose.display();
    ATranspose.insert(10, 0 , 0);
    ATranspose.transpose();
    if (A == ATranspose){
        std::cout<<"A is sysmetric matrix!\n";
    }


    return 0;
}