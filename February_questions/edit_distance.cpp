//Problem: Edit Distance
//Link: https://leetcode.com/problems/edit-distance/

//Code:
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};


/*Explanation of the above Code:
    1. We will use a 2D vector to store the minimum number of operations required to convert word1 to word2.
    2. We will use a for loop to initialize the first row of the vector.
    3. We will use a for loop to initialize the first column of the vector.
    4. We will use a for loop to traverse the vector.
    5. We will use a if condition to check if the characters at the current index of word1 and word2 are equal.
    6. If they are equal then we will store the value of the previous index of the vector in the current index.
    7. Else we will store the minimum of the previous index of the vector, the index above the current index and the index above and to the left of the current index.
    8. We will return the last index of the vector.
*/

// Time Complexity: O(m*n)