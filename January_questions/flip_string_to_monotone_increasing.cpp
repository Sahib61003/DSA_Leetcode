// Problem: Flip String to Monotone Increasing
// Path: https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int func(int idx,string&s,char ch,vector<vector<int>>&dp){
        int n=s.size();
        if(idx>=n){
            return 0;
        }
        if(dp[idx][ch-'0']!=-1){
            return dp[idx][ch-'0'];
        }
        int res1=1e9,res2=1e9;
        if(ch=='0'){
            if(s[idx]=='0'){
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
                res2=func(idx+1,s,'0',dp)+1;
            }
        }
        else{
            if(s[idx]=='0'){
                res1=func(idx+1,s,'1',dp)+1;
            }
            else{
                res1=func(idx+1,s,s[idx],dp);
            }
        }
        return dp[idx][ch-'0']=min(res1,res2);
    }
    int minFlipsMonoIncr(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(2,-1));

        int ans=func(0,s,'0',dp);
        return ans;
        
    }
};

/* Explanation of Code:
    1. We have to find the minimum number of flips required to make the string monotone increasing.
    2. We can do this by using dp.
    3. We will have two states, the index and the character we are currently at.
    4. If the character is 0, we can either flip it to 1 or not flip it.
    5. If the character is 1, we can either flip it to 0 or not flip it.
    6. We will return the minimum of the two cases.
    7. We will also store the result in dp to avoid recomputation.
    8. We will return the answer when we reach the end of the string.
*/

//Time Complexity : O(n)