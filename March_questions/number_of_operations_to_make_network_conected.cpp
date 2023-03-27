// Problem: Number of Operations to Make Network Connected
// Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

//Code:
class Solution {
    void dfs(vector<int> adj[], vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src]){
            if(!visited[i]){
                dfs(adj, visited, i);
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
        int len = arr.size();
        if(len<n-1) return -1;
         vector<int> adj[n];
        for(auto v : arr)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0; i<n; i++)
        if(!visited[i])
        {
            dfs(adj, visited, i);
            ans++;
        }
        return ans - 1;
    }
};



/*Explanation of the Code:
    1. A function called dfs is declared that takes in a vector of vectors of integers called adj, a vector of booleans called visited, and an integer called src.
    2. The src index of visited is set to true.
    3. A for loop is used to iterate through the vector at adj[src].
    4. If the current value is not found in visited, then the dfs function is called with the current value as the parameter.
    5. The loop continues until the last index is reached.
    6. A function called makeConnected is declared that takes in an integer called n and a vector of vectors of integers called arr.
    7. An integer called len is initialized to the size of arr.
    8. If len is less than n-1, then -1 is returned.
    9. A vector of vectors of integers called adj is declared.
    10. A for loop is used to iterate through arr.
    11. The current value is pushed back into adj at the first index.
    12. The current value is pushed back into adj at the second index.
    13. A vector of booleans called visited is declared.
    14. An integer called ans is initialized to 0.
    15. A for loop is used to iterate from 0 to n.
    16. If the current value is not found in visited, then the dfs function is called with the current value as the parameter.
    17. ans is incremented.
    18. Finally, ans-1 is returned.
    19. The loop continues until the last index is reached.

*/

//Time Complexity: O(n)