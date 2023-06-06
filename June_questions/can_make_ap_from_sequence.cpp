//Problem: Can make Arithmetic Progression from sequence
//Link: https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

//Code:
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // write the code
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};

/*Explanation of the Code:
    1. We have created a function canMakeArithmeticProgression.
    2. We have sorted the array.
    3. We have created a for loop to iterate through the array.
    4. We have created a if statement to check if the difference between the current element and the previous element is not equal to the difference between the second element and the first element.
    5. If the above condition is true, we have returned false.
    6. We have returned true.
*/

// Time Complexity: O(nlogn)
