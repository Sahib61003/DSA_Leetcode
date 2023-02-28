//Problem: Find Duplicate Subtree
//Link: https://leetcode.com/problems/find-duplicate-subtrees/

//Code:
class Solution {
public:
    string f(TreeNode* root,vector<TreeNode*>&ans, map<string,int> &mp){
        if(!root) {
            return "%";
        }
        string l = f(root->left,ans,mp);
        string r = f(root->right,ans,mp);
        string s = to_string(root->val) +"%"+l+"%"+r;
        if(mp[s]==1){
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> ans;
        map<string,int> mp;
        if(!root) return ans;
        f(root,ans,mp);
        return ans;
    }
};
/*Explanation of the above code:
    1. We will use a map to store the frequency of the string.
    2. We will use a vector to store the nodes which have frequency greater than 1.
    3. We will use a string to store the value of the node and the value of its left and right child.
    4. We will use a function to traverse the tree and store the string in the map.
    5. We will return the vector which will contain the nodes which have frequency greater than 1.
*/

// Time Complexity: O(n)