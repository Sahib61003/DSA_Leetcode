// Problem: Max Points on a Line
// Source: https://leetcode.com/problems/max-points-on-a-line/

//Code:
class Solution {
public:
    int maxPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            unordered_map<double, int> mp;
            int temp_max = 0;
            int x1 = arr[i][0];
            int y1 = arr[i][1];
            for(int j = 0; j < n; j++){
                if(j == i){
                    continue;
                }
                int x2 = arr[j][0]; 
                int y2 = arr[j][1];
                double nume = y2 - y1; 
                double deno = x2 - x1;
                if(deno == 0){
                    mp[INT_MAX]++;
                    temp_max = max(temp_max, mp[INT_MAX]);                   
                    continue;
                }               
                double slope = nume / deno;               
                mp[slope]++; 
                temp_max = max(temp_max, mp[slope]);
            }
            maxi = max(maxi, temp_max + 1);
        }
        return maxi;
    }
};

/* Explanation:
    1. We will take each point as a reference point and find the slope of all the other points with respect to the reference point.
    2. We will store the slope in a map and the value will be the number of points having that slope.
    3. We will also keep a variable temp_max which will store the maximum number of points having the same slope.
    4. We will also keep a variable maxi which will store the maximum number of points having the same slope.
    5. We will return maxi at the end.
*/

// Time Complexity: O(n^2)
// Space Complexity: O(n)