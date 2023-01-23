//Problem: Find the down Judge
//Path: https://leetcode.com/problems/find-the-town-judge/

//Code:
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n+1, 0);
        for (auto& t : trust) {
            trust_count[t[0]]--;
            trust_count[t[1]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (trust_count[i] == n - 1) {
                return i;
            }
        }
        return -1;        
    }
};

/*Explanation of Code:
    1. We create a vector of size n+1 and initialize it with 0.
    2. We iterate through the trust vector and decrement the value at trust[i][0] and increment the value at trust[i][1].
    3. We iterate through the trust_count vector and check if the value at trust_count[i] is equal to n-1. If it is, we return i.
    4. If we don't find any such value, we return -1.
*/

//Time Complexity: O(N)