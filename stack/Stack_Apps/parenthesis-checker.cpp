
#include "../includes/stack_ll.h"
#include <cstring>

class ParenthesisChecker{
    StackLL<std::string> *stack;
    std::string expression;
    
public:
    ParenthesisChecker(std::string exp){
        this->stack = new StackLL<std::string>(exp.length());
        this->expression = exp;
    }

    bool match(){
        if (this->expression.length() > 0){

            for (int i = 0; i < this->expression.length(); ++i){
                   
                if ((this->expression[i] == '{' ) ||(this->expression[i] == '(' )||(this->expression[i] == '[' ) ){

                    this->stack->push(std::string(1,this->expression[i]));

                }else if ((this->expression[i] == '}' )){

                    if ((this->stack->peek()[0]) == '{'){
                           
                        this->stack->pop();
                    }else{
                        return false;
                    }
                }else if (this->expression[i] ==  ')'){

                    if ((this->stack->peek()[0]) == '('){
                            
                        this->stack->pop();
                    }else{
                        return false;
                    }
                }else if ((this->expression[i] ==  ']')){

                    if ((this->stack->peek()[0]) == '['){
                           
                        this->stack->pop();
                    }else{
                        return false;
                    }
                }
            }

            if (this->stack->isEmpty()){
                return true;
            }
            
        }
        return false;
    }
    ~ParenthesisChecker(){
        delete this->stack;
    }

};

int main(){
    std::string exp = "]";
    ParenthesisChecker cheker(exp);
    if (cheker.match()){
        std::cout<<"Expression is valid!\n";
    }else{
        std::cout<<"Expression is invalid!\n";
    }
    return 0;
}