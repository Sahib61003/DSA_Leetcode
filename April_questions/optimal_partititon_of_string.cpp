//Problem: Optimal partition  of Strings
//Link: //https://www.geeksforgeeks.org/optimal-partition-of-strings/

//Code:
class Solution {
public:
    int partitionString(string s) {
        int i = 0, ans = 1,flag = 0;
        while(i < s.size()){
            int val = s[i] - 'a';
            if( flag & (1<<val) ) {
                flag = 0;
                ans++;
            }
            flag = flag | (1<<val);
            i++;
        }
        return ans;
    }
};


/*Explanation of the Code:

//Time Complexity:
