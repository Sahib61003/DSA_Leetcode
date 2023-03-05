//Problem: Count Subarrays with Same Bound
//Link: leetcode.com/problems/count-subarrays-with-same-bound/

//Code:

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if (num == minK) {
                minFound = true;
                minStart = i;
            }
            if (num == maxK) {
                maxFound = true;
                maxStart = i;
            }
            if (minFound && maxFound) {
                res += (min(minStart, maxStart) - start + 1);
            }
        }
        return res;
    }
};

/*Explanation of the Code:
    1. It takes a vector of integers, an integer "minK" and an integer "maxK" as arguments and returns a long integer.
    2. It first uses a variable "res" to store the result.
    3. It then uses three boolean variables "minFound", "maxFound" and "start" to keep track of the current index in the original vector "i" and the current index in the compressed vector "j".
    4. It uses a for loop to traverse the vector and check if the current element is less than "minK" or greater than "maxK".
    5. If it is, it sets "minFound" and "maxFound" to false and sets "start" to the current index plus 1.
    6. If the current element is equal to "minK", it sets "minFound" to true and "minStart" to the current index.
    7. If the current element is equal to "maxK", it sets "maxFound" to true and "maxStart" to the current index.
    8. If both "minFound" and "maxFound" are true, it adds the minimum of "minStart" and "maxStart" minus "start" plus 1 to "res".
    9. Finally, it returns "res".
*/

//Time Complexity: O(n)