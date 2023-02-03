//Problem: Zigzag Conversion
//Path: https://leetcode.com/problems/zigzag-conversion/


//Code:
class Solution {
public:
    string convert(string s, int numRows) {    
    if(numRows <= 1) return s;
    vector<string>v(numRows, ""); 
    int j = 0, dir = -1;
    for(int i = 0; i < s.length(); i++)
    {
        if(j == numRows - 1 || j == 0) dir *= (-1); 		 
        v[j] += s[i];
        if(dir == 1) j++;
        else j--;
    }
    string res;
    for(auto &it : v) res += it; 
    return res;
    }
};


/* Explanationn of the above code:
    1. We will be using a vector of strings to store the characters of the string s in the zigzag pattern.
    2. We will be using a variable j to keep track of the row number and a variable dir to keep track of the direction.
    3. We will be traversing the string s from left to right and for each character.
    4. we will be adding it to the string at the jth row of the vector.
    5. If j is equal to the number of rows or 0, we will change the direction of traversal.
    6. We will be traversing the vector of strings and adding all the strings to a single string and returning it.
*/

//Time Complexity: O(n)