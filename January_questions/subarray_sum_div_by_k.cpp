//Problem: Subarray Sums Divisible by K
//Path: https://leetcode.com/problems/subarray-sums-divisible-by-k/

//Code:
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(k, 0);
        sums[0]++;
        int cnt = 0;
        int currSum = 0;
        for(int i = 0; i<n; i++) {
            currSum = (currSum + nums[i]%k + k)%k;
            cnt += sums[currSum];
            sums[currSum]++;
        }
        return cnt;
    }
};

/* Explanation of the Code:
    -> We use the concept of prefix sum here.
    -> We calculate the prefix sum of the array and then we calculate the remainder of the prefix sum with k.
    -> We store the number of times a remainder has occured in a vector.
    -> We then calculate the number of subarrays that are divisible by k by using the formula:
    -> Number of subarrays = (Number of times a remainder has occured)*(Number of times a remainder has occured - 1)/2
    -> We do this for all the remainders and then we add them to get the final answer.
*/

//Time Complexity: O(n)
