#include <iostream>
#include "./includes/singlyLinkedList.h"


int main(){
    
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(22);
    list.append(4);
    list.append(5);
    //list.pop();
    list.prepend(-10);
    list.append(22);

    // std::cout<<list.get(0)<<"\n";
    //list.display();

    // for (int i = 0; i < list.getLength() ; ++i){
    //     std::cout<<list.get(i)<<"\n";
    // }

    Node *node = list.linearSearch(220);
    if (node != nullptr)
        std::cout<<"Element Found\n";
    else 
        std::cout<<"Element Not Found\n";
    

    // ArrayList<int> occur = (list.findOccurence(22));

    // std::cout<<"We found "<< 22 << " at ";
    // for (int i = 0 ; i < occur.length() ; ++i){
    //     std::cout<<"," <<occur.get(i) <<" ";
    // }

    // list.display();

    // std::cout<<std::endl;

    // int deletedEl = list.remove(0);
    // if (deletedEl != -1)
    //     std::cout<<deletedEl<<" has been deleted at index "<< 0 << " \n";


    // list.display();

    // int size = list.getLength();
    // for (int i = 0 ; i < size ; ++i){
    //     std::cout<<list.remove(0)<< " \n";
    // }

    // std::cout<<list.getLength();

    // list.display();

    // list.remove(); 
    std::cout<<list.getLength();

    if (list.update(1, 56))
        std::cout<<"\nList updated ! "<<list.get(1)<<"\n";
    else
        std::cout<< "Couldn't update the list! \n";
    

    std::cout<<"Smallest Element in the list is : "<<list.getMin()<<"\n";


    list.display();
    //list.rotateRight();
    std::cout<<"\n";
    // list.reverse();

    LinkedList list2;
    list2.append(-90);
    list2.append(80);
   // list2.display();
    list.merge(list2); // after this satement, list2's element will be moved to list, simply put 'cut'
    // at this point , after merge, list2 will have noting of its own.
    
    list2.append(222);
    list.display();
    std::cout<<"list 2 length is : " << list2.getLength()<<"\n";
    list2.display();

    return 0;
}

