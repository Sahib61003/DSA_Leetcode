//Problem: Matrix Diagnol Sum
//Link: https://leetcode.com/problems/matrix-diagonal-sum/

//Code:
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }
        if (n % 2 == 1) {
            sum -= mat[n / 2][n / 2];
        }
        return sum;   
    }
};

/*Explanation of the Code:
    1. Created a function which takes vector of vector mat as input.
    2. Created a variable sum which will store the sum of the diagnol elements.
    3. Created a variable n which will store the size of the vector mat.
    4. Created a for loop which will iterate from 0 to n.
    5. Incremented the sum by mat[i][i].
    6. Incremented the sum by mat[i][n - i - 1].
    7. If the value of n is odd then we will decrement the sum by mat[n / 2][n / 2].
    8. At last we will return the sum.
*/

// Time Complexity: O(n)