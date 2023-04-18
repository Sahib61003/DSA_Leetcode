//Problem: Merge Strings Alternatively
//URL: https://leetcode.com/problems/merge-strings-alternatively/

//Code:
class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string s;
        int i=0;
        while( i<w1.size() && i<w2.size()){
            s.push_back(w1[i]);
            s.push_back(w2[i]);
            i++;
        }
        if(i==w1.size()){
            for(int j = i;j<w2.size();j++) s.push_back(w2[j]);
        }
        else if(i==w2.size()){
            for(int j = i;j<w1.size();j++) s.push_back(w1[j]);
        }
        return s;
    }
};

/*Explanation of the Code:
    1. We have created a function which is taking two strings w1 and w2 and then we initialise string s.
    2. Then we have created a while loop which will run until i is less than the size of w1 and w2.
    3. Then we have created a if-else condition which will check if i is equal to the size of w1 then it will push the characters of w2 in s.
    4. Else if i is equal to the size of w2 then it will push the characters of w1 in s.    
    5. Then we have returned the string s.
*/

//Time Complexity: O(n)
