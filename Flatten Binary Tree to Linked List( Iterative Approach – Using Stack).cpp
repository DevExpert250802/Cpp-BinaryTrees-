/* Approach:

The algorithm approach can be stated as:

Take a stack and push the root node to it.
Set a while loop till the stack is non-empty.
In every iteration, take the node at the top of the stack( say cur) and pop the stack.
If cur has the right child, push it to the stack.
If cur has a left child, push it to the stack.
Set the right child of cur to the node at the stack’s top.
Set the left child of cur as NULL.  */

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
  stack < node * > st;
  st.push(root);
  while (!st.empty()) {
    node * cur = st.top();
    st.pop();

    if (cur -> right != NULL) {
      st.push(cur -> right);
    }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    }
    cur -> left = NULL;
  }

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






//===============================================================================================================================================================================================

class Solution {
public:
    void flatten(TreeNode* root) {
      stack<TreeNode*>st;
      if (root == NULL) return;
      st.push(root);
       while (!st.empty()) {
       TreeNode* cur = st.top();
         st.pop();
       if (cur -> right != NULL) {
        st.push(cur -> right);
      }
    if (cur -> left != NULL) {
      st.push(cur -> left);
    }
    if (!st.empty()) {
      cur -> right = st.top();
    cur -> left = NULL;
  }
   }
    }
};


//===============================================================================================================================================================================================


/*  Time Complexity: O(N)

Reason: The loop will execute for every node once.

Space Complexity: O(N) */
