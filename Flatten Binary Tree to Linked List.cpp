/* Problem Statement: Flatten Binary Tree To Linked List. Write a program that flattens a given binary tree to a linked list.

Note: 

The sequence of nodes in the linked list should be the same as that of the preorder traversal of the binary tree.
The linked list nodes are the same binary tree nodes. You are not allowed to create extra nodes.
The right child of a node points to the next node of the linked list whereas the left child points to NULL. */

 // Solution 1: Using Recursion


#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(3);
  root -> left -> right = newNode(4);
  root -> right = newNode(5);
  root -> right -> right = newNode(6);
  root -> right -> right -> left = newNode(7);

  Solution obj;

  obj.flatten(root);
  while(root->right!=NULL)
  {
      cout<<root->data<<"->";
      root=root->right;
  }
cout<<root->data;
  return 0;
}


//  Time Complexity: O(N)

//  Space Complexity: O(N)

