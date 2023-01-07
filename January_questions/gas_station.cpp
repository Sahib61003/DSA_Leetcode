// Problem: Gas Station
// Source: https://leetcode.com/problems/gas-station/

// Code:

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total_gas=0,total_cost=0;
        int curr_gas=0, starting_point=0;
        for(int i=0;i<n;i++)
        {
            total_gas+=gas[i];
            total_cost+=cost[i];
            curr_gas+=gas[i]-cost[i];
            if(curr_gas<0)
            {
                starting_point=i+1;
                 
                curr_gas=0;
            }
        }
        return (total_gas<total_cost)?-1:starting_point;     
    }
};

/* Explanation of the code:
    1. We have two variables total_gas and total_cost. We will use these variables to check if it is possible to complete the circuit or not.
    2. We have two variables curr_gas and starting_point. We will use these variables to find the starting point of the circuit.
    3. We will traverse the gas array and cost array simultaneously.
    4. We will add the gas[i] to total_gas and cost[i] to total_cost.
    5. We will add the gas[i]-cost[i] to curr_gas.
    6. If curr_gas becomes negative, we will update the starting_point to i+1 and curr_gas to 0.
    7. At the end of the loop, we will check if total_gas is less than total_cost. If it is, we will return -1. Else, we will return starting_point.
*/


// Time Complexity: O(n)

