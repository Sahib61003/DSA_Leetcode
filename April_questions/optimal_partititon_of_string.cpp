//Problem: Optimal partition  of Strings
//Link: //https://www.geeksforgeeks.org/optimal-partition-of-strings/

//Code:
class Solution {
public:
    int partitionString(string s) {
        int i = 0, ans = 1,flag = 0;
        while(i < s.size()){
            int val = s[i] - 'a';
            if( flag & (1<<val) ) {
                flag = 0;
                ans++;
            }
            flag = flag | (1<<val);
            i++;
        }
        return ans;
    }
};

/*Explanation of the Code:  
    1. we will pass a variable s in function.
    2. we will take a variable i,flag and initialize it with 0.
    3. we will take a variable ans and initialize it with 1.
    4. we will run a loop till i is less than size of string s.
    5. we will take a variable val and initialize it with s[i] - 'a'.
    6. we will check if flag and (1<<val) is true or not.
    7. if it is true then we will initialize flag with 0 and increment ans by 1.
    8. we will initialize flag with flag or (1<<val).
    9. we will increment i by 1.
    10. we will return ans.
*/

//Time Complexity: O(n)
