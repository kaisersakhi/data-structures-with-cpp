#include "../node.h"
#include "../../Linear/Arrays/includes/arrayList.h"
#include <climits>
#include <iostream>
// #include <limits.h>

class LinkedList{
protected:
    Node *head;
    Node *tail;
    int length;

public:

    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }


    // this member funtion will insert element at the end of the linked list , in O(1)
    bool append(int data){
        
        //fist crate a new singleton node and store its base addrress into "newNode"
        Node *newNode = new Node;
        newNode->data = data;   // copy the supplied datat into newNode's property
        newNode->next = nullptr; // make the new node point to null pointer 

        // this is special case : will run only once in the lifetime of linked list class
        if (this->head == nullptr){  // if at first head is null , that means list is empty 
            this->head = newNode;  // if list is empty, make head point to newNode
            this->tail = newNode;
            ++this->length;  // increment the length 
            return true; // indicate, node has been added successfully
        }

        // if head is not null, that means there are elements in the list
        // so we need to traverse the whole list untill we reach at the end of the linked list

        // for refrence crete a temperory node and make it point to the starting node which is head 
       // Node *current = this->head; 
        
        // now travese the whole list until u encounter null in the present node 
        // that means whenever there is null in "next" property of current node, then stop 
        // while(current->next != nullptr){
        //     current = current->next;
        // }
        // at this point we are pointing at the last node of the linked list
        // we have base address of the last node of the list
        //current->next = newNode; // put base address of newNode into "next" pointer of the last node

        this->tail->next = newNode;
        this->tail = newNode;
        ++this->length;
        return true; // return true : insertion successful 

    }


    bool prepend(int data){

        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (this->head == nullptr){
            this->head = newNode;
            ++this->length;
            return true;

        }

        newNode->next = this->head;
        this->head  = newNode;
        ++this->length;
                
        return true; 
    }


    // this will delete the node at the end of the list
    bool pop(){ 
        if (this->head != nullptr){
            Node *current = this->head;

            for (int i = 1; i < length - 1 ; ++i){
                current = current->next;
            }

            if (this->length == 1){
                delete this->head;
                this->head = nullptr;
                this->length--;
                return true;
            }
            delete current->next;
            current->next = nullptr;
            --this->length;
            return 1;
        }
        return false;

    }

    void display(){
        if (this->head != nullptr){
            Node *current = this->head;

            while (current != nullptr){
                std::cout<<current->data<<" ";
                current = current->next;
            }

            std::cout<<"\n";
        }
    }

    // this member function will return an element at specified index
    // considering index starts at 0
    int get(int index){
        if ((this->head != nullptr) && (index >= 0 && index < this->length)){
            Node *current = this->head;

            for (int i = 0; i < index ; ++i){
                current = current->next;
            }

            return current->data;
        }
        return -1; // -1 indicate, element not found 
    }


    // this method will return the node at specifed element 
    Node *linearSearch(int el){


        if (this->head != nullptr){
            Node *current = this->head;
            int i = 0;
            while (current != nullptr){
                if (current->data == el){
                    return current; // return current node as it is containing specied search element
                }
                current = current->next;
                ++i;
            }

        }

        return nullptr;

    }

    // this method will find the no. of duplicates
    // and their position in the list, 
    // and will retrun those position in the form of ArrayList<int>
    ArrayList<int> findOccurence(int el){
        ArrayList<int> array;

         if (this->head != nullptr){
            Node *current = this->head;
            int i = 0;
            while (current != nullptr){
                if (current->data == el){
                    array.add(i);
                }
                current = current->next;
                ++i;
            }

        }
        
        return array;
    }


    // deletes a node a specified index in a list
    int remove(int index = 0){ // if index is not specified then element will be deleted at the begining of the list

        // return if index is not in range / invalied index
        if (!(index >= 0 && index < this->length))
            return -1;

        int el = -1; 

        if (this->head != nullptr){
            Node *current = this->head;
           

            // special case
            if (index  == 0 ){ // first element in the list
                // el = this->get(index);

                Node *temp = this->head;
                el = temp->data;
                this->head = temp->next;
                delete temp;
                --this->length;


            }else if (index == length - 1){ // last element in the list, also special case
                el = this->get(index);  
                this->pop();
                --this->length;

            }else { // elements from first+1 to n -1

               for (int i = 0 ; i < index  - 1; ++i){
                   current = current->next;
               } 

               Node *temp = current->next;

               current->next = temp->next;

               el = temp->data;
               delete temp;
               --this->length;
             
            }
        }

        return el;
    }

    // this method will update an element at specified index
    bool update(int index, int data){

        // if there exists anything in the list and index is in range
        if (this->head != nullptr && (index >= 0 && index < this->length)){

            Node *current = this->head;

            for (int i = 0 ; i < index; ++i){
                current = current->next;
            }

            current->data = data;
            return true;
        }
        // else return false 
        return false;
    }


    // this method will return minimum in the list
    int getMin(){
        
        int minElement = INT_MAX;

        if (this->head != nullptr){

            Node *current = this->head;

            while (current != nullptr){

                if (current->data < minElement)
                    minElement = current->data;
                
                current = current->next;
            }

        }
        return minElement;
    }
    // Node *get(int index){

    //     if (this->head != nullptr && (index >= 0 && index < this->length)){

    //     }


    //     return nullptr;
    // }


    void rotateRight(){
        if (this->head != nullptr && this->length > 1){
            Node *current = this->head;
            Node *pre = nullptr;

            while (current->next != nullptr){
                pre = current;
                current = current->next;
            }
            // at this point currrent will point to the last node 
            // 
            this->prepend(current->data);
            delete current;
            pre->next = nullptr;
      
        }
    }



    // LIST a = {10};
    // LIST b = {5};
    // a.merge(b);
    // print b.length();
    // String a = "kaiser";
    // String b = "bhat";
    // a.concat(b);
    // print a; // kaiser bhat
    // print b; // bhat

    // now, we will do the reverse ;


    void reverse(){
        
        if (this->head != nullptr && this->length > 1){
            Node *pre = nullptr;
            Node *cur = nullptr;
            Node *nex = this->head;

            while (nex != nullptr){
                pre = cur;
                cur = nex;
                nex = nex->next;
                cur->next = pre;
            }

            this->head = cur;
        }
    }

    // this methos will concatenate two list 
    void merge(LinkedList &mList){

        if (!(mList.getLength() > 0))
            return;
        
        //Solution 1: // copy each and every  node to this list and also keeping the orginals there
        // this will merge in O(n);

        Node *current = mList.head;

        while (current != nullptr){
            this->append(current->data);
            current = current->next;
        }


        // Solution 2 : // attaching all orginal nodes to this list, and making 2list as null
        // this will merger in O(1)
        // if (this->head == nullptr){
        //     this->head = mList.head;
        //     this->tail = mList.tail;
        //     this->length = mList.length;
        //     mList.head = nullptr;
        //     mList.tail = nullptr;
        //     mList.length = 0;

        // }else{
        //     this->tail->next = mList.head;
        //     this->tail = mList.tail;
        //     this->length += mList.length;
        //     mList.head = nullptr;
        //     mList.tail = nullptr;
        //     mList.length = 0;
        // }

    }

    // deleting entire list
    void popAll(){
         if (this->head != nullptr){
            Node *current = nullptr;

            while (head != nullptr){
                current = head;
                head = current->next;
                delete current;
            }

            this->head = nullptr;
            this->length = 0;
        }
    }


    int getLength(){
        return this->length;
    }

    ~LinkedList(){
        if (this->head != nullptr){
            Node *current = nullptr;

            while (head != nullptr){
                current = head;
                head = current->next;
                delete current;

            }
        }
    }
};