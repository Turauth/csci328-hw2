#pragma once
#include <iostream>
using namespace std;

// Define a struct for nodes and make the payload type float.
struct Node
{
    float payload {};
    Node* link;
};

// Define class List to encapsulate linked list behavior.
class List {
private:
    Node temp {};
    bool listIsEmpty { false };

public:
    Node* head;

    // Make a specified constructor that takes in a float number as a parameter and makes it the payload 
    // for the first element of the linked list.
    List(float payload) {
        head = new Node;
        head->payload = payload;
        head->link = nullptr;
    }

    // Define a function to traverse through the whole list and print out its contents
    // (https://www.geeksforgeeks.org/dsa/traversal-of-singly-linked-list/).
    void traverse() {
        Node* currentPointer { head };

        while (currentPointer != nullptr) {
            cout << currentPointer->payload;
            if (currentPointer->link != nullptr) {
                cout << " -> ";
            }
            currentPointer = currentPointer->link;
        }
        cout << endl;
    }

    // Define a function to return the length of the list.
    int len() {
        int length { 0 };
        Node* currentPointer { head };

        while (currentPointer != nullptr) {
            currentPointer = currentPointer->link;
            length +=1;
        }

        return length;
    }

    // Define a function to delete elements at a specified index in the list
    // (https://www.geeksforgeeks.org/cpp/cpp-program-for-deleting-a-node-in-a-linked-list/).
    void del(int index) {
        Node* temp = new Node;
        
        // When the index of the function is zero, delete the head node.
        if (index == 0) {

            // If the list was empty, print an appropriate message.
            if (head == nullptr) {
                cout << "The list was already empty; nothing was deleted." << endl;
                return;
            }

            // Otherwise, delete the head node.
            temp = head;
            head = head->link;
            delete temp;
        }
        
        else if (index > 0) {
            // If the index is greater than or equal to the length of the list, return an appropriate message.
            if (index >= len()) {
                cout << "The specified index is greater than or equal to the length of the list." << endl;
            }

            // If the index is less than the length of the list, delete the corresponding node.
            else {
                Node* currentPointer { head };

                // Walk through the list until the node before the index is reached.
                for (int i { 0 }; i < index - 1; i++) {
                    currentPointer = currentPointer->link;
                }

                // While pointing to the the node before the deletion target, assign the deletion target, reassign its link, and
                // and delete it.
                Node* nodeToDelete = currentPointer->link;
                currentPointer->link = nodeToDelete->link;
                delete nodeToDelete;
            }
        }

        else {
            cout << "The index is out of range." << endl;
        }
    }

    // Define a function to insert elements at a specified index in the list.
    void insert(float payload, int index) {
        Node* newNode = new Node;
        newNode->payload = payload;
        newNode->link = nullptr;

        if (index == 0) {
            // Make the pointer from the new node point to the old head node. Redefine the pointer to the head as pointing to the
            // new node.
            newNode->link = head;
            head = newNode;
            return;
        }

        // For index > 0, find the node at position (index-1)
        Node* currentPointer { head };

        // Traverse to the node just before the insertion point.        
        for (int i { 0 }; i < index - 1; i++) {            
            // If the index is found to be greater than the length of the list, insert the node at the tail of the list.
            if (currentPointer->link == nullptr) {
                currentPointer->link = newNode;
                return;
            }
            currentPointer = currentPointer->link;
        }
        // When the next node would correspond to the index, reassign the link of the current node to the
        // inserted node.
        newNode->link = currentPointer->link;
        currentPointer->link = newNode;
    } 
};