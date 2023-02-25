//Problem: Minimum Distance Between BST Nodes
//Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

//Code:
class Solution {
public:

 void inorder(TreeNode* root,vector<int>&ans) {
    
    if(root==NULL) {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans); 
}

int minDiffInBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        int mini = INT_MAX;
        for(int i = 0;i<v.size()-1;++i){
            if(v[i]!=v[i+1]){
                mini = min(mini,v[i+1]-v[i]); 
            }
        }  
        return mini;
    }
};

/*Explanation of the Code:
1. We will use inorder traversal to store the values of the nodes in a vector.
2. Then we will traverse the vector and find the minimum difference between the adjacent elements.
3. We will return the minimum difference.
*/

//Time Complexity: O(n)