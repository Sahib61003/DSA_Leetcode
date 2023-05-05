//Problem: Maximum  Number of vowwel in substring
//Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

//Code:
class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0, counting = 0;
        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0, local = 0; i < s.size(); i++) {
            local += vowel.count(s[i]);
            if (i - k >= 0){
                local -= vowel.count(s[i-k]);
            }
            count = max(count, local);
        }
        return count;
    }
};

/*Explanation of the Code:
    1. Created a function which takes string s and integer k as input.
    2. Created a variable count which will store the maximum number of vowels in a substring of given length.
    3. Created a variable counting which will store the number of vowels in a substring of given length.
    4. Created a unordered_set vowel which will store the vowels.
    5. Created a for loop which will iterate through the string s.
    6. Created a variable local which will store the number of vowels in a substring of given length.
    7. Incremented the local by 1 if the character is present in the vowel set.
    8. If the value of i - k is greater than or equal to 0 then we will decrement the local by 1 if the character is present in the vowel set.
    9. At last we will return the count.
*/

// Time Complexity: O(n)