#include <iostream>

using namespace std;

// Node class for singly linked list
class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// LinkedList class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Method to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // Method to swap elements in groups of 2
    void swapPairs() {
        Node* current = head;
        while (current != nullptr && current->next != nullptr) {
            int temp = current->data;
            current->data = current->next->data;
            current->next->data = temp;
            current = current->next->next;
        }
    }

    // Method to append a node to the end of the linked list
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* lastNode = head;
        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }

    // Method to display the linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// DoublyNode class for circular doubly linked list
class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

// CircularDoublyLinkedList class
class CircularDoublyLinkedList {
public:
    DoublyNode* head;

    CircularDoublyLinkedList() {
        head = nullptr;
    }

    // Method to append a node to the end of the circular doubly linked list
    void append(int data) {
        DoublyNode* newNode = new DoublyNode(data);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }
        DoublyNode* lastNode = head->prev;
        lastNode->next = newNode;
        newNode->prev = lastNode;
        newNode->next = head;
        head->prev = newNode;
    }

    // Method to display the circular doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        DoublyNode* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    // Reverse a linked list
    LinkedList linkedList;
    for (int i = 1; i <= 5; i++) {
        linkedList.append(i);
    }
    cout << "Original linked list:" << endl;
    linkedList.display();
    linkedList.reverse();
    cout << "Reversed linked list:" << endl;
    linkedList.display();

    // Swap elements in a linked list in groups of 2
    linkedList = LinkedList();
    for (int i = 1; i <= 5; i++) {
        linkedList.append(i);
    }
    cout << "\nOriginal linked list:" << endl;
    linkedList.display();
    linkedList.swapPairs();
    cout << "Linked list after swapping pairs:" << endl;
    linkedList.display();

    // Create a circular doubly linked list
    CircularDoublyLinkedList circularList;
    for (int i = 1; i <= 5; i++) {
        circularList.append(i);
    }
    cout << "\nCircular doubly linked list:" << endl;
    circularList.display();

    return 0;
}
