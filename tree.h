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
        newNode->height = 1;
        return newNode;
    }

    // Make a function to insert nodes into the BST (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/;
    // https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    Node2* insertNode(Node2* root, float payload) {
        
        // If the tree is empty, return a new node.
        if (root == nullptr) {
            return createNode(payload);
        }

        // Otherwise, descend the tree.
        if (payload < root->payload) {
            root->left = insertNode(root->left, payload);
        }

        else if (payload > root->payload) {
            root->right = insertNode(root->right, payload);
        }

        // Return the node pointer.
        else {
            return root;
        }

        // Update height of this ancestor node.
        root->height = 1 + max(height(root->left), height(root->right));

        // Get the balance factor of this ancestor node.
        int balance = balanceFactor(root);

        // If this node becomes unbalanced, there are four cases.

        // Left-Left.
        if (balance > 1 && payload < root->left->payload) {
            return rightRotate(root);
        }

        // Right-Right.
        if (balance < -1 && payload > root->right->payload) {
            return leftRotate(root);
        }

        // Left-Right.
        if (balance > 1 && payload < root->right->payload) {
            root->left = leftRotate(root->right);
            return rightRotate(root);
        }

        // Right-Left.
        if (balance < -1 && payload < root->right->payload) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

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

    // Make a function to delete a node based on its value (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/;
    // https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    Node2* deleteNode(Node2* root, float payload) {
        
        if (root == nullptr) {
            return root;
        }

        // If the data to be deleted is smaller than then root's data, then it lies in the left subtree.
        if (payload < root->payload) {
            root->left = deleteNode(root->left, payload);
        }

        // If the data to be deleted is greater than then root's data, then it lies in the right subtree.
        else if (payload > root->payload) {
            root->right = deleteNode(root->right, payload);
        }

        // Delete the node which has the same data as the root.
        else {
            // Account for nodes with one or no children.
            if (root->left == nullptr || root->right == nullptr) {
                Node2* temp = root->left ? root->left : root->right;

                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }

                else{
                    *root = *temp;
                }

                delete temp;
            }

            else {
                Node2* temp = minValueNode(root->right);
                root->payload = temp->payload;
                root->right = deleteNode(root->right, temp->payload);
            }
        }

        if (root == nullptr) {
            return root;
        }

        // Update the height of the current node.
        root->height = 1 + max(height(root->left), height(root->right));

        // Get the balance factor of this node.
        int balance = balanceFactor(root);

        // If this node becomes unbalanced, then there are 4 cases.

        // Left Left Case
        if (balance > 1 && balanceFactor(root->left) >= 0) {
            return rightRotate(root);
        }

        // Left Right Case
        if (balance > 1 && balanceFactor(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Right Case
        if (balance < -1 && balanceFactor(root->right) <= 0) {
            return leftRotate(root);
        }

        // Right Left Case
        if (balance < -1 && balanceFactor(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }


    // Make a function to traverse the tree (https://www.geeksforgeeks.org/cpp/cpp-binary-search-tree/).
    void traverseTree(Node2* root) {
        if (root != nullptr) {
            traverseTree(root->left);
            cout << root->payload << " ";
            traverseTree(root->right);
        }
    }

    // Make a method for checking the height of any given node.(https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    int height(Node2* node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    // Make method to get the balance factor of a node (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    int balanceFactor(Node2* node)
    {
        if (node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    // Make a function to perform a right rotation on a subtree (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    Node2* rightRotate(Node2* y)
    {
        Node2* x = y->left;
        Node2* T2 = x->right;

        // Perform rotation.
        x->right = y;
        y->left = T2;

        // Update heights.
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root.
        return x;
    }

    // Make a function to perform a left rotation on a subtree (https://www.geeksforgeeks.org/cpp/cpp-program-to-implement-avl-tree/).
    Node2* leftRotate(Node2* x)
    {
        Node2* y = x->right;
        Node2* T2 = y->left;

        y->left = x;
        x->right = T2;

        // Update heights.
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root.
        return y;
    }
};