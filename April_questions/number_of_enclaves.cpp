//Problem: Number of enclaves
//Link: https://leetcode.com/problems/number-of-enclaves/

//Code:
class Solution {
public:
    void dfs(vector<vector<int>>& grid , int i , int j , int m , int n){
        if(i<0 || j <0 || i >= m || j>= n || grid[i][j] == 0){
            return ;
        }
        grid[i][j] = 0;
        dfs(grid ,i + 1 , j , m , n);
        dfs(grid ,i - 1 , j , m , n);
        dfs(grid ,i , j + 1 , m , n);
        dfs(grid ,i , j - 1, m , n);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<n; i++){
            if(grid[0][i]==1) dfs(grid,0,i,m,n);
            if(grid[m-1][i]==1) dfs(grid,m-1,i,m,n);
        }
        
         for(int i=0; i<m; i++){
            if(grid[i][0]==1) dfs(grid,i,0,m,n);
            if(grid[i][n-1]==1) dfs(grid,i,n-1,m,n);
        }
        int cnt = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*Explanation of the above code:
    1. The first line defines a class called "Solution".
    2. The next line defines a public function called "dfs", which is used to perform depth-first search on the grid to find the enclaves. The function takes in the grid, the current row (i), the current column (j), and the total number of rows (m) and columns (n) in the grid as parameters.
    3. The next few lines check if the current cell is out of bounds or if it contains a 0. If either of these conditions is true, the function returns.
    4. If the current cell is a 1, it is set to 0 to mark it as visited, and the dfs function is called recursively for each of its neighboring cells (up, down, left, and right).
    5. The "numEnclaves" function is the main function that returns the number of enclaves in the grid. It takes in the grid as a parameter.
    6. The next two lines define variables "m" and "n" to store the number of rows and columns in the grid, respectively.
    7. The following two for loops check the top and bottom rows and mark all the 1s in those rows as visited by calling the dfs function.
    8. The next two for loops check the leftmost and rightmost columns and mark all the 1s in those columns as visited by calling the dfs function.
    9. Finally, the last for loop counts the number of unvisited 1s in the grid and returns the count as the result.
*/

//Time Complexity : O(logn)
