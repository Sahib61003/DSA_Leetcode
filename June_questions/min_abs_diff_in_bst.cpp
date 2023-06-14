//Problem: Minimum Absolute difference in BST
//Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

//Code:
class Solution {
public:
    int min_dif = INT_MAX;
    int val = -1;
int getMinimumDifference(TreeNode* root) {
    if (root->left != NULL)
        getMinimumDifference(root->left);
    if (val >= 0)
        min_dif = min(min_dif, root->val - val);
    val = root->val;
    if (root->right != NULL)
        getMinimumDifference(root->right);
    return min_dif;
    }
};

/*Explanation of the Code:

*/

//Time Complexity: 
