#include "Stack.h"
#include <iostream>
using namespace std;

int main(){
  string expr;
  cout << "Informe a expressao aritimetica";
  getline(cin, expr);

  Stack pilha;
  char temp;
  for(int i = 0; i < expr.length(); i++){
    if(expr[i] == '('){
      pilha.push(expr[i]);
    }
    if(expr[i] == ')'){
      pilha.pop(temp);
    }
  }
  return 0;
}