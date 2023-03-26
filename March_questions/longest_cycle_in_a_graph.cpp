//Problem: Longest Cycle in a Graph
//Link: https://leetcode.com/problems/longest-cycle-in-a-graph

//code:
class Solution {
public:
    int mx=-1;
    void dfs(vector<int> &ed , vector<int> &pvis , vector<int> &vis , int i , int j){
        if(pvis[i]){
            mx = max(mx , j - pvis[i]);
            return;
        }
        if(!vis[i]){
            pvis[i] =j; j++; vis[i]=1;
            if(ed[i]!=-1) dfs(ed , pvis , vis , ed[i],j);
        }
        pvis[i] = 0;
        return;
    }

    int longestCycle(vector<int>& ed) {
        vector<int> vis(ed.size(),0) , pvis(ed.size(),0);
        mx = -1;
        for(int i=0;i<ed.size();i++){
            if(!vis[i]) dfs(ed,pvis,vis,i,1);
        }
        return mx;
    }
};

/*Explanation of the Code:
1. We will use dfs to find the longest cycle in the graph.
2. We will use 3 vectors to store the information about the nodes.
3. The first vector will store the edges of the graph.
4. The second vector will store the information about the nodes which are currently in the recursion stack.
5. The third vector will store the information about the nodes which are already visited.
6. We will use a variable mx to store the maximum length of the cycle.
7. We will use a function dfs to find the longest cycle in the graph.
8. The function will take 4 parameters:
    a. The first parameter will be the vector which stores the edges of the graph.
    b. The second parameter will be the vector which stores the information about the nodes which are currently in the recursion stack.
    c. The third parameter will be the vector which stores the information about the nodes which are already visited.
    d. The fourth parameter will be the current node.
9. We will check if the current node is already in the recursion stack.
    a. If yes, then we will update the value of mx.
    b. If no, then we will check if the current node is already visited.
        i. If yes, then we will return.
        ii. If no, then we will update the value of the current node in the recursion stack and update the value of the current node in the visited vector.
        iii. We will check if the current node has an edge or not.
            1. If yes, then we will call the function dfs recursively.
            2. If no, then we will return.
10. We will return the value of mx.
*/

//Time Complexity: O(n)