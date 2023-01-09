// Problem: Binary Tree Preorder Traversal
// Source: https://leetcode.com/problems/binary-tree-preorder-traversal/

// Code:

// This is recursive approach.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      if(root){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }        
};

/*Explanation of the above code:
    1. The code is pretty simple. We just have to traverse the tree in preorder fashion and push the values in the vector.
    2. We use recursion to traverse the tree.
    3. We push the value of the root node in the vector and then call the function recursively for the left and right subtrees.
    4. We return the vector.
*/      

// This is iterative approach.
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        while (root || !st.empty()) {
            if (root) {
                ans.push_back(root -> val);
                if (root -> right) {
                    st.push(root -> right);
                }
                root = root -> left;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};
/* Explanation of the above code:
    1. We use a stack to store the right child of the root node.
    2. We push the value of the root node in the vector and then check if the root node has a right child.
    3. If it has a right child, we push it in the stack.
    4. We then move to the left child of the root node.
    5. If the root node is NULL, we pop the top element from the stack and make it the root node.
    6. We repeat the above steps until the root node is NULL and the stack is empty.
    7. We return the vector.
*/

// Time Complexity: O(n)