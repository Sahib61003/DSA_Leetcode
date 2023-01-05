// Problem: Minimum Number of Arrows to Burst Balloons
// Source: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

// Code: 

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end()); 
        int lastpoint = p[0][1];
        int ans = 1;
        for(auto point : p) {
            if(point[0] > lastpoint) {
                ans++;
                lastpoint = point[1];
            }
            lastpoint = min(point[1],lastpoint);
        }
        return ans;
    }
};

/* Explaination of the code:
    Sort the points in ascending order of their starting points.
    Initialize the lastpoint to the ending point of the first point.
    Initialize the answer to 1.
    Iterate through the points.
        If the starting point of the current point is greater than the lastpoint,
        increment the answer and update the lastpoint to the ending point of the current point.
        Update the lastpoint to the minimum of the ending point of the current point and the lastpoint.
    Return the answer.
*/

// Time Complexity : O(nlogn)
