//Problem: Reorder Routes to make all paths lead to city zero
//Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

//Code:
class Solution {
public:
    int dfs(vector<vector<int>> &al, vector<bool> &visited, int from) {
    auto change = 0;
    visited[from] = true;
    for (auto to : al[from])
        if (!visited[abs(to)])
            change += dfs(al, visited, abs(to)) + (to > 0);
    return change;        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> al(n);
        for (auto &c : connections) {
            al[c[0]].push_back(c[1]);
            al[c[1]].push_back(-c[0]);
        }
        return dfs(al, vector<bool>(n) = {}, 0);
    }
};

/*Explanation of the Code:
    1. A function called dfs is declared that takes in a vector of vectors of integers called al, a vector of booleans called visited, and an integer called from.
    2. An integer called change is initialized to 0.
    3. The from index of visited is set to true.
    4. A for loop is used to iterate through the vector at al[from].
    5. If the absolute value of the current value is not found in visited, then the dfs function is called with the absolute value of the current value as the parameter.
    6. If the current value is greater than 0, then change is incremented.
    7. The loop continues until the last index is reached.
    8. change is returned.
    9. A function called minReorder is declared that takes in an integer called n and a vector of vectors of integers called connections.
    10. A vector of vectors of integers called al is declared.
    11. A for loop is used to iterate through connections.
    12. The current value is pushed back into al at the first index.
    13. The current value is pushed back into al at the second index.
    14. The absolute value of the current value is pushed back into al at the second index.
    15. The absolute value of the current value is pushed back into al at the first index.
    16. The dfs function is called with al, a vector of booleans of size n, and 0 as the parameters.
    17. The return value of the function is returned.
    18. The loop continues until the last index is reached.

*/

//Time Complexity: O(n)