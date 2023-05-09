//Problem : Spiral Matrix
//Link: https://www.leetcode.com/challenges/spiral-matrix

//Code:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }
        
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols-1, top = 0, bottom = rows-1;
        
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;
            
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
            }
            right--;
            
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return result;
    }
};

/*Explanation of the Code:
    1. Created a function which takes vector of vector matrix as input.
    2. Created a vector result which will store the result.
    3. If the matrix is empty or the matrix[0] is empty then we will return the result.
    4. Created a variable rows which will store the size of the vector matrix.
    5. Created a variable cols which will store the size of the vector matrix[0].
    6. Created a variable left which will store the value 0.
    7. Created a variable right which will store the value cols - 1.
    8. Created a variable top which will store the value 0.
    9. Created a variable bottom which will store the value rows - 1.
    10. Created a while loop which will run till left <= right and top <= bottom.
    11. Created a for loop which will iterate from left to right.
    12. Stored the value of matrix[top][i] in the vector result.
    13. Incremented the value of top by 1.
    14. Created a for loop which will iterate from top to bottom.
    15. Stored the value of matrix[i][right] in the vector result.
    16. Decremented the value of right by 1.
    17. Created an if statement which will run if top <= bottom.
    18. Created a for loop which will iterate from right to left.
    19. Stored the value of matrix[bottom][i] in the vector result.
    20. Decremented the value of bottom by 1.
    21. Created an if statement which will run if left <= right.
    22. Created a for loop which will iterate from bottom to top.
    23. Stored the value of matrix[i][left] in the vector result.
    24. Incremented the value of left by 1.
    25. At last we will return the vector result.
*/

// Time Complexity: O(n)