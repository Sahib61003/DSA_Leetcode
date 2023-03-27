//Problem: Minimum Score of Path Between 2 Cities
//Link: https://leetcode.com/Minimum-Score-of-Path-Between-2-Cities/

//Code:
class Solution {
public:
    unordered_set<int> s;
    unordered_map<int, vector<int>> mp;
    int minScore(int n, vector<vector<int>>& roads) {
        for(auto& r:roads) {
            mp[r[0]].push_back(r[1]);
            mp[r[1]].push_back(r[0]);
        }
        dfs(1);
        int ans = INT_MAX;
        for(auto& r:roads) {
            if(s.find(r[0]) != s.end()) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
    }
    void dfs(int root) {
        if(s.find(root) != s.end()) return;
        s.insert(root);
        for(auto&child : mp[root]) {
            dfs(child);
        }
    }
};

/*Explanation of the Code:
    1. An unordered_set of integers called s is declared.
    2. An unordered_map of integers to vectors of integers called mp is declared.
    3. A function called minScore is declared that takes in an integer called n and a vector of vectors of integers called roads.
    4. A for loop is used to iterate through the roads vector.
    5. The current value is pushed back into mp at the first index.
    6. The current value is pushed back into mp at the second index.
    7. The dfs function is called with the value 1 as the parameter.
    8. An integer called ans is initialized to INT_MAX.
    9. A for loop is used to iterate through the roads vector.
    10. If the first index of the current value is found in s, then ans is set to the minimum of itself and the third index of the current value.
    11. The loop continues until the last index is reached.
    12. Finally, ans is returned.
    13. A function called dfs is declared that takes in an integer called root.
    14. If the root is found in s, then the function returns.
    15. The root is inserted into s.
    16. A for loop is used to iterate through the vector at mp[root].
    17. The dfs function is called with the current value as the parameter.
    18. The loop continues until the last index is reached.
*/    

//Time Complexity: O(n)