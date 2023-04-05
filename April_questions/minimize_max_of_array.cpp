//Problem: Minimize Maximum of Array
//Link: https://www.geeksforgeeks.org/minimize-maximum-of-array/

//Code:
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long sum = 0;
        long long result = 0;
        for (int index = 0; index < nums.size(); ++index) {
            sum += nums[index];
            result = max(result, (sum + index) / (index + 1));
        }
        return (int) result;
    }
};

/*Explanation of the Code:  
    1. we will pass a vector nums in function.
    2. we will take a variable sum and initialize it with 0.
    3. we will take a variable result and initialize it with 0.
    4. we will run a loop till index is less than size of vector nums.
    5. we will increment sum by nums[index].
    6. we will initialize result with max of result and (sum + index) / (index + 1).
    7. we will return result.
*/

//Time Complexity: O(n)