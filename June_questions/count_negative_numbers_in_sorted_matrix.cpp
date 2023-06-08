//Problem: Count negative number in sorted matrix
//Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

//Code:
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int ub = upper_bound(grid[i].rbegin(),grid[i].rend(),-1) - grid[i].rbegin();
            ans += ub;
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. We have created a function countNegatives.
    2. We have created a variable n to store the size of the grid.
    3. We have created a variable ans to store the answer.
    4. We have created a for loop to iterate through the grid.
    5. We have created a variable ub to store the upper bound of the grid.
    6. We have added ub to ans.
    7. We have returned ans.
*/

// Time Complexity: O(nlogn)
