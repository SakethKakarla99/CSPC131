#include <iostream>
#include <vector>
#include <stack>
using namespace std;


std::vector<std::string> Expression(std::string n){
  std::vector<std::string> expression(n.length());
  for(int i=0; i<n.length(); i++ ){
    expression[i] = n[i];
  }
  return expression;
}

int main() {
  //intialization of the variables
  string answer;
  std::stack<std::string> expression_checker;
  string received_expression;
  std::vector<std::string> expression_given;
  do{
    std::cout << "Enter the string of your choice to check if it is balanced: ";
    std::cin >> received_expression;

    

    expression_given = Expression(received_expression);

    for(int x =0; x < expression_given.size(); x++){
      std::cout << expression_given[x] << " ";

    }
    std::cout << "\n";
    
    for(int e = 0; e < expression_given.size(); e++){
      if(expression_given[e] != ")"){
        expression_checker.push(expression_given[e]);
        
      }
      if(expression_given[e] == ")"){
       if(expression_checker.top() != "(" || expression_checker.empty() == 1){
            throw std::invalid_argument("Unbalanced expression: Missing opening paranthesis");
        }else{
          expression_checker.pop();
          
        }
      }
 
    }
    
   if(expression_checker.size() != 0){
    std::cout << "Expression is unbalanced. " << 
    std::endl;
  }
  else{
    std::cout << "Expression is balanced!" << std::endl;
  }
   std::cout << "Do you still want to test other examples? (yes or no)" << std::endl;
   std::cin>> answer;
   
  } while(answer == "yes");
  
}