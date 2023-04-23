//Problem: Binary Search
//Link: https://leetcode.com/problems/binary-search/

//Code

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg = 0, end = nums.size() - 1;
        while(beg<end){
            int mid = beg + (end-beg)/2;
            if(nums[mid] >= target){
                end = mid;
            }else{
                beg = mid + 1;
            }
        }

        if(nums[beg] != target){
            return -1;
        }
        return beg;
    }
};

/*Explanation of the Code:      
    1. The function search takes in a vector of integers called nums and an integer called target.
    2. Two integers called beg and end are initialized to 0 and nums.size()-1 respectively.
    3. A while loop is used to iterate through the nums vector until beg is greater than or equal to end.
    4. An integer called mid is initialized to beg + (end-beg)/2.
    5. If the value at index mid in the nums vector is greater than or equal to target, then end is assigned the value of mid.
    6. Otherwise, beg is assigned the value of mid + 1.
    7. This is done to check if the target is in the first half of the nums vector or the second half.
    8. The loop continues until beg is greater than or equal to end.
    9. If the value at index beg in the nums vector is not equal to target, then -1 is returned.
    10. Otherwise, beg is returned.
*/
    
// Time Complexity: O(logn)
