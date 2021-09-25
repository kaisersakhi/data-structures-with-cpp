/*
    Author : Kaiser Sakhi
    Date : 04-08-2021
    Environment : Wsl Ubuntu 20

*/

#include <iostream>
#include <cmath>

struct Term{

    int cofficient;
    int power;
    Term *next; // its like the head of the list
};

class Polynomail{
    int size; // this will store the count of terms or nodes
    Term *list;

public:
    Polynomail(){
        this->size = 0; // initilize size to 0
        this->list = nullptr;
    }
    bool insert(int cofficient, int power){
        Term *term = new Term;
        term->cofficient = cofficient;
        term->power = power;
        term->next = nullptr;

        if (this->list == nullptr){
            list = term;
            ++this->size;
            return 1;
        }else{
            Term *current = this->list;

            while(current->next != nullptr){
                current = current->next;
            }
            current->next = term;
            ++this->size;
            return 1;
        }
        return 0; // i know, unreachable
    }
    
    void display(){
        if (this->list != nullptr){
            Term *current = this->list;
            char sign = '+';
            while(current != nullptr ){

                if (current->cofficient > 0 && current != list){
                    std::cout<<sign;
                }
                std::cout<<current->cofficient;
                
                if (current->power > 0){
                    std::cout<<"x";//whenver power is zero, then dont show variable X,
                }
                
                if (current->power > 1){
                    std::cout<<"^"<<current->power;
                }
                current = current->next;
            }
            std::cout<<"\n";
        }
    }

    int evaluate(int x){
        int sum = 0;

        if (this->list != nullptr){

            Term *current = this->list;

            while(current != nullptr){
                sum +=  current->cofficient * pow(x, current->power);
                current = current->next;                                                                              
            }
        }
        return sum;
    }


    Polynomail *operator+ (Polynomail &poly){
        Polynomail *sum = nullptr;

        Term *p = nullptr;
        Term *q = nullptr;
        //int longestListLength = (this->size > poly.size) ? this->size : poly.size;

        p = this->list;
        q = poly.list;

        sum = new Polynomail;

        while (p != nullptr || q != nullptr){

            if (p->power > q ->power){
                sum->insert(p->cofficient, p->power);
                p = p->next;
            }else if (p->power < q->power){
                sum->insert(q->cofficient, q->power);
                q = q->next;
            }else{
                sum->insert(q->cofficient + p->cofficient, q->power);
                p = p->next;
                q = q->next;
            }

        }

        while (p != nullptr){
            sum->insert(p->cofficient, p ->power);
            p = p->next;
        }
        while (q != nullptr){
            sum->insert(q->cofficient, q->power);
            q = q->next;
        }

        return sum;
    } 



};

int main(){
    Polynomail poly;
    poly.insert(4,2);
    //poly.insert(3,1);
    poly.insert(-2,1);
    poly.insert(4, 0);

    Polynomail poly2;
    poly2.insert(1, 3);
    poly2.insert(2,2);
    poly2.insert(4,0);

    Polynomail *sum = poly + poly2;

    if (sum != nullptr){
        sum->display();
        delete sum;
    }
    
    //poly.display();
    //std::cout<<"The polynomail evaluates to : "<<poly.evaluate(4)<<"\n";

    return 0;
       
}