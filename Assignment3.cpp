#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//this is the function that helps to put the expression given by user into a vector that can be expressed back to the user so they can see what expression they typed before the balance checker happens
std::vector<std::string> Expression(std::string &n){
  std::vector<std::string> expression(n.length());
  for(int i=0; i<n.length(); i++ ){
    expression[i] = n[i];
  }
  return expression;
}

int main() {
  //intialization of the variables
  string answer;
  std::stack<char> expression_checker_stack;
  string received_expression;



    // Allows the user to write an expression of parantheses to see if it is balanced. 
    std::cout << "Enter the string of your choice to check if it is balanced: ";
    std::cin >> received_expression;

    //using above function to put the received expression into an array to be displayed
    std::vector<std::string> expression_given(received_expression.length());

    expression_given = Expression(received_expression);

    std::cout << "This is the received expression: ";
    for(int x =0; x < expression_given.size(); x++){
      std::cout << expression_given[x] << " ";

    }
    std::cout << "\n";
    /* this big for loop iterates through the received expression and placing '(' into a stack and popping when ')' 
     is seen and the expression_check.top() is '(' */
    for(int e = 0; e < received_expression.length(); e++){
      if(received_expression[e] != ')'){
        expression_checker_stack.push(received_expression[e]);
        
      }
      if(received_expression[e] == ')'){
      /*right here is a special case where we have an expression that has ')' as the first char which auto is 
      unbalanced*/
       if(expression_checker_stack.empty() ==1  || expression_checker_stack.top() != '('){
            throw std::invalid_argument("Unbalanced expression.");
        }
       else{
          expression_checker_stack.pop();
          
        }
      }
 
    }
  //finally we have the last step which checks to see if the stack is empty and if it isnt then it is unbalanced.
   if(expression_checker_stack.size() != 0){
    std::cout << "Expression is unbalanced! " << 
    std::endl;
  }
  else{
    std::cout << "Expression is balanced!" << std::endl;
  }
  
  
  
}