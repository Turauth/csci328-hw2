// Author: J. Woychuk

// Description:

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
    void traverse(Node* head) {       
        while (head != nullptr) {
            cout << head->payload;
            if (head->link != nullptr) {
                cout << " -> ";
            }
            head = head->link;
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
    /*void del(int index) {

        if (index == 0) {
            if (listIsEmpty == true) {
                cout << "The list is empty; there is nothing to delete." << endl;
            }

            else {
                // Store current head in a temporary variable, move head to the next node, and delete the old head node.
                if (head.link != nullptr) {
                    Node temp = head;
                    head = *(head.link);
                    temp.link = nullptr;
                    temp.payload = 9.999;
                    cout << "A new head has been elected." << endl;
                }

                else {
                    head.payload = 9.999;
                    listIsEmpty = true;
                    cout << "The head payload was set to its default value and the list should be empty." << endl;
                }
            }
        }
        
        else if (index > 0) {
            Node currentNode { head };

            for (int i { 0 }; i < index; i++) {

                // If the index is found to be greater than the length of the list, return an appropriate message.
                if (currentNode.link == nullptr) {
                    cout << "The index is greater than the length of the list." << endl;
                }

                else {
                    // Walk through the list until the index is reached or it is discovered that the index is greater than
                    // the length of the list.                    
                    Node nextNode { *(currentNode.link) };
                    currentNode = nextNode;

                    // When the next step would correspond to the index, set its payload value to the default and check whether 
                    // the next node is the tail.
                    if (i == index - 1) {
                        nextNode.payload = 9.999;
                        
                        if (nextNode.link == nullptr) {
                            // If the next node is the tail, cut the pointer to it.
                            currentNode.link = nullptr;
                            cout << "Tail node deleted" << endl;
                        }

                        else {
                            // If the next node is not the head or the tail, move the link from the current node to link to
                            // the node after the node being deleted and cut the link from the deleted node.
                            currentNode.link = nextNode.link;
                            nextNode.link = nullptr;
                            cout << "Middle node deleted." << endl;
                        }                            
                    }
                }
            }
        }

        else {
            cout << "The index is out of range." << endl;
        }
    }*/

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
            
            cout << "A node was inserted at the head of the list." << endl;
            return;
        }

        // For index > 0, find the node at position (index-1)
        Node* currentPointer = head;

        // Traverse to the node just before the insertion point.        
        for (int i { 0 }; i < index - 1; i++) {
            
            // If the index is found to be greater than the length of the list, insert the node at the tail of the list.
            if (currentPointer->link == nullptr) {
                currentPointer->link = newNode;
                
                cout << "The index is greater than the length of the list. ";
                cout << "The node was inserted at the tail of the list." << endl;
                return;
            }
            currentPointer = currentPointer->link;
        }
            // When the next node would correspond to the index, reassign the link of the current node to the
            // inserted node.
            newNode->link = currentPointer->link;
            currentPointer->link = newNode;
            cout << "A node was inserted between the head and tail of the list." << endl;
    } 
};