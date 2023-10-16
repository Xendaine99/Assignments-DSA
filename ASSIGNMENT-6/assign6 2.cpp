#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr; 
    }

    
    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
        cout << element << " has been pushed onto the stack." << endl;
    }

    
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop an element." << endl;
        } else {
            int poppedElement = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << poppedElement << " has been popped from the stack." << endl;
        }
    }

    
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            Node* current = top;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
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
