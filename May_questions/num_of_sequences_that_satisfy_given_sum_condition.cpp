//Problem: Number of Sequences thatsatisfy given sum condition
//Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

//Code:
class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), l = 0, r = n - 1, mod = 1e9 + 7;
        vector<int> pows(n, 1);
        for (int i = 1 ; i < n ; ++i)
            pows[i] = pows[i - 1] * 2 % mod;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            } else {
                res = (res + pows[r - l++]) % mod;
            }
        }
        return res;
    }
};

/*Explanation of the Code:
    1. Created a function which takes vector nums and integer target as input.
    2. Sorted the vector nums.
    3. Created a variable res which will store the number of subsequences that satisfy the given sum condition.
    4. Created a variable n which will store the size of the vector nums.
    5. Created a variable l which will store the left index of the vector nums.
    6. Created a variable r which will store the right index of the vector nums.
    7. Created a variable mod which will store the value of 10^9 + 7.
    8. Created a vector pows which will store the power of 2.
    9. Created a for loop which will iterate from 1 to n.
    10. Stored the power of 2 in the vector pows.
    11. Created a while loop which will run until the value of l is less than or equal to r.
    12. If the sum of nums[l] and nums[r] is greater than target then we will decrement the value of r by 1.
    13. Else we will increment the value of res by pows[r - l++].
    14. At last we will return the value of res.
*/

// Time Complexity: O(nlogn)
