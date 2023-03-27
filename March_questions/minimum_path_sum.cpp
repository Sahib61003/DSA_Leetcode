//Problem: Minimum Path Sum
//Link: https://leetcode.com/problems/minimum-path-sum/

//Code:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and j!=0) grid[i][j]+=grid[i][j-1];
                if(j==0 and i!=0) grid[i][j]+=grid[i-1][j];
                if(i!=0 and j!=0) grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid[n-1][m-1];
    }
};

/*Explanation of the Code:
    1. We will use dynamic programming to solve this problem.
    2. We will use a 2D vector to store the information about the minimum path sum.
    3. We will use a variable n to store the number of rows in the grid.
    4. We will use a variable m to store the number of columns in the grid.
    5. We will use a for loop to traverse the grid.
    6. We will use a nested for loop to traverse the grid.
    7. We will check if the current node is in the first row.
        a. If yes, then we will check if the current node is in the first column.
            i. If yes, then we will do nothing.
            ii. If no, then we will update the value of the current node by adding the value of the previous node in the same row.
        b. If no, then we will check if the current node is in the first column.
        i. If yes, then we will update the value of the current node by adding the value of the previous node in the same column.
            ii. If no, then we will update the value of the current node by adding the minimum of the value of the previous node in the same row and the value of the previous node in the same column.
    8. We will return the value of the last node in the grid.
*/

//Time Complexity: O(n*m)