//Problem:  Longest Zigzag path in binary tree
//Link: https://www.leetcode.com/longest-zig-zag-path-in-a-binary-tree/

//Code:
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        vector<int> res = dfs(root);
        return res[2];
    }
    
private:
    vector<int> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {-1, -1, -1};
        }
        
        vector<int> leftSubtree = dfs(node->left);
        vector<int> rightSubtree = dfs(node->right);
        
        int leftLength = leftSubtree[1] + 1;
        int rightLength = rightSubtree[0] + 1;
        int maxLen = max({leftLength, rightLength, leftSubtree[2], rightSubtree[2]});
        
        return {leftLength, rightLength, maxLen};
    }
};

/*Explanation of the Code:
    1. Creating a function which takes treenode root as parameter.
    2. Creating a vector of size 3 and initializing it with -1.
    3. If the root is null, then return the vector.
    4. Creating two vectors leftSubtree and rightSubtree and calling the dfs function on the left and right subtree of the root.
    5. Creating two variables leftLength and rightLength and storing the leftSubtree[1] + 1 and rightSubtree[0] + 1 respectively.
    6. Creating a variable maxLen and storing the maximum of leftLength, rightLength, leftSubtree[2] and rightSubtree[2].
    7. Returning the vector with leftLength, rightLength and maxLen.
*/

//Time Complexity: O(n)