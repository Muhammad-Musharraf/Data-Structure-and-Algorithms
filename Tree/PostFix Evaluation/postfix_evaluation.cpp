#include <iostream>
#include <stack>
#include <string>

// if "infixToPostfix" u can use expr like this:
        // a+b-c/x*y+5
        // 4+6-2/1*3+5
    
// For "PostFix Evaluation" u need expr in single digits only:
        // 4+6-2/1*3+5
        // 12*3-12*+11*23*-<31!=&&

using namespace std;

int prec(char op){
    if(op == '*' || op == '/' || op == '%') return 2;
    if(op == '+' || op == '-') return 1;

    // ===== OR =====
     
    // switch(op){
    //     case '*':
    //     case '/':
    //     case '%':
    //         return 2; 
    //     case '+':
    //     case '-':
    //         return 1;
    //     default:
    //         return 0;
    // }
}

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

string infixToPostfix(string expr){
    stack<char> s;      // holds operators temporarily
    string output = "";

    for(int i = 0; i < expr.length(); i++){
        char c = expr[i];

        if(!isOperator(c) && c != '(' && c != ')'){
            output += c;
        }

        else if(c == '('){
            s.push(c);
        }

        else if(c == ')'){
            while(!s.empty() && s.top() != '('){
                output += s.top();
                s.pop();
            }
            s.pop(); 
        }

        else if(isOperator(c)){
            while(!s.empty() && prec(s.top()) >= prec(c)){
                output += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while(!s.empty()){
            output += s.top();
            s.pop();
    }

    return output;
}

int postfixEvaluation(string postExpr){
    stack<int> s; // holds numbers

    for(int i = 0; i < postExpr.length(); i++){
        char c = postExpr[i];

        // if(isdigit(c)){
        //     s.push(c);
        // }

        if(c >= '0' && c <= '9'){
            s.push(c - '0');
        }

        else if(isOperator(c)){
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();

            switch (c)
            {
            case '+': s.push(a+b); break;
            case '-': s.push(a-b); break;
            case '*': s.push(a*b); break;
            case '/': s.push(a/b); break;

            default:
                break
                ;
            }

        }
    }
    return s.top();
}

int main() { 
    // a-b+c/x*y+5
    // 12-31/4*+5+

    string infixExpr = "";
    string postfixExpr = "";
    int postfixEval;
    string postfixEvalDigits = "";

    cout << "(Infix to Postfix) Enter the infix expression: ";
    cin >> infixExpr;

    postfixExpr = infixToPostfix(infixExpr);
    cout << "Postfix Expression is: " << postfixExpr << endl;

    cout << "Enter the postfix Expression in digits (single digits only): ";
    cin >> postfixEvalDigits;
    postfixEval = postfixEvaluation(postfixEvalDigits);
    cout << "Postfix Evaluation is: " << postfixEval << endl;

    return 0;
}