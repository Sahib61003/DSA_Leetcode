//Problem: Add Binary
//Path: https://leetcode.com/problems/add-binary/

//Code:
class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.size()-1;
        int j=b.size()-1;
        int carry=0;
        string res="";
        for(int i = b.size()-1; i >= 0 ; --i){
             if(b[i] == '1' && a[i]=='1'){
                if(carry == 0) res = "0" + res;
                else res = "1" + res;      
                carry = 1;
             }
             else if(b[i] =='0' && a[i] =='0'){
                if(carry == 0) res = "0" + res;   
                else
                {
                    res = "1" + res;
                    carry = 0;
                }
             }
             else if((b[i]=='0' && a[i]=='1') || (b[i]=='1' && a[i] == '0')){
                if(carry == 0) res = "1" + res;
                else res = "0" + res;
            }
        }
        if(carry == 1) res = "1" + res;
        return res;
    }
};

/*Explanation of the code:
    1. We will use two pointers to iterate over the strings.
    2. We will iterate over the strings from the end.
    3. We will add the characters at the current position of the two strings.
    4. If the sum is 0, we will add 0 to the result string.
    5. If the sum is 1, we will add 1 to the result string.
    6. If the sum is 2, we will add 0 to the result string and carry 1 to the next position.
    7. If the sum is 3, we will add 1 to the result string and carry 1 to the next position.
    8. If we reach the end of the loop, we will check if there is any carry left.
    9. If there is any carry left, we will add 1 to the result string.
    10. We will return the result string.
*/

//Time Complexity: O(n)
