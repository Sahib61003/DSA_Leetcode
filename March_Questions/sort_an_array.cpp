//Problem: Sort an array
//Link: https://leetcode.com/problems/sort-an-array/

//Solution:
class Solution {
    public:
    vector<int> sortArray
    (vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};  

//Time Complexity: O(nlogn)

/*Explanation of the Code:
    1. We use the inbuilt sort function to sort the array.
    2. The time complexity of the sort function is O(nlogn).
    3. We return the sorted array.
*/
