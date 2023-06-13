//Problem: Equal Row and Columnn Pair
//Link: https://leetcode.com/problems/equal-row-and-column-pairs/

//Code:
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> hashmap;
        int ans = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i=0; i<row; i++) {
            hashmap[grid[i]]++;
        }
        for (int j=0; j<col; j++) {
            vector<int> curr;
            for (int i=0; i<row; i++) {
                curr.emplace_back(grid[i][j]);
            }
            ans += hashmap[curr];
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. We have created a class Solution.
    2. We have created a function equalPairs.
    3. We have created a map hashmap to store the vector and its frequency.
    4. We have created a variable ans to store the answer.
    5. We have created a variable row to store the size of the vector grid.
    6. We have created a variable col to store the size of the vector grid[0].
    7. We have created a for loop to iterate through the vector grid.
    8. We have inserted the vector grid[i] and its frequency to the map hashmap.
    9. We have created a for loop to iterate through the vector grid[0].
    10. We have created a vector curr.
    11. We have created a for loop to iterate through the vector grid.
    12. We have inserted the value of the element at grid[i][j] to the vector curr.
    13. We have added the value of the frequency of the vector curr to the variable ans.
    14. We have returned ans.
*/

// Time Complexity: O(n*m)

