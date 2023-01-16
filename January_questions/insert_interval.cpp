// Problem: Insert Interval
// Source: https://leetcode.com/problems/insert-interval/

//Code:

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>>ans;
        for(auto &&i:intervals){

            if(i[1]<newInterval[0])ans.push_back(i);

            else if(newInterval[1]<i[0]){
                ans.push_back(newInterval);
                newInterval=i;
            }

            else{
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }    
        }
        ans.push_back(newInterval);
        return ans;
    }
};

/* Explanation of the code:
    1. We will be using a vector of vectors to store the intervals.
    2. We will be using a for loop to iterate over the intervals.
    3. We will be using a if-else if-else statement to check the conditions.
    4. If the end of the interval is less than the start of the new interval,
        we will push the interval into the answer vector.
    5. If the start of the interval is greater than the end of the new interval, 
        we will push the new interval into the answer vector and
        then we will assign the new interval to the current interval.
    6. If the above two conditions are not satisfied, we will update the start and end of the new interval.
    7. We will push the new interval into the answer vector and return the answer vector.

*/

// Time Complexity: O(n)
