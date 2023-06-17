//Problem: Make array strictly increasing
//Link: https://leetcode.com/problems/make-array-strictly-increasing
 
//Code:
class Solution {
public: 
    int solve(int i,int j,int &a,int &b,int p,vector<vector<int>> &dp,vector<int> &v1,vector<int> &v2){
        if(i==a){
            return 0;
            j = upper_bound(v2.begin()+j,v2.end(),p)-v2.begin();
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(j==b && v1[i]<=p){
            return 2001;
            int take = 2001,nottake = 2001;
        }
        if(j!=b){
            take = solve(i+1,j+1,a,b,v2[j],dp,v1,v2)+1;
        }
        if(v1[i]>p) {
            nottake = solve(i+1,j,a,b,v1[i],dp,v1,v2);
            return dp[i][j] = min(take,nottake);
        }
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m=arr2.size();
        vector<vector<int>> dp(2001,vector<int>(2001,-1));
        sort(arr2.begin(),arr2.end());
        int a= solve(0,0,n,m,-1,dp,arr1,arr2);
        if(a>n) {
            return -1;
        }
        return a;
    }
};

/*Explanation of the Code:
    1. We have created a class Solution.
    2. We have created a function solve.
    3. We have created a variable take to store the value of the minimum number of operations if we take the element.
    4. We have created a variable nottake to store the value of the minimum number of operations if we do not take the element.
    5. We have created a if statement to check if i is equal to a.
    6. We have returned 0.
    7. We have updated the value of j to the upper bound of v2.begin()+j and v2.end() and p-v2.begin().
    8. We have created a if statement to check if dp[i][j] is not equal to -1.
    9. We have returned dp[i][j].
    10. We have created a if statement to check if j is equal to b and v1[i] is less than or equal to p.
    11. We have returned 2001.
    12. We have created a if statement to check if j is not equal to b.
    13. We have updated the value of take to solve(i+1,j+1,a,b,v2[j],dp,v1,v2)+1.
    14. We have created a if statement to check if v1[i] is greater than p.
    15. We have updated the value of nottake to solve(i+1,j,a,b,v1[i],dp,v1,v2).
    16. We have returned dp[i][j] to the minimum of take and nottake.
    17. We have created a function makeArrayIncreasing.
    18. We have created a variable n to store the size of arr1.
    19. We have created a variable m to store the size of arr2.
    20. We have created a vector dp of size 2001*2001 and initialized it with -1.
    21. We have sorted the vector arr2.
    22. We have created a variable a to store the value of solve(0,0,n,m,-1,dp,arr1,arr2).
    23. We have created a if statement to check if a is greater than n.
    24. We have returned -1.
    25. We have returned a.
*/

// Time Complexity: O(n^2)
