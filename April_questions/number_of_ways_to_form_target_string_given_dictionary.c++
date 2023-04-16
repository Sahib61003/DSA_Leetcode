//Problem: Number of ways to form a target string given a dictionary
//Link: leetcode.com/number-of-ways-to-form-a-target-string-given-a-dictionary/ 

//Code:
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size();
        int m = target.size();
        int mod = 1000000007;
        vector<int> dp(m+1, 0);
        dp[0] = 1;
        
        vector<vector<int>> count(n, vector<int>(26, 0));
        for (const string& word : words) {
            for (int i = 0; i < n; i++) {
                count[i][word[i] - 'a']++;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = m-1; j >= 0; j--) {
                dp[j+1] += (int)((long)dp[j] * count[i][target[j] - 'a'] % mod);
                dp[j+1] %= mod;
            }
        }
        
        return dp[m];
    }
};

/*Explanation of the Code:
1. We will use dynamic programming to solve this problem.
2. We will use a vector dp of size m+1 to store the number of ways to form a target string of length j using the first i characters of the dictionary.
3. We will use a vector count of size n to store the number of times each character appears in the ith position of the dictionary.
4. We will use a variable mod to store the value of 10^9 + 7.
5. We will initialize the first element of the vector dp to 1.
6. We will iterate over the dictionary and store the number of times each character appears in the ith position of the dictionary in the vector count.
7. We will iterate over the dictionary and for each character in the ith position of the dictionary, we will iterate over the target string from the end and update the number of ways to form a target string of length j using the first i characters of the dictionary.
8. We will return the last element of the vector dp.
*/

//Time Complexity: O(n*m)