//Problem: Binary Tree Zigzag Level Order Traversal
//Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

//Code:
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)return ans;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
           int sz=q.size();
           vector<int>v;
           while(sz--){
               TreeNode * f=q.front();
               v.push_back(q.front()->val);
               q.pop();
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);

           }
           if(i++%2)
           reverse(v.begin(),v.end());
           ans.push_back(v);

        }
        return ans;
    
    }
};

/* Explanation of the above code:
    1. We will use a vector to store the final answer.
    2. We will use a queue to store the nodes of the tree.
    3. We will use a for loop to traverse the queue.
    4. We will use a while loop to traverse the queue.
    5. We will use a if condition to check if the level is even or odd.
    6. If it is even then we will push the nodes in the vector.
    7. If it is odd then we will push the nodes in the vector in reverse order.
    8. We will return the vector which will contain the nodes in zigzag order.
*/

// Time Complexity: O(n)