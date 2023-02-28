//Problem: Best Time to Buy and Sell Stock
//Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

//Code:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        int low = 0;
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < prices[low]) {
                low = i;
                continue;
            }
            maxprofit= max(maxprofit, prices[i] - prices[low]);
        }
        return maxprofit;
    }
};

/*Explanation of the above code:
    1. We will use a for loop to traverse the array.
    2. We will use a if condition to check if the price is less than the price at the lowest index.
    3. If it is then we will update the lowest index.
    4. We will use a max function to check if the maximum profit is greater than the price at the current index minus the price at the lowest index.
    5. We will return the maximum profit.
*/

// Time Complexity: O(n)