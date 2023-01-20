//Problem: Non Decreasing Sequences
//Path: https://leetcode.com/problems/non-decreasing-array/

//Code:

class Solution {
    public:
    void helper(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res) {
    if (out.size() >= 2) res.push_back(out);
    unordered_set<int> uset;
    for (int i = start; i < nums.size(); ++i) {
        if (uset.find(nums[i]) != uset.end()) continue;
        if (out.empty() || nums[i] >= out.back()) {
            uset.insert(nums[i]);
            out.push_back(nums[i]);
            helper(nums, i + 1, out, res);
            out.pop_back();
        }
    }
}
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        helper(nums, 0, out, res);
        return res;
    }
};


/*Explanation of Code:
    1. We use a helper function to find all the subsequences.
    2. We use a set to store the elements that we have already used in the current subsequence.
    3. We use a for loop to iterate through the array.
    4. If the element is already used in the current subsequence, we continue.
    5. If the current subsequence is empty or the current element is greater than the last element in the current subsequence,
        we add the element to the current subsequence and call the helper function recursively.
    6. We pop the last element from the current subsequence and continue the for loop.
    7. We return the result.    
*/

//Time Complexity: O(2^n)
