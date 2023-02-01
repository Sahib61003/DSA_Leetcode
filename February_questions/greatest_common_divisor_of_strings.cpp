//Problem: Greatest Common Divisor of Strings 
//Path: https://leetcode.com/problems/greatest-common-divisor-of-strings/

//Code:
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            return "";
        int n1=str1.length();
        int n2=str2.length();
        int n=min(n1,n2);
        for(int i=n;i>=1;i--)
        {
            if(n1%i==0 && n2%i==0)
            {
                string s=str1.substr(0,i);
                string s1="";
                string s2="";
                for(int j=0;j<n1/i;j++)
                    s1+=s;
                for(int j=0;j<n2/i;j++)
                    s2+=s;
                if(s1==str1 && s2==str2)
                    return s;
            }
        }
        return "";       
    }
};

/*Explanation of Code:
1. If str1+str2!=str2+str1, then there is no common divisor. Return "".
2. If str1+str2==str2+str1, then there is a common divisor. Find the length of the common divisor.
3. The length of the common divisor must be a divisor of both str1 and str2. Find the largest common divisor.
4. Return the common divisor.
*/

// Time Complexity: O(n^2)
