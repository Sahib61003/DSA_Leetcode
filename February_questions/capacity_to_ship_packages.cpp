//Problem: Capacity To Ship Packages Within D Days
//Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

//Code:
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int cur = 0, need = 1;
            for (int w : weights) {
                if (cur + w > mid) {
                    cur = 0;
                    need++;
                }
                cur += w;
            }
            if (need <= days) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};

/*Explanation of the above Code:
    1. We will use a binary search to find the minimum capacity.
    2. We will use a lo variable to store the minimum capacity.
    3. We will use a hi variable to store the maximum capacity.
    4. We will use a while loop to run the binary search.
    5. We will use a mid variable to store the mid value of lo and hi.
    6. We will use a cur variable to store the current capacity.
    7. We will use a need variable to store the number of days required.
    8. We will use a for loop to traverse the weights vector.
    9. We will use an if condition to check if the current capacity is greater than the mid value.
    10. If it is greater than the mid value then we will increase the number of days required.
    11. We will use an if condition to check if the number of days required is less than or equal to the given days.
    12. If it is less than or equal to the given days then we will update the hi variable.
    13. Else we will update the lo variable.
    14. We will return the lo variable.
*/

// Time Complexity: O(n*log(sum(weights)))