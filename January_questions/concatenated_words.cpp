//Problem: Concatenated Words
//Path: https://leetcode.com/problems/concatenated-words

//Code:
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> words_set;
        for (string word : words) words_set.insert(word);
        vector<string> res;
    
        for (string word : words) {
            int n = word.size();
            vector<int> dp(n + 1, 0);
            dp[0] = 1;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int j = i + 1; j <= n; j++) {
                    if (j - i < n && words_set.count(word.substr(i, j - i))) {
                        dp[j] = 1;
                    }
                }
                if (dp[n]) {
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};

/* Explanation of the code:
    1. We are using unordered_set to store the words in the dictionary.
    2. We are using a vector to store the result.
    3. We are iterating over the words in the dictionary.
    4. We are storing the size of the word in a variable n.
    5. We are creating a vector of size n+1 and initializing all the elements to 0.
    6. We are setting the first element of the vector to 1.
    7. We are iterating over the word.
    8. If the element is 0, we are continuing the loop.
    9. We are iterating over the word from i+1 to n.
    10. If the word is present in the dictionary, we are setting the element at jth position to 1.
    11. If the last element of the vector is 1, we are pushing the word into the result vector.
    12. We are returning the result vector.
*/

//Time Complexity: O(n^2)
