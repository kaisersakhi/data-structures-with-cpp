// #include "./node.h"
#include <iostream>
#include "./includes/singlyLinkedList.h"

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
};

int main(){
    
    DoublyLinkedList list;
    list.append(90);
    list.append(99);
    list.append(9);
    list.append(70);
    list.append(880);
    list.display();
    std::cout<<list.getMin()<<"\n";
    list.display(true);
    return 0;
}