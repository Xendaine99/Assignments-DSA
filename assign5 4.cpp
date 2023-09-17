#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPrefix(string infix) {
    stack<char> operators;
    stack<string> operands;
    reverse(infix.begin(), infix.end());

    for (char c : infix) {
        if (isalnum(c)) {
            operands.push(string(1, c));
        } else if (c == ')') {
            operators.push(c);
        } else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                string operand1 = operands.top();
                operands.pop();
                string operand2 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string temp = op + operand2 + operand1;
                operands.push(temp);
            }
            operators.pop();  // Pop ')'
        } else {
            while (!operators.empty() && getPrecedence(c) <= getPrecedence(operators.top())) {
                string operand1 = operands.top();
                operands.pop();
                string operand2 = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                string temp = op + operand2 + operand1;
                operands.push(temp);
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        string operand1 = operands.top();
        operands.pop();
        string operand2 = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        string temp = op + operand2 + operand1;
        operands.push(temp);
    }

    return operands.top();
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
