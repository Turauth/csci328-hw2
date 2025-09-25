// Author: J. Woychuk

// Description:

#pragma once
#include <iostream>
using namespace std;

// Define a struct for nodes and make the payload type float with a default value of -999999.
struct Node
{
    float payload {-999999};
    Node *link;
};

// Define class List to encapsulate linked list behavior.
class List
{
public:
    Node head {};

    // Make a specified constructor that takes in a float number as a parameter and makes it the payload 
    // for the first element of the linked list.
    List(float payload) {
        head.payload = payload;
        head.link = nullptr;
    }

    // Define a function to traverse through the whole list and print out its contents. This definition was
    // developed using the recursive approach on this page:
    // https://www.geeksforgeeks.org/dsa/traversal-of-singly-linked-list/.
    void traverse(Node currentNode) {     
        
        // Print the current node data and return if the current node's link is null.
        cout << currentNode.payload << endl;
        if (currentNode.link == nullptr) {
            return;
        }

        // Print an arrow if there are more nodes in the list and move to the next node.
        if (currentNode.link != nullptr) {
            cout << " -> ";
        }

        traverse(*currentNode.link);
    }

    // Define a function to return the length of the list.
    int len(List list) {
        int length { 0 };
        Node currentNode { list.head };

        if (currentNode.payload != -999999) {
            length += 1;
        }

        while (currentNode.link != nullptr) {
            Node currentNode = *currentNode.link;
            length +=1;
        }

        return length;
    }

    // Define functions to delete and insert elements at a specified index in the list
    // (https://www.geeksforgeeks.org/cpp/cpp-program-for-deleting-a-node-in-a-linked-list/).
    void del(int index) {
        if (index == 0) {
            if (&head == nullptr) {
                cout << "List is empty; there is nothing to delete." << endl;
                return;
            }

            // Store current head in a temporary variable, move head to the next node, and delete the old head node.
            Node temp = head;
            head = *head.link;
            delete &temp;
            cout << "Head node deleted." << endl;
        }
        
        else {
            cout << "No nodes deleted." << endl;
        }
    }
};