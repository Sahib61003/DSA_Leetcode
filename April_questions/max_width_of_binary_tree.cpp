//Problem: Maximum Width of Binary Tree
//Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/

//Code:
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
    	size_t ans = 1;
    	if(root){
    		queue<pair<TreeNode*, size_t>> q;
    		q.push({root, 0});
    		
    		while(!q.empty()){
				ans = max(ans, q.back().second-q.front().second+1);
    			int size = q.size();
    			for(int i = 0; i<size; i++){
    				TreeNode* current = q.front().first;
    				size_t curInd = q.front().second;
    				q.pop();
    				if(current->left){
    					q.push({current->left, curInd*2});
    				}
    				if(current->right){
    					q.push({current->right, curInd*2+1});
    				}
    			}
    		}
    	}
    	return (int)ans;   
    }
};

/*Explanation of the Code:
    1. We have created a function which take input of treenode root.
    2. We have created a queue of pair of treenode and size_t.
    3. We have pushed the root and 0 in the queue.
    4. We have created a while loop which will run until the queue is empty.
    5. We have created a for loop which will run until the size of the queue.
    6. We have created a treenode current which will store the first element of the queue.
    7. We have created a size_t curInd which will store the second element of the queue.
    8. We have popped the first element of the queue.
    9. We have created a if condition which will check if the left child of the current node is not null.
    10. If the condition is true then we have pushed the left child of the current node and the index of the left child in the queue.
    11. We have created a if condition which will check if the right child of the current node is not null.
    12. If the condition is true then we have pushed the right child of the current node and the index of the right child in the queue.
    13. We have created a if condition which will check if the size of the queue is greater than the ans.
    14. If the condition is true then we have updated the ans with the size of the queue.
    15. We have returned the ans.
*/

//Time Complexity: O(n)