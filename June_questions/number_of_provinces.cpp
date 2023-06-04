// Problem: Number of Provinces
// Link: https://leetcode.com/problems/number-of-provinces/submissions/

//Code:
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinces++;
                dfs(isConnected, visited, i);
            }
        }
        return provinces;
    }
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int node) {
        visited[node] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(isConnected, visited, neighbor);
            }
        }
    }
};

/*Explanation of the Code:
    1. We have created a function findCircleNum.
    2. We have created a vector visited of size n and initialized it with false.
    3. We have created a for loop to iterate through the matrix.

    4. We have created a if statement to check if the node is not visited.
    5. If the node is not visited, we have incremented the provinces.
    6. We have called the dfs function.
    7. We have created a dfs function.
    8. We have passed the parameters isConnected, visited and node.
    9. We have set the visited[node] to true.
    10. We have created a for loop to iterate through the matrix.
    11. We have created a if statement to check if the node is connected to the neighbor and the neighbor is not visited.
    12. If the above condition is true, we have called the dfs function.
*/

// Time Complexity: O(n^2)
