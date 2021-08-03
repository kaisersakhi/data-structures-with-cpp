/*
    Author : Kaiser Sakhi
    Date : 02-08-2021
    Environment : Wsl Ubuntu 20
*/

#include "./includes/doublyLL.h"

int main(){
    
    DoublyLinkedList list;
    list.append(90);
    list.append(99);
    list.append(9);
    list.append(70);
    list.append(880);
    list.display();
    std::cout<<list.getMin()<<"\n";
    list.reverse();
    list.remove();
    
    DoublyLinkedList list2;
    list2.append(11);
    list2.append(12);
    list.merge(list2);// after this operation , list2 will be empty
    list.display(true);

    if (!list.hasLoop())
        std::cout<<"There is no loop in the list!\n";
    return 0;
}