//Problem: Uncrossed Lines
//Link: https://leetcode.com/problems/uncrossed-lines/

//Code:
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        vector<int> dp(n + 1);
        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int curr = dp[j];
                if (nums1[i-1] == nums2[j-1]) {
                    dp[j] = prev + 1;
                } else {
                    dp[j] = max(dp[j-1], curr);
                }
                prev = curr;
            }
        }
        return dp[n];
    }
};



/*Explanation of the Code:
    1. Creating a variable m which store size of nums1 and n which store size of nums2.
    2. If m is less than n then swap nums1 and nums2 and swap m and n.
    3. Creating a vector dp of size n+1.
    4. Creating a loop from 1 to m.
    5. Creating a variable prev and initialize it with 0.
    6. Creating a loop from 1 to n.
    7. Creating a variable curr and initialize it with dp[j].
    8. If nums1[i-1] is equal to nums2[j-1] then dp[j] is equal to prev + 1.
    9. Else dp[j] is equal to max(dp[j-1], curr).
    10. prev is equal to curr.
    11. Return dp[n].
*/

//Time Complexity: O(m*n)
