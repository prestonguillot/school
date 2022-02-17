#include "stack.h"
#include "queue.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <fstream.h>

using namespace std;
using namespace STACK_CLASS_CSC307;
using namespace QUEUE_CLASS_CSC307;

void pause() {
    char dummy;
    cout << "\nPress any key to continue.\n";
    dummy = getch();
}

int infixpriority(char token) {
    switch(token) {
        case '(':
            return 4;
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case ')':
            return 0;
        case '$':
            return 0;
    }
}

int stackpriority(char token) {
    switch(token) {
        case '^':
            return 3;
        case '*':
            return 2;
        case '/':
            return 2;
        case '+':
            return 1;
        case '-':
            return 1;
        case '(':
            return 0;
        case '$':
            return 0;
    }
}

queue<char,50> infix2postfix(char string[]) {
    queue<char,50> infix,postfix;
    stack<char,50> operators;
    int i;
    char token = ' ',token2;

    for(i = 0;string[i] != '$';i++)
        infix.enqueue(string[i]);
    infix.enqueue('$');
    
    operators.push('$');
    while(token != '$') {
        token = infix.dequeuex();
        if(isdigit(token))
                postfix.enqueue(token);
        else if(token == ')') {
                token2 = operators.popx();
                while(token2 != '(') {
                     postfix.enqueue(token2);
                     token2 = operators.popx();
                }
       }
       else if(token == '$') {
                while(!operators.empty())
                     postfix.enqueue(operators.popx());
       }
       else {
                while(stackpriority(operators.top()) >= infixpriority(token))
                     postfix.enqueue(operators.popx());
                operators.push(token);
       }
    }
    return postfix;
}

float postfixeval(queue<char,50> postfix) {
    stack<float,50>  operand;
    float operand1,operand2;
    char x;

    for (x = postfix.dequeuex();x != '$';x = postfix.dequeuex()) {
        if(isdigit(x))
                operand.push(x - 48);
        else {
                if(x == '+') {
                   operand.push(operand.popx() + operand.popx());      
                }
                else if(x == '*') {
                   operand.push(operand.popx() * operand.popx());
                }
                else if(x == '-') {
                   operand2 = operand.popx();
                   operand1 = operand.popx();
                   operand.push(operand1 - operand2);
                }
                else if(x == '/') {
                   operand2 = operand.popx();
                   operand1 = operand.popx();
                   operand.push(operand1 / operand2);
                }
                else if(x == '^') {
                  operand2 = operand.popx();
                  operand1 = operand.popx();              
                  operand.push(pow(operand1,operand2));
                }
        }
    }
    return operand.popx();
}

int main() {
queue<char,50> postfix;
char string[50];
ifstream infile;
int ch;

infile.open("posfix.dat");
while((ch = infile.peek()) != EOF) {
    infile.getline(string,50,'\n');
    postfix = infix2postfix(string);
    cout << "Infix notation:          " << string << endl
         << "Postfix notation:        " << postfix << endl
         << "Evaluated Expresssion:   " << postfixeval(postfix) << endl << endl;
}


pause();
return EXIT_SUCCESS;
}
