/*
    Author : Kaiser Sakhi
    Date : 07-23-2021
    Environment : WSL Kali Linux
*/
//Write a program to implement different operations like adding a node at beginning, end,
// center, after a certain element, after a certain count of nodes in a doubly linked list.


#include <iostream>
#include <climits>
enum ListPositions {
    START,
    MIDDLE,
    END,
    NONE
};


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

    // if alignmen is NONE it will always consider position, and if position is not given,
    // then node will be inserted at the end of the list
    bool insert(int data, ListPositions alignment = NONE, int position = -1){ // position -1 represents last

        // alignment is a constant range {ListPositions}
        // if alginment is given then insert elements, if alginment is NONE then consider arg{'position'}

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
            
            Node *current = nullptr;
            Node *tempNode = nullptr;

            // if postion and alignment is 0 or start, that is the same thing
            if (alignment == START || position == 0 ){
                // insert node at the satrt of the list
                this->head->previous = newNode;
                newNode->next = this->head;
                this->head = newNode;
                ++this->size;

                return true;


            }else if (alignment == MIDDLE){


                int count = (int) (size / 2); //considering floor

                current = this->head;

                for (int i = 0 ; i < count - 1; ++i){
                    current = current->next;
                }

                newNode->next = current->next; // first make newNode's next point to currtent of next 
                newNode->previous = current;  // make newnode's previous point to current, because that will be previous to new node now
                current->next = newNode; // now alter next of current make it point to newNode
                newNode->next->previous = newNode;  // at this point newNode's next  is pointing to the current node 
                // now we have to make sucessor node point to new node
                ++this->size;
                 return true;


            }else if (alignment == END || position == size -1 ){ // if position is size -1 

                newNode->previous = this->tail;
                this->tail->next = newNode;
                this->tail = newNode;
                ++this->size;
                return 1;

            }else if (alignment == NONE){
                // now consider positon orgument 
                // if position is

                if (position < 0 || position >= size) { // if position is invalid then insert at the end 
                    // same code as alighment end
                    newNode->previous = this->tail;
                    this->tail->next = newNode;
                    this->tail = newNode;
                    ++this->size;
                    return 1;
                }else{

                    current = this->head;

                    for (int i = 0 ; i < position - 1 ; ++i){
                        current = current->next;

                    }

                    
                    newNode->next = current->next; // first make newNode's next point to currtent of next 
                    newNode->previous = current;  // make newnode's previous point to current, because that will be previous to new node now
                    current->next = newNode; // now alter next of current make it point to newNode
                    newNode->next->previous = newNode;  // at this point newNode's next  is pointing to the current node 
                    // now we have to make sucessor node point to new node
                    ++this->size;
                    return true;

                }

                // i think all considered all the cases, lets checkt it out 

                
            }

            
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
    list.insert(9, START); //[9]
    list.insert(0, NONE, 0); // [0,9]
    list.insert(8, MIDDLE); //[0,8,9]
    list.insert(15 ,END); // [0,8,9, 15]
    list.insert(11, MIDDLE); // [0, 8, 11 , 9, 15]
    list.insert(41, NONE, 1); // [0, 41, 8 ,11,  , 9, 15]
    list.insert(91, NONE, 4); // [0,41,8,11,91,9,15];

    list.display();
    std::cout<<"\n";
    list.dispalyReverse();





}


