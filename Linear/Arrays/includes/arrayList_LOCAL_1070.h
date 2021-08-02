#include <limits.h>

template <class Type>
class ArrayList{
    Type *arr;
    int len;  // len represents the number of elements in a list 
    int size; // size represents total size of the array
public:
    ArrayList(){
        this->arr = nullptr;
        this->len = 0;
        this->size = 0;
    }

    ArrayList(int size){
        this->size = size;
        this->arr = new Type[this->size];
        this->len = 0;
    }

    bool add(Type element){
        int *tempPtr = nullptr;
        //this will run when array will be full in any case, which means len and size would be same 
        if (this->len == this->size){
            tempPtr = new int[size + 1];
            // check if memory allocation was successful 
            if (tempPtr == nullptr)
                return false; // if not then return false , which means failed to insert elemne t
            tempPtr[len] = element;
            //++this->len;
            // at first this willl not run, because at first arr will contine nullptr
            if (arr != nullptr){
                for (int i = 0; i < this->len; ++i){
                    tempPtr[i] = arr[i];
                }
                delete []this->arr; // deleting old array after copying the old elements to new array , so we dont need old arrray
                 // now, we need to copy the new array address to "arr" array pointer 
            }
            this->arr = tempPtr;
            ++this->len;
            ++this->size;
            return true;
        }else { // else if the size and len are not equal that means we have vacant location left to put element in , or we have space to store elements 
              arr[len] = element;
              ++this->len;
              return true;
        }
        return true;
    }

    int linearSearch(int element){
        for (int i = 0 ; i < this->len ; i++){
            if (this->arr[i] == element){
                return i;
            }
        }
        return -1;
        
    }

    bool update(int index, int element){
         if ( index >= 0 && index < size){
             this->arr[index] = element;
             return true;
         }
         return false;
    }

    int get(int position){
        if ( position >= 0 && position < len){
            return arr[position];
        }
        return -1; // -1 represents that the index was invalid 
    }

    bool remove(int index){
         if ( index >= 0 && index < size){
             for (int i = index; i < this->size - 1 ; ++i){
                this->arr[i] = this->arr[i + 1]; 
             }
             this->len--;
             return true;
         }
         return false;
    }

    int length(){
        return this->len;
    }

    int min(){
        int min_element = INT_MAX;

        for (int i  = 0; i < this->len; ++i){
            if (this->arr[i] < min_element)
                min_element = this->arr[i];
        }
        return min_element;
    }

    int max(){
        int max_el = INT_MIN;

        for (int i  = 0; i < this->len; ++i){
            if (this->arr[i] > max_el)
                max_el = this->arr[i];
        }

        return max_el;

    }


    int shiftLeft(bool forRotation = false){
            int overFlowEl = 0;
            if (len >   1){
                overFlowEl = this->arr[0];
                for (int i = 0; i < this->len -1 ; ++i){
                        this->arr[i] = this->arr[i + 1];
                }

                this->arr[len - 1]  = 0;
                if (!forRotation)
                    this->len--;
            }else if (this->len == 1){
                overFlowEl = this->arr[0];
                this->arr[0]  = 0;
                if (!forRotation)
                    this->len--;
            }else{
                return -1;
            }

            return overFlowEl;
    }

    int shiftRight(){
        int overFlowEl = 0;
        if (len > 1){
            overFlowEl = this->arr[this->len - 1];

            for (int i = this->len - 1; i > 0 ; --i){
                this->arr[i] = this->arr[i - 1];
            }
            this->arr[0] = 0;


        }else if (this->len == 1){
            this->arr[1] = this->arr[0];
            this->len++;
        }else{
            return -1; //
        }
        return overFlowEl;
    }

    void rotateLeft(){
        if (this->len > 0){
            //int a = this->shiftLeft(true);
            this->arr[this->len - 1] = this->shiftLeft(true); 
        }
    }

    void rotateRight(){
        if (this->len > 0){
            //int a = this->shiftLeft(true);
            this->arr[0] = this->shiftRight(); 
        }
    }

    void reverse(){
        if (this->len > 1){
            int i = 0 ;
            int j = len - 1;
            int temp = 0;
            while(i < j){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                ++i;
                --j;
            }
        }
    }

    void popAll(){ // this function will delete all the elements from the array and also del the whole array
        if (this->arr != nullptr){
            delete []this->arr;
            this->len = 0;
            this->size = 0;
            this->arr = nullptr;
        }
    }

    // backdoor entry to array
    long getBaseAddress(){
        return (long)this->arr;
    }

    ArrayList(const ArrayList<Type> &list){
        
        if (list.arr != nullptr){
            this->arr = new Type[list.size];
            for (int i = 0 ; i < len ; ++i){
                this->arr[i] = list.arr[i];
            }
            this->size = list.size;
            this->len = list.len;
        }
    }


    ~ArrayList(){
        if (this->arr != nullptr)
            delete []this->arr;
    }

};

