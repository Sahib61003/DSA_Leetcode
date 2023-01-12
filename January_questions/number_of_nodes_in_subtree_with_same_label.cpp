// Problem: Number of nodes in Sub Tree with same label 
// Path: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

//Code: 

class Solution {
public:
    vector<int> ans;
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for(auto &i:edges){
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans.resize(n,0);
        vector<int> count(26,0);
        dfs(0,-1,count,adj,labels);
        return ans;
    }
    void dfs(int node,int parent,vector<int>& count,vector<int> adj[],string &labels){
        for(auto &i:adj[node]){
            if(i!=parent){
                vector<int> counting(26,0);
                dfs(i,node,counting,adj,labels);
                for(int i=0;i<26;i++){
                    count[i]=count[i]+counting[i];
                }
            }
        }
        count[labels[node]-'a']++;
        ans[node]=count[labels[node]-'a'];
    }
};

/* Explanation of the code:
    1. We will use dfs to traverse the tree and count the number of nodes with same label.
    2. We will use a vector of size 26 to count the number of nodes with same label.
    3. We will use a vector of size n to store the answer.
    4. We will use a vector of size n to store the adjacency list of the tree.
    5. We will use a string to store the labels of the nodes.
    6. We will use a for loop to traverse the edges and store the adjacency list of the tree.
    7. We will use a for loop to traverse the adjacency list of the node and call the dfs function.
    8. We will use a for loop to traverse the count vector and add the count of the nodes with same label to the count vector.
    9. We will use a for loop to traverse the count vector and store the count of the nodes with same label in the answer vector.
    10. We will return the answer vector.
*/

// Time Complexity: O(n)