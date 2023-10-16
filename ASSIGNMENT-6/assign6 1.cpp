#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 

class Stack {
private:
    int top;
    int arr[MAX_SIZE];

public:
    Stack() {
        top = -1; 
    }

    
    void push(int element) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow. Cannot push more elements." << endl;
        } else {
            arr[++top] = element;
            cout << element << " has been pushed onto the stack." << endl;
        }
    }

    
    void pop() {
        if (top < 0) {
            cout << "Stack is empty. Cannot pop an element." << endl;
        } else {
            int poppedElement = arr[top--];
            cout << poppedElement << " has been popped from the stack." << endl;
        }
    }

    
    void display() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= top; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack stack;
    int choice;

    do {
        cout << "\nStack Operations Menu:" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                int element;
                cout << "Enter the element to push onto the stack: ";
                cin >> element;
                stack.push(element);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
