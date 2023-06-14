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
    1. We have created a class Solution.
    2. We have created a function getMinimumDifference.
    3. We have created a variable min_dif to store the minimum difference.
    4. We have created a variable val to store the value of the node.
    5. We have created a if statement to check if the left node is not NULL.
    6. We have called the function getMinimumDifference with the left node as the parameter.
    7. We have created a if statement to check if the value of val is greater than or equal to 0.
    8. We have updated the value of min_dif to the minimum of min_dif and the difference between the value of the node and val.
    9. We have updated the value of val to the value of the node.
    10. We have created a if statement to check if the right node is not NULL.
    11. We have called the function getMinimumDifference with the right node as the parameter.
    12. We have returned min_dif.
*/

// Time Complexity: O(n)
