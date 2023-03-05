//Problem: Find Index of First Occurrence of String
//Link: leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

//Code:
class Solution {
public:
    int strStr(string ha, string needle) {
        if(ha.find(needle) == string :: npos){
            return -1;
        }
        int n = ha.size() , m = needle.size() ;
        for(int i = 0 ; i < n - m + 1 ; i++ ){
            if(needle == ha.substr(i,m) ){
                return i;
            }
        }
        return -1;
    }
};

/*Explanation of the Code:
    1. It takes two strings as arguments and returns an integer.
    2. It first checks if the second string is a substring of the first string, and if it is not, it returns -1.
    3. It then uses two variables "n" and "m" to store the lengths of the two strings.
    4. It then uses a for loop to traverse the first string and check if the substring of the first string starting at the current index and of length equal to the length of the second string is equal to the second string.
    5. If it is, it returns the current index.
    6. If it is not, it continues to traverse the first string.
    7. If the second string is not a substring of the first string, it returns -1.
*/

// Time Complexity: O(n)