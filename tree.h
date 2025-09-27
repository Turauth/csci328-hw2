#pragma once
#include <iostream>
using namespace std;

struct Node2 {
    Node2* left;
    Node2* right;
    float payload {};
    int height {};
};

class Tree {
public:
    Node2* root;

    // Make a default constructor with the payload of the root node as a parameter.
    Tree (float payload) {
        root = new Node2;

        root->left = nullptr;
        root->right = nullptr;
        root->payload = payload;
        root->height = 1;

        cout << "Tree planted." << endl;
    }

    // Make a function to add a node to the tree (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    Node2* createNode(float payload) {
        Node2* newNode = new Node2;
        newNode->left = newNode->right = nullptr;
        newNode->payload = payload;
        newNode->height = 0;
        return newNode;
    }

    // Make a function to insert nodes into the BST (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    Node2* insertNode(Node2* root, float payload) {
        
        // If the tree is empty, return a new node.
        if (root == nullptr) {
            return createNode(payload);
        }

        // Otherwise, descend the tree.
        if (payload < root->payload) {            
            if (root->left == nullptr) {
                cout << "Node with data " << payload << " will be inserted as left child of the node with data " << root->payload << "." << endl;
            }
            root->height++;        
            root->left = insertNode(root->left, payload);
        }
        else if (payload > root->payload) {
            if (root->right == nullptr) {
                cout << "Node with data " << payload << " will be inserted as right child of node with data " << root->payload << "." << endl;
            }  
            root->right = insertNode(root->right, payload);
        }

        // Return the node pointer.
        return root;
    }

    // Define a function to find the in order successor, which is the smallest node in the right subtree of the current node
    // (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    Node2* minValueNode(Node2* node) {
        Node2* current = node;

        // Descend to the with the smallest value in the subtree.
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Make a function to delete a node based on its value (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    Node2* deleteNode(Node2* root, float payload) {
        
        if (root == nullptr) {
            return root;
        }

        // If the data to be deleted is smaller than then root's data, then it lies in the left subtree.
        if (payload < root->payload) {
            root->left = deleteNode(root->left, payload);
        }

        // If the data to be deleted is greater than then root's data, then it lies in the right subtree.
        if (payload > root->payload) {
            root->right = deleteNode(root->right, payload);
        }

        // Delete the node which has the same data as the root.
        else {
            // Account for nodes with one or no children.
            if (root->left == nullptr) {
                Node2* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node2* temp = root->left;
                delete root;
                return temp;
            }

            // Account for nodes with two children. A function will be defined above to find the in order successor.
            Node2* temp = minValueNode(root->right);

            // Copy the in order successor's content to the temp node and delete the in order succcessor.
            root->payload = temp->payload;
            root->right = deleteNode(root->right, temp->payload);
        }
        return root;
    }


    // Make a function to traverse the tree (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    void traverseTree(Node2* root) {
        if (root != nullptr) {
            traverseTree(root->left);
            cout << root->payload << endl;
            traverseTree(root->right);
        }
    }

    // Make a method for checking the height of any given node. I did not try to make this function on my own
    // (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    int height(Node2* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Make method to get the balance factor of a node (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    int balanceFactor(Node2* node)
    {
        if (node == nullptr)
            return 0;
        return height(node->left) - height(node->right);
    }

    // Make a function to perform a right rotation on a subtree (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    Node2* rightRotate(Node2* y)
    {
        Node2* x = y->left;
        Node2* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height
            = max(height(y->left), height(y->right)) + 1;
        x->height
            = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Make a function to perform a left rotation on a subtree.
    Node2* leftRotate(Node2* x)
    {
        Node2* y = x->right;
        Node2* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights
        x->height
            = max(height(x->left), height(x->right)) + 1;
        y->height
            = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }
};