// Problem: Lexicographicaaly Smallest Equivalent String 
// Path: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/ 

//Code:

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char map[26];
        for(int i=0;i<26;i++){
            map[i] = i+'a';
        }
        for(int i=0;i<s1.size();i++){
            char replace = max(map[s1[i] - 'a'],map[s2[i] - 'a']); //Bigger element
            char put = min(map[s1[i] - 'a'],map[s2[i] - 'a']); // Smaller element
            for(int i=0;i<26;i++){
                if(map[i] == replace)
                    map[i] = put;   // Replace all the bigger characters with it's smallest equivalent
            }
        }

        string ans = "";
        for(int i=0;i<baseStr.size();i++){
            ans += map[baseStr[i] - 'a'];
        }
        return ans;
    }
};

/*Explanation of the code:
    1. We will create a map of 26 characters and initialize it with the characters itself.
    2. We will iterate through the s1 and s2 and find the smallest equivalent character for each character in s1 and s2.
    3. We will replace all the bigger characters with the smallest equivalent character.
    4. We will iterate through the baseStr and replace each character with it's smallest equivalent character.
    5. We will return the string.
*/

//Time Complexity: o(n)
