#include<iostream>


class Array{
        int *arr;
        int size;
        int length;
public:
        Array(int size){
                this->size = size;
                arr = new int[size];
                this->length = 0;
        }
        bool insert(int el){
                if (length < size){
                        arr[length]  = el;
                        ++length;
                        return true;
                }
                return false;
        }

        int find(int el){
                for (int i = 0; i < this->size; ++i ){
                        if (arr[i] == el)
                                return i;
                }
                return -1; // assume -1 represents not found 
        }

        bool update(int el, int position){
                if (position < size && position >= 0 ){
                        arr[position] = el;
                        return true;
                }
                return false;
        }
        bool remove(int position){
               if (position <= length && position >= 0 )  {
                       for (int i = position ; i < size -1; ++i){
                               arr[i] = arr[i + 1];
                       }
                       --this->length;
                       return true;
               }       
               return false;
        }
        int get(int position){
                if (position < size && position >= 0 ){
                        return arr[position];
                }
                return -1; 
        }
        void insertRandom(){
                for (int i = 0; i < size; ++i)
                        insert(i+1);
        }
        
        int len(){
                return this->length;
        }

};


int main(){
        int size = 5;
        Array items(size);
        items.insertRandom();
        items.update(10, 0);
        items.remove(0);
        std::cout<<"Element Location : "<<items.find(5)<<"\n";
        for (int i = 0 ; i < items.len() ; ++i){
                std::cout<<items.get(i)<<"\n";
        }
        return 0;
}