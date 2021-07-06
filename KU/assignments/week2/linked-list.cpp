
/*
    Author : Kaiser Sakhi
    Date : 07-06-2021
    Environment : WSL Kali Linux
*/


// program to delete nodes at diffrent postions 

#include <iostream>
#include "node.h"

class LinkedList{
    Node *head;
    int len;
public :
    LinkedList(){
        this->head = nullptr;
        this->len = 0;
    }

    bool insert(int element){
        Node *temp = new Node;
        temp->data = element;
        temp->next = nullptr;

        if (this->head == nullptr){
            this->head = temp;
            ++this->len;
            return true;
        }else{
            Node *current = this->head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = temp;
            ++this->len;
            return true;
        }

        return false;
    }
    void display(){
        Node *current = this->head;
        while (current != nullptr){
            std::cout<<current->data<< " ";
            current = current->next;
        }
    }
    int length(){
        return this->len;
    }

    bool remove(int position = 0){
        if (!(position > -1 && position < this->len))
            return false;
        
        if (position == 0){ // delete node at head
            Node *cur = this->head;
            this->head = cur->next;
            delete cur;
            --this->len;
            return true;
        }else{
            Node *cur = this->head;
            Node *temp = nullptr;
            for (int i = 0 ; i < position; ++i){
                temp = cur;
                cur = cur->next;
            }
            temp->next = cur->next;
            delete cur;
            --this->len;
            return true;
        }

        return false;
    }


    ~LinkedList(){
        if (this->head != nullptr){
            Node *current = this->head;
            Node *temp = nullptr;
            while (current != nullptr){
                temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

};

int main(){
    LinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.remove(3);
    list.display();
    std::cout<<"\nList Length is : "<<list.length()<<"\n";
    return 0;

}