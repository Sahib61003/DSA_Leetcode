//Problem: Shuffle the Array
//Path: https://leetcode.com/problems/shuffle-the-array/

//Code: 
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        
        for(int i =0 ;i < n;i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+n]);
        }
        return ans;
    }
};

/*Explanation of the above code:
    1. initialising vector integer ans.
    2. for loop to iterate through the array.
    3. pushing the elements of the array in the ans vector.
    4. returning the ans vector.
*/

//Time Complexity: O(n)