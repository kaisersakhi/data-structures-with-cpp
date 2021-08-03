/*
    Author : Kaiser Sakhi
    Date : 02-08-2021
    Environment : Wsl Ubuntu 20
*/




#include <iostream>
#include "./singlyLinkedList.h"

class DoublyLinkedList : public LinkedList{
    // Node *head;
    // Node *tail;
    // int length;

public:
    // LinkedList::head

    DoublyLinkedList() : LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }    

    // append / insert / pop / add
    bool append(int data){

        Node *newNode = new Node;
        newNode->data = data;
        newNode->pre = nullptr;
        newNode->next = nullptr;

        // special case : if list is empty
        if (this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
            ++this->length;
            return 1;
        }else{
            newNode->pre = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
            ++this->length;
            return 1;
        }
        return 0;
    }

    void display(bool reverse = false){
        if (this->head != nullptr){
            
            Node *current = nullptr;
            if (!reverse){
                LinkedList::display();
                return;
            }else 
                current = this->tail;

            while (current != nullptr){
                std::cout<<current->data<<" ";
                current =  current->pre;
            }
            std::cout<<std::endl;
        }

    }

    //@Override
    void reverse(){
        if (this->head != nullptr){

            //one way
            Node *cNode = this->tail = this->head;
            Node *temp = nullptr;

            while (cNode != nullptr){
                temp = cNode->next;
                cNode->next = cNode->pre;
                cNode->pre = temp;
               // temp = temp->next;
               if (temp == nullptr){
                   this->head = cNode;
                   break;
               }
                cNode = cNode->pre; // next, essentially
            }
         
        }
    }

    //@Override 
    bool remove(int index = -1){// demands index aka position, assuming starts at 0
        // if index is not specified , then -1 will represent last node
        if (head != nullptr && (index >= -1 && index < this->length)){
            if (this->length == 1){
                this->popAll();
                return 1;
            }
            // there are 3 cases
            //1. Starting Node
            //2. Ending Node
            //3. Any other node

            // for starting
            if (index == 0){
                if (this->length > 1){
                    this->head = this->head->next;
                    delete this->head->pre;
                    this->head->pre = nullptr;
                    --this->length;
                }else{
                    // if there is only 1 node in the list
                    this->popAll();
                }
                return true;
            }
            // for ending node
            if (index == this->length -1 || index == -1){
                tail = tail->pre;
                delete tail->next;
                tail->next = nullptr;
                --length;
                return true;
            }

            // if it is any other node
            Node *current = this->head;
            for (int i = 0 ; i < index ; ++i){
                current = current->next;
            }

            Node *temp = current->pre;
            temp->next = current->next;
            temp = current->next;
            temp->pre = current->pre;
            delete current;
            --this->length;
            return 1;
        }
        return 0;
    }

    //@Override
    void popAll(){
        LinkedList::popAll();
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void merge(DoublyLinkedList &mList){
        
        if (this->head != nullptr){
            Node dummyNode;
            dummyNode.pre = this->tail;
            dummyNode.next = mList.head;
            LinkedList::merge(mList, true); // provide true, to move nodes directly, not to copy
            dummyNode.next->pre = dummyNode.pre;
        }
    }
};