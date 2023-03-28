//Problem: Minimum Cost for Tickets
//Link: https://leetcode.com/problems/minimum-cost-for-tickets/

//Code:
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366] = {0};
        unordered_set<int> travelDays;
        for (int day : days) {
            travelDays.insert(day);
        }
        for (int i = 1; i <= 365; i++) {
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min(dp[i-1] + costs[0], min(dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2]));
            }
        }
        return dp[365];
    }
};

/*Explanation of the Code:
    1. function mincosTickets will take dats and costs as parameter.
    2. dp array of size 366 is created.
    3. unordered_set travelDays is created.
    4. for loop is used to insert days in travelDays.
    5. for loop is used to iterate from 1 to 365.
    6. if travelDays does not contain i then dp[i] = dp[i-1].
    7. else dp[i] = min(dp[i-1] + costs[0], min(dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2])).
    8. return dp[365].
*/

//Time Complexity: O(n)