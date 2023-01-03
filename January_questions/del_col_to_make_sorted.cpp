// Problem: Delete Columns to Make Sorted
// Source: https://leetcode.com/problems/delete-columns-to-make-sorted/

//Code:
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;

        int rows = strs.size();
        int cols = strs[0].size();

        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows - 1; j++) {
                if (strs[j][i] > strs[j + 1][i]) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};

/* Explanation of Code:
    Initialize counter for number of columns to delete.
    Get the number of rows and columns in the grid.
    Iterate through each column.
        Iterate through each row.
            If the current element is lexicographically greater than the next element,
            increment the counter and break out of the inner loop.
*/

// Time Complexity : O(n * m)
