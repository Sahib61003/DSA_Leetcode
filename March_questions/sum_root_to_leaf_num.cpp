//Problem: Sum Root to Leaf Numbers
//Link: 

//Code:
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
    int dfs(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        else {
            sum = sum * 10 + root->val;
        }
        if (!root->left && !root->right) {
            return sum;
        }
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};

/*Explanation of the Code:
    1. Initialising a function sumNumbers with parameter root of the tree
    2. Initialising a function dfs with parameters root and sum
    3. If root is null, return 0
    4. Else sum will store 
    5. If root->left and root->right are null, return sum
    6. Else return the sum of dfs(root->left, sum) and dfs(root->right, sum)
*/

//Time Complexity: O(n)
