//Problem: Count Odd Number in an Interval Range
//Link: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

//Code:
class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (i % 2 != 0) {
                count++;
            }
        }
        return count;   
    }
};

/*Explanation of the Code:
    1. We have to count the number of odd numbers in the given range.
    2. We have to use a for loop to iterate through the range.
    3. We have to check if the number is odd or not.
    4. If the number is odd, we have to increment the count.
    5. Finally, we have to return the count.
*/

//Time Complexity: O(n)