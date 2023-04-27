//Problem: Add Digit
//Link: https://leetcode.com/problems/add-digits/

//Code:
class Solution {
public:
    int addDigits(int num) {
        if(num == 0){
            return 0;
        } else if(num % 9 == 0){
            return 9;
        }
        else {
             return num % 9;
        }
    }
};

//Time Complexity: O(logN)



