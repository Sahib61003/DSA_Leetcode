//Problem: Summary Ranges
//Link: https://leetcode.com/problems/summary-ranges/

//Code:
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
       vector<string> Res;
        
        if(nums.size() < 1)
           return Res;
        
        for(int i=0;i<nums.size();)
        {
            int low=i;
            int high=i;
            
            while(high+1 < nums.size() && nums[high+1] == nums[high]+1)
                high++;
            
            if(high > low)
                Res.push_back(to_string(nums[low]) + "->" + to_string(nums[high]));
            
            else
                Res.push_back(to_string(nums[high]));
            
            i=high+1;
            
        }  
        
        return Res;
    }
};


/*Explanation of the Code:
    1. We have created a class Solution.
    2. We have created a function summaryRanges.
    3. We have created a vector Res to store the result.
    4. We have created a if statement to check if the size of the vector nums is less than 1.
    5. If the above condition is true, we have returned Res.
    6. We have created a for loop to iterate through the vector nums.
    7. We have created a variable low to store the value of i.
    8. We have created a variable high to store the value of i.
    9. We have created a while loop to check if high + 1 is less than the size of the vector nums and the value of the element at high + 1 is equal to the value of the element at high + 1.
    10. If the above condition is true, we have incremented high by 1.
    11. We have created a if statement to check if the value of high is greater than the value of low.
    12. If the above condition is true, we have pushed the value of the element at low and the value of the element at high to the vector Res.
    13. Else, we have pushed the value of the element at high to the vector Res.
    14. We have set the value of i to high + 1.
    15. We have returned Res.
*/

// Time Complexity: O(n)
