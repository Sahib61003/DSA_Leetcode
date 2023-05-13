//Problem: Count way to build good string
//link: https://leetcode.com/problems/count-ways-to-build-good-strings/

//Code:
using namespace std;
class Solution {
    int mod = 1000000007;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high+1 + max(zero, one), 0);

        dp[high]  = 1;

        for(int i = high-1; i >= 0; --i) {
            int takeOne = dp[i + one];
            int takeZero = dp[i + zero];
            dp[i] = ((takeOne + takeZero) + (i >= low)) % mod;
        }

        return dp[0];
    }
};

/*Explanation of the Code:
    1. Creating a variable int mod.
    2. Creating a vector dp of size high+1 + max(zero, one) and initializing it with 0.
    3. dp[high] = 1.
    4. Running a for loop from high-1 to 0.
    5. Creating two variables takeOne and takeZero and initializing them with dp[i + one] and dp[i + zero] respectively.
    6. dp[i] = ((takeOne + takeZero) + (i >= low)) % mod.
    7. Returning dp[0].
*/

//Time Complexity:O(high - low + 1)

