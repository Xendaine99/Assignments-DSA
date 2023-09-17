#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');  // Convert char to integer and push it onto the stack
        } else if (isOperator(c)) {
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        s.push(operand1 / operand2);
                    } else {
                        cout << "Error: Division by zero" << endl;
                        return -1;
                    }
                    break;
            }
        }
    }

    if (!s.empty()) {
        return s.top();
    } else {
        cout << "Error: Invalid postfix expression" << endl;
        return -1;
    }
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfix(postfixExpression);
    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
