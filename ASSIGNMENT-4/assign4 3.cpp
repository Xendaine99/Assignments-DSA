#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class CircularDoublyLinkedList {
private:
    Node* head;

public:
    CircularDoublyLinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtFirst(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Function to insert a node at the end
    void insertAtLast(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
        }
    }

    // Function to delete the first node
    void deleteAtFirst() {
        if (head) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head;
                head->prev->next = head->next;
                head->next->prev = head->prev;
                head = head->next;
                delete temp;
            }
        }
    }

    // Function to delete the last node
    void deleteAtLast() {
        if (head) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                Node* temp = head->prev;
                temp->prev->next = head;
                head->prev = temp->prev;
                delete temp;
            }
        }
    }

    // Function to insert a node at the middle
    void insertAtMiddle(int value, int position) {
        if (position <= 0) {
            insertAtFirst(value);
        } else {
            Node* newNode = new Node(value);
            Node* current = head;
            int count = 0;
            while (current && count < position) {
                current = current->next;
                count++;
            }
            if (current) {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
            }
        }
    }

    // Function to delete a node at the middle
    void deleteAtMiddle(int position) {
        if (position <= 0) {
            deleteAtFirst();
        } else {
            Node* current = head;
            int count = 0;
            while (current && count < position) {
                current = current->next;
                count++;
            }
            if (current && current != head) {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
    }

    // Function to traverse and print the linked list
    void traverse() {
        Node* current = head;
        if (current) {
            do {
                std::cout << current->data << " ";
                current = current->next;
            } while (current != head);
        }
        std::cout << std::endl;
    }
};

int main() {
    CircularDoublyLinkedList myList;
    myList.insertAtFirst(1);
    myList.traverse();
    cout<<"INSERTING VALUES AT HEAD"<<endl;
    myList.insertAtFirst(2);
    myList.traverse();
    cout<<"INSERTING VALUES AT TAIL"<<endl;
    myList.insertAtLast(3);
    myList.traverse();
    cout<<"INSERTING VALUES AT MIDDLE"<<endl;
    myList.insertAtMiddle(4, 1);
    myList.traverse();
    cout<<"DELETING VALUES AT HEAD"<<endl;
    myList.deleteAtFirst();
    myList.traverse();
    cout<<"DELETING VALUES AT TAIL"<<endl;
    myList.deleteAtLast();
    myList.traverse();
    cout<<"DELETING VALUES AT MIDDLE"<<endl;
    myList.deleteAtMiddle(1);
    myList.traverse();
    return 0;
}