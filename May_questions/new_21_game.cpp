//Problem: New 21 Game
//Link: https://leetcode.com/problems/new-21-game/


//Code:

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
           if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        vector<double> dp(n + 1);
        double currSum = 1.0;
        double ans = 0.0;
        dp[0] = 1.0;
        for (int i = 1; i < n+1; i++) {
            dp[i] = currSum / maxPts;
            if (i < k) 
                currSum += dp[i];
             else 
                ans += dp[i];
            if (i - maxPts >= 0) 
                currSum -= dp[i - maxPts];
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. If k is equal to 0 or n is greater than or equal to k + maxPts then return 1.0.
    2. Creating a vector dp of size n+1.
    3. Creating a variable currSum and initialize it with 1.0.
    4. Creating a variable ans and initialize it with 0.0.
    5. dp[0] is equal to 1.0.
    6. Creating a loop from 1 to n.
    7. dp[i] is equal to currSum / maxPts.
    8. If i is less than k then currSum is equal to currSum + dp[i].
    9. Else ans is equal to ans + dp[i].
    10. If i - maxPts is greater than or equal to 0 then currSum is equal to currSum - dp[i - maxPts].
    11. Return ans.
*/

//Time Complexity: O(n)
