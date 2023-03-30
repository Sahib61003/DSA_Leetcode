//Problem: Scramble String
//Link: https://leetcode.com/problems/scramble-string/

//Code:
class Solution {
public:
    unordered_map<string, bool> mp;
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
            return true;
        string key = s1 + "*" + s2;
        if(mp.count(key))
            return mp[key];
        for(int i = 0; i < s1.size() - 1; i++){
            if(isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && 
            isScramble(s1.substr(i + 1), s2.substr(i + 1))){
                return mp[key] = true;
            }    
            if(isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && 
            isScramble(s1. substr(i + 1), s2.substr(0, s2.size() - i - 1))){
                return mp[key] = true;
            } 
        }
        return mp[key] = false;
    }
};

/*Explanation of the Code:  
    1. create a function with parameters s1 and s2.
    2. if s1 is equal to s2 return true.
    3. create a string key and assign it to s1 + "*" + s2.
    4. if mp contains key return mp[key].
    5. create a for loop and run it from 0 to size of s1 - 1.
    6. It checks 2 condition and then return either true or false accordingly.
    7. return mp[key] = false. if no condition in loop matches.
*/

//Time Complexity: O(n^4)