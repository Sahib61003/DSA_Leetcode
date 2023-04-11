//Problem: Remove Stars from a String
//Link: https://leetcode.com/problems/removing-stars-from-a-string

//Code:

class Solution {
public:
    string removeStars(string s) {
        string c="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                c.pop_back();
            }else{
                c+=s[i];
            }
            
        }
        return c;
    }
};

/*Explanation of the Code:
    1. We will use a string c to store the final string.
    2. We will iterate over the string s.
    3. If the character is a star, we will pop the last character from the string c.
    4. If the character is not a star, we will append it to the string c.
    5. Finally, we will return the string c.
*/

//Time Complexity: O(n)