/*
Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.
If the diagonal element are present in two different subtress then left subtree diagonal element should be taken first and then right subtree. 
*/


vector<int> diagonal(Node *root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front();
            q.pop();
            
            // Traverse down the right child
            while (node) {
                if (node->left)
                    q.push(node->left);
                ans.push_back(node->data);
                node = node->right;
            }
        }
    }
    
    return ans;
}

/*
Input :
            8
          /   \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13
Output : 8 10 14 3 6 7 13 1 4
*/
