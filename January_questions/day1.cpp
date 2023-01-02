// Problem: Detect Capital
// Link: https://leetcode.com/problems/detect-capital/

//Code:

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(word[i]>='A' && word[i]<='Z')
                count++;
        }
        if(count==n || count==0)
            return true;
        else if(count==1 && word[0]>='A' && word[0]<='Z')
            return true;
        else
            return false;
    }
};

/*  Explanation of code
    first we count the number of capital letters in the string
    if the count is equal to the length of the string or 0 then we return true   
    if the count is 1 and the first letter is capital then we return true
    else we return false
*/

//Time Complexity: O(n)
