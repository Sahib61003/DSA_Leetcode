// Problem: Same Tree
// Path: https://leetcode.com/problems/same-tree/

//Code:

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        return(isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

/* Explantion of Code:
    1. If both are NULL then return True.
    2. If one of them do not exist and another exist, we return False.
    3. If two of them are equal to None, we return True.
    4. If none of two above condition holds, we look at children and return True only if values 
    of nodes are equal and if True holds for left and right subtrees.
*/

// Time Complexity: O(n)