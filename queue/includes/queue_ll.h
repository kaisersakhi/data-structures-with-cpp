#include<iostream>

template<class T>
struct Node{
    T data;
    Node<T> *next;
};

template <class Type>
class QueueLL{
private:
    Node<Type> *front;
    Node<Type> *rear;
    int length;
public:
    QueueLL(){
        this->front = nullptr;
        this->rear = nullptr;
        this->length = 0;
    }

    bool enqueue(Type element){

        if (this->isFull()) return false;

        Node<Type> *newNode = new Node<Type>;
        newNode->data = element;
        newNode->next = nullptr;

        if (this->rear == nullptr){
            this->front = this->rear = newNode;
            ++this->length;
            return true;
        }else{
            this->rear->next = newNode;
            this->rear = newNode;
            ++this->length;
            return true;
        }
    }

    Type dequeue(){
        Type t;
        if (this->front == nullptr) {
            std::cout<<"\nError: Queue Is Already Empty\n";
            return t;
        }

        if (this->front == this->rear){
            // that means, there is only one node in the queue;
            Type x = this->front->data;
            this->front = this->rear = nullptr;
            --this->length;
            return x;
        }

        Type x = this->front->data;
        Node<Type> *temp = this->front;
        this->front = this->front->next;
        delete temp;
        --this->length;
        return x;
    }

    bool isFull(){
        // this will check if there is space in the heap at all
        // or we can limit the number of instants of this class using a static counter 

        Node<Type> *c = new Node<Type>;
        if (c == nullptr)
            return true;
        delete c;
        return false;
    }


    bool isEmpty(){
        return (this->front == nullptr);
    }

    Type getFront(){
        Type t;
        if (this->front != nullptr)
            return this->front->data;
        return t;
    }
    Type getRear(){
        Type t;
        if (this->rear != nullptr)
            return this->rear->data;
        return t;
    }

    ~QueueLL(){
        Node<Type> *temp = this->front;

        while (temp != nullptr){
            this->front = this->front->next;
            delete temp;
            temp = this->front;
        }
    }

};