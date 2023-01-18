// Problem: Maximum Sum Circular Subarray 
// Path: https://leetcode.com/problems/maximum-sum-circular-subarray/

// Code:
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int total_sum=0,curr_sum1=0,curr_sum2=0,mxsum_subary=INT_MIN,minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            total_sum+=i; curr_sum1+=i; curr_sum2+=i;
            mxsum_subary=max(mxsum_subary,curr_sum1);
            if(curr_sum1<0) curr_sum1=0;
           minsum_subary=min(curr_sum2,minsum_subary);
            if(curr_sum2>0) curr_sum2=0;
        }
        return (total_sum==minsum_subary)?mxsum_subary:max(mxsum_subary,total_sum-minsum_subary);  
    }
};

/*Explanation of Code:
    1. We will use Kadane's Algorithm to find the maximum sum subarray.
    2. We will also find the minimum sum subarray.
    3. We will also find the total sum of the array.
    4. Now, if the total sum is equal to the minimum sum subarray, then we will return the maximum sum subarray.
    5. Else, we will return the maximum of the maximum sum subarray and the total sum - minimum sum subarray.    
*/

// Time Complexity: O(n)