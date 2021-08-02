/*
    Author : Kaiser Sakhi
    Date : 07-23-2021
    Environment : WSL Kali Linux
*/
// Write a program in C++ to implement a doubly linked list?

#include <iostream>

class Node{
public:
    Node *previous;
    int data;
    Node *next;

};

class DoublyLinkedList{
    Node *head;
    Node *tail;
    int size;

public :
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
    }

    bool insert(int data){
        Node *newNode = new Node;
        newNode->previous = nullptr;
        newNode->next = nullptr;
        newNode->data = data;

        // check special case, if head is null -> list is empty
        if (this->head == nullptr){
            this->head = newNode;
            this->tail = newNode;
            ++this->size;
            return 1;
        }else{ // if list is not empty then insert at the end with tail node in O(1)

            newNode->previous = this->tail;
            this->tail->next = newNode;
            this->tail = newNode;
            ++this->size;
            return 1;
        }
        return 0;
    }

    void display(){
        if (this->head != nullptr){

            Node *current = this->head;

            while (current != nullptr){
                std::cout<< current->data << " ";
                current = current->next;
            }
        }
    }

    void dispalyReverse(){
        if (this->head != nullptr){
            Node *current = this->tail;

            while (current != nullptr){
                std::cout<<current->data<< " ";
                current = current->previous;
            }
            std::cout<<"\n";
        }
    }


    ~DoublyLinkedList(){
        if (this->head != nullptr){
            Node *temp = this->head;

            while (this->head != nullptr){
                temp = this->head;
                head = head->next;
                delete temp;
            }
            std::cout<<"\n";
        }
    }

};

int main(){
    DoublyLinkedList list;
    list.insert(9);
    list.insert(0);
    list.insert(8);
    list.insert(15);
    list.insert(11);
    list.insert(41);
    list.insert(91);

    list.display();
    std::cout<<"\n";
    list.dispalyReverse();


}