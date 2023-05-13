//Problem: Solving question with brainpower
//link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/

//Code:
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<ll> dp(n+1, 0);
        for(int i=n-1; i>=0 ;i--){
            int point = questions[i][0];
            int jump = questions[i][1];

            int nextQuestion = min(n, i+jump+1);
            dp[i] = max(dp[i+1], point + dp[nextQuestion]);
        }
        return dp[0];
    }
};

/*Explanation of the Code:
    1. Creating a variable int n and initializing it with the size of questions.
    2. Creating a vector dp of size n+1 and initializing it with 0.
    3. Running a for loop from n-1 to 0.
    4. Creating three variables point, jump and nextQuestion and initializing them with questions[i][0], questions[i][1] and min(n, i+jump+1) respectively.
    5. dp[i] = max(dp[i+1], point + dp[nextQuestion]).
    6. Returning dp[0].
*/

//Time Complexity:O(n)
