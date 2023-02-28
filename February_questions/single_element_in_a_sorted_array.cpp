//Problem: Single Element in a Sorted Array
//Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

//Code:
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int curr_xor=0; //variable will store XOR
        for(int i =0;i<n;i++){
            curr_xor ^= nums[i]; // XOR
        }
        return curr_xor;
    }
};

/*Explanation of the above Code:
    1. We will use a for loop to traverse the array.
    2. We will use a XOR operator to check if the number is repeated or not.
    3. We will return the XOR.
*/

// Time Complexity: O(n)