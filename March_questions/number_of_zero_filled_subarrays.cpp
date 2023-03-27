//Problem: Number of Zero-Filled Subarrays
//Link: https://leetcode.com/problems/number-of-zero-filled-subarrays/

//Code:
class Solution {
public:
    long zeroFilledSubarray(vector<int>& nums) {
        long cnt = 0, zeroSubarraysEndingAtCurrentIndex = 0;
        for (int n : nums) {
            if (n == 0) {
                cnt += ++zeroSubarraysEndingAtCurrentIndex;
            } else {
                zeroSubarraysEndingAtCurrentIndex = 0;
            }
        }
        return cnt;
    }
};

/* Explanation of the Code: 
    1. We will use a variable cnt to store the number of zero-filled subarrays.
    2. We will use a variable zeroSubarraysEndingAtCurrentIndex to store the number of zero-filled subarrays ending at the current index.
    3. We will use a for loop to iterate through the vector nums.
    4. We will check if the current element is 0 or not.
        a. If yes, then we will update the value of cnt and zeroSubarraysEndingAtCurrentIndex.
        b. If no, then we will update the value of zeroSubarraysEndingAtCurrentIndex to 0.
    5. We will return the value of cnt.
*/

//Time Complexity: O(n)