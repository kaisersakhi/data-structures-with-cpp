/*
    Author : Kaiser Sakhi
    Date : 03-09-2021
    Environment : UBUNTU 20.04
*/

// Program : implementation of queue using linked list

#include "includes/queue_ll.h"

/*
    To me, this is the best way to impleemtn the queue
    becuase it take O(1) for both insertion and deletion
*/

int main(){
    QueueLL<int> q;
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    while(!q.isEmpty()){
        std::cout<<q.dequeue()<<" ";
    }

    // std::cout<<q.dequeue()<<" ";
    // std::cout<<q.dequeue()<<" ";
    // std::cout<<q.dequeue()<<" ";
    // std::cout<<q.dequeue()<<" ";
    // std::cout<<q.dequeue()<<" ";
    return 0;
}