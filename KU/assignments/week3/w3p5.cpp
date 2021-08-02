/*
    Author : Kaiser Sakhi
    Date : 07-23-2021
    Environment : WSL Kali Linux
*/


//Write a program to implement different operations of a circular linked list


#include <iostream>

class Node{
    public:
    int data;
    Node *next;
};

class CircularSignlyLinkedList{
    int size;
    Node *head;
public:
    CircularSignlyLinkedList(){
        this->head = nullptr;
        this->size = 0;
    }

    bool insert(int data){
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (this->head == nullptr){
            this->head = newNode;
            this->head->next = head;
            this->size++;
            return 1;
        }else{
            Node *current = this->head;

            do{
                current = current->next;
            }while(current->next != this->head);

            current->next = newNode;
            newNode->next = this->head;
            return 1;
        }
        return 0;
    }

    void display(){
        if (this->head != nullptr){
            Node *current = this->head;

             do{
                 std::cout<<current->data<<" ";
                current = current->next;
            }while(current != this->head);
            std::cout<<"\n";
        }
    }
};

int main(){
    CircularSignlyLinkedList list;
    list.insert(11);
    list.insert(90);
    list.insert(9);
    list.insert(19);
    list.display();
    return 0;
}
