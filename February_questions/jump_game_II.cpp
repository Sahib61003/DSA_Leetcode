//Problem: Jump game  II
//Path: https://leetcode.com/problems/jump-game-ii/

//Code:

class Solution {
public:
    int jump(vector<int>& nums) {
      for(int i = 1; i < nums.size(); i++) {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }
      int ind = 0;
      int ans = 0;
      while(ind < nums.size() - 1) {
        ans++;
        ind = nums[ind];
      }
      return ans;
    }
};

/*Explanation of the above code:
    1. We will use the greedy approach to solve this problem.
    2. We will iterate over the array and update the value of the array at each index 
       with the maximum value of the index + the value at the index.
    3. We will then iterate over the array again and find the index which is the maximum value of the index 
       + the value at the index.
    4. We will then update the index to the value of the index which we found in the previous step.
    5. We will repeat the above steps until we reach the last index of the array.
    6. We will return the number of steps taken to reach the last index of the array.
*/

//Time Complexity: O(n)