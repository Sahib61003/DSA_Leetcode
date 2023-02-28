//Problem: Search Insert Position
//Link: https://leetcode.com/problems/search-insert-position/

//Code:
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) { 
       int hi = nums.size()-1, lo=0;
       while(hi >= lo)
       {
         int mid = (hi + lo)/2;
         if(nums[mid]==target) return mid;
         else if(nums[mid] > target) hi = mid - 1;
         else lo = mid + 1;
       }
      return lo;
    }
};

/*Explanation of the above code:
    1. We will use a while loop to check if the high is greater than or equal to the low.
    2. We will use a mid variable to store the middle element.
    3. We will use a if condition to check if the middle element is equal to the target.
    4. If it is then we will return the middle element.
    5. We will use a else if condition to check if the middle element is greater than the target.
    6. If it is then we will update the high to the middle element minus 1.
    7. We will use a else condition to update the low to the middle element plus 1.
    8. We will return the low.
*/

// Time Complexity: O(logn)