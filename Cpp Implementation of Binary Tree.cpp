// C++ implementation of Binary tree


#include <bits/stdc++.h>
// using namespace std; // This line is commented out since it's not needed in this code.

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void display(Node* root) {
    if (root == NULL)
        return;

    // Traverse the left subtree
    display(root->left);

    // Print the data of the current node
    std::cout << root->data << " "; // Added a space to separate the values

    // Traverse the right subtree
    display(root->right);
}

int main() {
    // Create a binary tree
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Call the display function to perform an in-order traversal and print the tree
    display(root);

    return 0;
}



/* output :   4251637


      1
     / \
    2   3
   / \ / \
  4  5 6  7

*/
        
