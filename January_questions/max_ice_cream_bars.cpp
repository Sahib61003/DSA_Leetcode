// Problem: Maximum Ice Cream Bars
// Source: https://leetcode.com/problems/maximum-ice-cream-bars/description/

// Code:

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count = 0;
        sort(costs.begin(),costs.end());
        int n = costs.size();
        // for(auto cost : costs) one way to make a loop from i to n.
        for(int i=0; i<n; i++){
            if(costs[i]>coins)break;
            coins -= costs[i];
            count++;
        }
        return count;
    }
};

/* Explanation of Code:
    Sort the costs in ascending order.
    Initialize the count to 0.
    Iterate through the costs.
        If the cost is greater than the coins, break.
        Subtract the cost from the coins.
        Increment the count.
    Return the count.
*/

// Time Complexity : O(nlogn)
