//Problem: Check Completeness of a Binary Tree
//Path: leetcode.com/problems/check-completeness-of-a-binary-tree/

//Code:
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*>q;
        q.push(root);
        bool nullSeen=false; 

        while(!q.empty()){ 
            int levelSize=q.size(); 
            while(levelSize--){    
                TreeNode* tp=q.front();
                q.pop();
                if(!tp) nullSeen=true; 
                else{
                    if(nullSeen) return false; 
                    q.push(tp->left);
                    q.push(tp->right);
                }
            }
        }
        return true;
    }
};

/*Explanation of the Code:
    1. We use a queue to traverse the tree level by level.
    2. We use a boolean variable, nullSeen, to check if we have seen a null node.
    3. If we have seen a null node, then we should not see any other node after that.
    4. If we see a node after a null node, then the tree is not complete.
    5. We traverse the tree level by level.
    6. We check if the current node is null.
    7. If it is null, then we set nullSeen to true.
    8. If it is not null, then we check if nullSeen is true.
    9. If it is true, then we return false.
    10. If it is false, then we push the left and right children of the current node into the queue.
    11. We return true if we have traversed the entire tree.
*/

//Time Complexity: O(n)
