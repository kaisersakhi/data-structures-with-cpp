/*
    Author : Kaiser Sakhi
    Date : 07-23-2021
    Environment : WSL Kali Linux
*/


// Write a program to implement different operations like deleting a node at beginning, end,
// center, after a certain element, after a certain count of nodes in a doubly linked list.


#include <iostream>


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
            std::cout<<"\n";
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

    bool remove(ListPositions alignment = NONE, int position = -1){

        if (this->head == nullptr)
            return false;

        // continue if there are elements in this list
        
        // if size is 1, then there is only one element in the list
        // in this case we will ignore the arguments and empty the list
        if (this->size == 1 ){
            delete this->head;
            this->head = this->tail = nullptr;
            this->size = 0;
            return true;
        }
        
        Node *current = nullptr;
        Node *tempNode = nullptr;
        // regarless what alignment has, if position is set to 0 then remove at start
        // remove at start if postion is not set and 
        // if size is 2 and alignment is middle, then that means we have to alter the head node 
        // and middle point would be 2 / 2, which is also 1, as we count first node will be at position 0
        if (alignment == START || position == 0 || ( ( size == 2 || size == 3) && alignment == MIDDLE )){
             // if size is 2 or 3 and alignemnt is set to middle, int both cases we have to alter head node
             // for size == 3, we are taking floor, so we have to alter the head node 
            current = this->head->next;
            delete this->head;
            this->head = current;
            this->head->previous = nullptr;
            --this->size;
           return true;

        }else if (alignment == MIDDLE || position < size){ // this case will fire only when size > 3 , as we are covering , when size is 2 and 3 , in the above case 

            current = this->head;

            int count = (position > 0 ) ? position - 1 : (int) (this->size / 2);

            for (int i = 0 ; i < count ; ++i){
                current = current->next;
            }
          
            tempNode = current->previous;
            tempNode->next = current->next;
            tempNode = current->next;
            //if (tempNode != nullptr) // when size is 3 and position is supplied temp node will be null
            tempNode->previous = current->previous;
            --this->size ;
            return true;


        }else if (alignment == END || position >= size || alignment == NONE  ){

            current = this->tail;
            this->tail = current->previous;
            this->tail->next = nullptr;
            delete current;
            --this->size;
            return true;

        }
        return false;


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
    list.remove(START); // remove 9
    
    list.display();
    list.remove(NONE, 4); // remove 11
    list.display();
    list.remove(MIDDLE); // 15
    list.display();
    list.remove(NONE, 7); // invalid position, will delete the last node
    list.display();
    list.remove(NONE, 2);
    list.display();
    list.remove(MIDDLE); // 0
    list.display();
    list.remove(END, 0); //41
    list.display(); // display nthing
    std::cout<<"\n";

    return 0;
}