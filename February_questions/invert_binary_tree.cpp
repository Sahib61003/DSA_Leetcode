//Problem: Invert Binary Tree
//Link: https://leetcode.com/problems/invert-binary-tree/

//Code:
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

       if(root == NULL){
           return root;
       }
       swap(root->left, root->right);
       invertTree(root->left);
       invertTree(root->right);

       return root;
    }
};

/*Explanation of the above code:
1. Created a invert tree function which takes a root node as a parameter.
2. If the root is NULL, we will return the root.
3. We will swap the left and right child of the root.
4. We will call the invert tree function recursively for the left and right child of the root.
5. We will return the root.
*/

// Time Complexity: O(n)