//Problem: Minimum Time To collect Apple From Tree
// Path: leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

// Code: 

class Solution {
public:
    vector<vector<int>> adjList;
    int dfs(vector<bool>& hasApple,int node,int d,int prev)
    {
        int result=0,temp;
        for(int &i:adjList[node])
	    if(i!=prev)
	    {
	        temp=dfs(hasApple,i,d+1,node);
	        if(temp) result+=temp-d;
	    }
        return result||hasApple[node]?result+d:0; 
        
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) 
    {
        adjList.resize(n);
        for(vector<int> &e:edges)
            adjList[e[0]].push_back(e[1]),adjList[e[1]].push_back(e[0]);
        return dfs(hasApple,0,0,-1)*2;
    }
};

/* Explanation of Code:
    1. We will use DFS to traverse the tree and find the minimum time to collect all the apples.
    2. We will use a vector of vector to store the adjacency list of the tree.
    3. We will use a DFS function to traverse the tree and find the minimum time to collect all the apples.
    4. We will use a vector of boolean to store the information whether the node has an apple or not.
    5. We will use a variable result to store the result of the function.
    6. We will use a variable temp to store the result of the recursive call.
    7. We will use a for loop to traverse the adjacency list of the node.
    8. We will use a if condition to check if the node is not the previous node.
    9. We will call the DFS function recursively and store the result in temp.
    10. We will use a if condition to check if the temp is not equal to 0.
    11. We will add the result with temp-d.
    12. We will return the result.
    13. We will use a if condition to check if the result is not equal to 0 or the node has an apple.
    14. We will return the result+d.
    15. We will return the result of the DFS function multiplied by 2.    
*/

// Time Complexity: O(n)
 
