//Problem: Sign of the product of an array
//Link: https://leetcode.com/problems/sign-of-the-product-of-an-array

//Code:
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int result = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                result = 0;
                break;
            }
            if (nums[i] < 0) {
                result *= -1;
            }
        }
        return result;       
    }
};

/*Explanation of the Code:  
    1. We will iterate over the vector nums.
    2. If we encounter a 0, we will return 0.
    3. If we encounter a negative number, we will multiply the result by -1.
    4. We will return the result.
*/

//Time Complexity: O(n)
