 //    Write a program for Morris's Preorder Traversal of a Binary Tree.


vector < int > preorderTraversal(node * root) {
  vector < int > preorder;

  node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      preorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        preorder.push_back(cur -> data);
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        cur = cur -> right;
      }
    }
  }
  return preorder;
  
}


 /*
Time Complexity: O(N).

Space Complexity: O(1)

   */
