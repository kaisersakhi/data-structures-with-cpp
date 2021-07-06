
// Write a program in C++ to perform Transpose of a Matrix

/*
    Author : Kaiser Sakhi
    Date : 20-JUN-2021
    Environment : WSL UBUNTU18
*/

// program to implement Matrix with basic operations 




#include "../matrix.h"

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