//Problem: kth Missing Positive Integer
//Link: https://leetcode.com/problems/kth-missing-positive-number/

//Code:
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] - mid - 1 < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left + k;
    }
};

/*Explanation of the Code:
    1. Creating a function consisting of integer array and integer variable k as parameter.
    2. Creating two variables left and right and assigning them to 0 and arr.size()-1 respectively.
    3. Creating a while loop which will run until left is less than or equal to right.
    4. Creating a variable mid and assigning it to left + (right - left) / 2.
    5. Creating an if-else statement which will check if arr[mid] - mid - 1 is less than k.
    6. If the condition is true then left will be assigned to mid + 1.
    7. Else right will be assigned to mid - 1.
    8. Returning left + k.
    9. left + k is the kth missing positive integer.
*/

//Time Complexity: O(log n)