#include "./associative_array.h"

int main(){

    Dictionary<char, int> d(7);

    // {'(' : 1}
    d.append('(',1);
    d.append(')',1);
    d.append('^',2);
    d.append('*',3);
    d.append('/',3);
    d.append('+',4);
    d.append('-',4);
    d.print();

    Dictionary<char, int> dd(7);
    bool a = (d > dd);
    
    return 0;

}
