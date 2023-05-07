//Problem: Find the longest valid obstacle course at each position
//Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

//Code:
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> v(obstacles.size(),(int)1e9), ans;
        for(int x: obstacles){
            auto ub = upper_bound(begin(v), end(v), x);
            ans.emplace_back(ub - v.begin() + 1);
            *ub = x;
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. Created a function which takes vector obstacles as input.
    2. Created a vector v which will store the value of 10^9.
    3. Created a vector ans which will store the longest valid obstacle course at each position.
    4. Created a for loop which will iterate through the vector obstacles.
    5. Created a variable ub which will store the upper bound of the vector v.
    6. Stored the value of ub - v.begin() + 1 in the vector ans.
    7. Stored the value of x in the vector v.
    8. At last we will return the vector ans.
*/

// Time Complexity: O(nlogn)