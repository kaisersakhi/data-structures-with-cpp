#include <iostream>

/*
    for time being lets make it work only fo r
    KeyType with int and char only 
    value type can be anythin
*/
template<class KeyType, class ValueType>
class Dictionary{
    KeyType *keyArray;
    ValueType *valueArray;
    int size ;
    int len; 
public:
    Dictionary(int size){
        if (size > 0){
            this->size = size;
            this->keyArray = new KeyType[this->size];
            this->valueArray = new ValueType[this->size];
            this->len = 0;
        }else{
            this->size = 0;
            this->keyArray = nullptr;
            this->valueArray = nullptr;
            this->len = 0;
        }
    }

    bool append(KeyType key, ValueType value){

        if (!(this->len >= this->size)){
            // when there is space to add new values into both arrays
            keyArray[len] = key;
            valueArray[len++] = value;
            return true ;
        }
        return false;
    }

    // this function will return a value at specifed key
    ValueType get(KeyType key){
        int index = 0;
        bool found_key = false;
        // first search from key array 

        for (; index <= this->len ; ++index){
            if (keyArray[index] == key){
                found_key = true ;
                break;
            }
        }
        
        ValueType val;
        if (found_key){
            val = valueArray[index];
        }
        // if (!found_key){
        //     return 
        // }
        //this will return garbage value if key is not found
        return val;
        

        
    }

    void print(){
        for (int i = 0; i < this->len; ++i){
            std::cout<<"\""<<keyArray[i]<<"\" : "<<valueArray[i] <<",\n";
        }
    }

    // bool operator>(Dictionary &d){

    //     int k = d['('];
        
    // }

    int length(){
        return this->len;
    }
    int getSize(){
        return this->size;
    }

    ~Dictionary(){
        if (this->keyArray != nullptr){
            delete []keyArray;
            delete []valueArray;
        }
    }
};