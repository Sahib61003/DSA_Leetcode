//Problem: Maximum value of k coins from piles
//Link: https://leetcode.com/maximum-value-k-coins-piles/

//Code:
class Solution {
public:
      int maxValueOfCoins(vector<vector<int>>& A, int K) {
        int n = A.size();
        vector<vector<int>> memo(n + 1, vector<int>(K + 1, 0));
        function<int(int, int)> dp = [&](int i, int k) {
            if (memo[i][k] > 0){
                return memo[i][k];
            }
            if (i == n || k == 0){ 
                return 0;
            }
            int res = dp(i + 1, k), cur = 0;
            for (int j = 0; j < A[i].size() && j < k; ++j) {
                cur += A[i][j];
                res = max(res, dp(i + 1, k - j - 1) + cur);
            }
            memo[i][k] = res;
            return res;
        };
        return dp(0, K);
    }
};

/*Explanation of the Code in 10 lines:
1. We have a vector of vectors A, which contains the coins in each pile.
2. We have a variable K, which is the number of coins we can take.
3. We have a variable n, which is the number of piles.
4. We have a memoization table, which is a vector of vectors, which stores the maximum value of coins we can take from the piles.
5. We have a function dp, which takes two parameters, i and k.
6. If the memoization table has a value greater than 0, then we return that value.
7. If i is equal to n or k is equal to 0, then we return 0.
8. We have a variable res, which stores the maximum value of coins we can take from the piles.
9. We have a variable cur, which stores the current value of coins we can take from the piles.
10. We return the maximum value of coins we can take from the piles. 
*/

//Time Complexity: O(n^2)
