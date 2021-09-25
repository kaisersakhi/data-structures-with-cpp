/*
    Author : Kaiser Sakhi
    Date : 03-09-2021
    Environment : UBUNTU 20.04
*/


#include "../../dictionary/associative_array.h" // this file alreay includes iostream
#include "../includes/stack_ll.h"


/*
    this postfix is capable of many things, hehehe
    it can convert a simple infix expression into postfix, even if,
    the expression are just variables,
    or, is having brakets, 
    or, is having number, provided that there aren't any varibles with the numbers
*/


class Postfix{
    // this property will hold the infix expression 
    std::string expression;
    bool havingVariables;

    bool isOprand(char op){

        if (op == '+' || op == '-' ||  op == '*' || op == '/' || op == '(' || op == ')')
            return false;
        return true;
    }

    int getPrecedence(char op){
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '(')
            return 3;
        if (op == ')' )
            return 0;
        return -1;
    }

    // this will parse the string into number, if it can
    double getNumber(std::string postfix , int start, int end){
        // create 
        double number = 0;
        for(int i = start; i <= end; ++i){
            if(postfix[i] >= 48 && postfix[i] <= 57){
                number *= 10;
                number  += ((int)postfix[i])-48;
            }
        }
        return number;
    }

public:
    // constructor has 2 args, 
    //1. exp , which can be set at intansiation or at any other point in objects life
    // 2. hasvariables, bool, which show that if we are working with number or not, 
    // 2nd one is helpful for evaluting the expression
    Postfix(std::string exp = "", bool hasVariables = true){
        this->expression = exp;
        this->havingVariables = hasVariables;
    }

    // this method will convert the infix expression which is in 'this->expressio' into postfix
    // can be supplied with two args, withDelimiter , it will put a character inbetween two consection number and 
    // opertaors, and delimeter this is the character that has to be put , by defualt it will be underscore
    std::string toPostfix(bool withDelimeter = false, char delimeter = '_'){

        // if there is nothing in the expression , then return empyt string
        if(this->expression.length() < 1){
            return this->expression;
        }

        //create a stack of maximum length
        StackLL<char> stack(this->expression.length());
        // this string will hold the final output 
        std::string outputString ;

        //iterate the whole string 
        for (int i = 0; i < this->expression.length() ; ++i){

            // if the ith char is not an operator then directly append that to outputstring
            if (this->isOprand(this->expression[i])){
                // if(outputString.length() != 0  && withDelimeter){
                //     outputString += delimeter;
                // }
                outputString += this->expression[i];

            }else{
                //if the ith char is an operator, then
                //1-check if stack is empty , because im performing peek operation , 
                //2- check if stack top is having '(', that means we can push, as the '(' is having a greater precedence than 
                // any other operator
                //3 : if its not '(", then check the precedence 
                if ( stack.isEmpty() || stack.peek() == '(' || ((getPrecedence(expression[i])) > (getPrecedence(stack.peek())))){
                    // this is for the delimeter
                    // if there isn't anything in the output string, then dont appedn ,else
                    // check if withDelimeter is set
                    if(outputString.length() != 0  && withDelimeter){
                        outputString += delimeter;
                    }
                    // push the ith char, either stack is having '(' or the ith char is having greter precednce than the stack top
                    stack.push(this->expression[i]);

                }else{
                    // else, if the ith char is having low or equal precedenc
                    // then pop all the chars from the stack until there is an operator with low precedence than 
                    // the ith char
                    while(getPrecedence(this->expression[i])  <= getPrecedence(stack.peek())){
                        //if stack top is having '(', then that means there is not opertor of local scope to be poped
                        if (stack.peek() == '('){
                            //stack.pop();
                            // end the loop and preseve the opeining brace
                            break;
                        }
                        // this is for delimeter
                        if (withDelimeter)
                            outputString += delimeter;
                        // pop the operator that is having greater precedence then the ith char
                        outputString += stack.pop();
                    }

                    // if ith char is ')', that means we are at the end of local scope and
                    //  we need to end it, by pop the opening brace
                    if (this->expression[i] == ')' && stack.peek() == '('){
                        stack.pop();
                        continue;
                    }
                    // this is for delimeter
                    if(outputString.length() != 0  && withDelimeter){
                        outputString += delimeter;
                    }
                    // else, if the ith expression is having lower precedence then push that 
                    stack.push(this->expression[i]);
                }
            }
        }

        // at this point , we are at the end of expression but there are some opertors in the stack
        // pop them all and append them to output stering
        while(!stack.isEmpty()){
            if (withDelimeter)
                outputString += delimeter;
            outputString += stack.pop();
        }

        // finally return the postfix expression
        return outputString;
    }

    double evaluate(){
        char delimeter = '_';
        std::string postfix = this->toPostfix(true, delimeter);
       
        // if the object was instantiaed without an expression 
        // or there are varibales in the expression,
        // then in both cases, halt and return
        if ((postfix.length() < 1) || !havingVariables) {
            return 0;
        }
        
        // create a stack of maximum len
        StackLL<double> stack(postfix.length());

        // iterate through the string
        for (int i =0 ; i < postfix.length(); ++i){
            // check if a character is oprand , means , it is a number or not
            // if its  a number then isOprand will be true
            if (this->isOprand(postfix[i]) && postfix[i] != delimeter){
                std::string strNum;
                int startingIndex = i;
                //get the first number
                // countinue until we find the first delimeter, that marks the end of 
                // a number
                while(postfix[i] != delimeter){
                    strNum += postfix[i];
                    ++i;
                }
                int endingIndex = i;
                // at this stage we have the number, parse the number
                double number = this->getNumber(postfix,startingIndex,endingIndex);
                // std::cout<<number<<"\n";
                // push the number 
                stack.push(number);
                continue;

            }else if (!this->isOprand(postfix[i])){
                // if its an opereator, then perform the operation on
                // last two pushed numbers of the stack
                double secondNum = stack.pop();
                double firstNum = stack.pop();
                
                if (postfix[i] == '*'){
                    stack.push(firstNum*secondNum);

                }else if(postfix[i] == '/'){
                    stack.push(firstNum/secondNum);
    
                }else if(postfix[i] == '+'){
                    stack.push(firstNum + secondNum);

                }else if(postfix[i] == '-'){
                    stack.push(firstNum - secondNum);
                }
            }
        }
        // if something went wrong and stck was empty , then return 0
        if(!stack.isEmpty()){
            //esle pop the answer from stack and return it
            return stack.pop();
        }
     
        return 0;
    }

    void setExpression(std::string exp){
        this->expression = exp;
    }

    ~Postfix(){
        // if (this->precedenceTable != nullptr)
        //     delete this->precedenceTable;
    }
};

int main(){
    bool having_variables = false;
    bool needDelimeter = false;
    std::string exp = "";
    std::cout<<"Enter The Expression : ";
    std::cin>>exp;
    std::cout<<std::endl;
    std::cout<<"Are we working with variables ? (1 = yes , 0 = NO) :";
    std::cin>>having_variables;
   // having_variables = !having_variables;
    std::cout<<std::endl;
    // if(having_variables != 0){
    //     needDelimeter = true;
    // }
    std::cout<<"Need Delimiter? (1 = yes , 0 = NO) : ";
    std::cin>>needDelimeter;
    std::cout<<std::endl;


    Postfix post(exp, having_variables);
    std::cout<<post.toPostfix(needDelimeter)<<" \n";
    std::cout<<"The Expression is Evaluated To : "<<post.evaluate()<<"\n";
    return 0;
}
 