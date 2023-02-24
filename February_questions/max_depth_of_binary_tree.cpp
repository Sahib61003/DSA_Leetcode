//Problem: Maximum Depth of the Binary Tree
//Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

//Code:
class Solution {
public:

    int maxDepth(TreeNode* root) {
        
        if(root==NULL) return 0;

        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*Explanation of the code:
    1. We will use a recursive function to find the maximum depth of the binary tree.
    2. We will use a base case to check if the root is NULL.
    3. If the root is NULL, we will return 0.
    4. We will return the maximum of the maximum depth of the left subtree and the maximum depth of the right subtree plus 1.
*/

// Time Complexity: O(n)