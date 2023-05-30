//Problem: Stone Game  III
//Link: https://leetcode.com/problems/stone-game-iii/

//Code:
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(3);

        for (int i = n - 1; i >= 0; i--) {
            int takeOne = stoneValue[i] - dp[(i + 1) % 3];
            int takeTwo = INT_MIN;
            if (i + 1 < n) {
                takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];
            }
            int takeThree = INT_MIN;
            if (i + 2 < n) {
                takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3];
            }

            dp[i % 3] = max(takeOne, max(takeTwo, takeThree));
        }

        int scoreDiff = dp[0];
        if (scoreDiff > 0) {
            return "Alice";
        } else if (scoreDiff < 0) {
            return "Bob";
        } else {
            return "Tie";
        }
    }
};

/*Explanation of the Code:
    1. The idea is to use dynamic programming to solve this problem.
    2. The base case of the recursion would be when the list is empty or has just one node.
    3. The recursive function returns the pointer to the swapped list.
    4. The first two lines of the function are the base case.
    5. The third line stores the pointer to the second node in the list in a temporary variable.
    6. The fourth line calls the function recursively for the rest of the list.
    7. The fifth line makes the next of the second node point to the first node.
    8. The sixth line makes the next of the first node point to the rest of the list.
    9. The seventh line returns the pointer to the second node.
*/

// Time Complexity: O(N)

