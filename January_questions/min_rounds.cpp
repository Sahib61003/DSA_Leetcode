//Problem: Minimum Rounds to Complete All Tasks
//Source: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

//Code:
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int output=0;
        for (auto freq : mp){
            if(freq.second==1)
                return -1;
            if(freq.second%3==0){
                output += freq.second/3;
            }
            else{
                output += freq.second/3 + 1;
            }
        }
        return output;
    }
};

/* Explanation of the above code
    Create a unordered map to store the frequency of each task.
    Iterate through the map and check if the frequency is 1. If yes, return -1.
    If the frequency is not 1, check if the frequency is divisible by 3. If yes, add the frequency/3 to the output.
    If the frequency is not divisible by 3, add the frequency/3 + 1 to the output.
    Return the output.
*/
// Time Complexity : O(n)