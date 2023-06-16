//Problem: Minimum Flips to Make a OR b Equal to c
//Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

//Code:
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
        while(a||b||c){
            int x1=a&1;
            int x2=b&1;
            int x3=c&1;
            if((x1|x2)!=x3){
                if(x1&x2){
                    ans+=2;
                }
                else {
                    ans+=1;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. We have created a class Solution.
    2. We have created a function minFlips.
    3. We have created a variable ans to store the answer.
    4. We have created a while loop to iterate till a or b or c is not equal to 0.
    5. We have created a variable x1 to store the value of a&1.
    6. We have created a variable x2 to store the value of b&1.
    7. We have created a variable x3 to store the value of c&1.
    8. We have created a if statement to check if (x1|x2)!=x3.
    9. We have created a if statement to check if x1&x2 is true.
    10. We have updated the value of ans by 2.
    11. We have created a else statement.
    12. We have updated the value of ans by 1.
    13. We have updated the value of a by a>>1.
    14. We have updated the value of b by b>>1.
    15. We have updated the value of c by c>>1.
    16. We have returned ans.
*/

// Time Complexity: O(n)
