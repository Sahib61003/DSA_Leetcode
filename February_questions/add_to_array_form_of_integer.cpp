//Problem:  Add to Array-Form of Integer
//Link: //https://leetcode.com/problems/add-to-array-form-of-integer/

//Code:
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n = num.size();
        int carry = 0, i = n-1;
        while (k > 0 || i >= 0 || carry > 0) {
            int sum = carry;
            if (k > 0) {
                int remainder = k % 10;
                sum += remainder;
                k = k / 10;
            }
            if (i >= 0) {
                sum += num[i];
                i--;
            }
            carry = sum / 10;
            ans.push_back(sum % 10);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*Explanation of the above code:
    1. We will use a vector to store the answer.
    2. We will use a variable n to store the size of the vector num.
    3. We will use a variable carry to store the carry.
    4. We will use a variable i to store the index of the last element of the vector num.
    5. We will use a while loop to iterate over the vector num and the variable k.
    6. We will use a variable sum to store the sum of the carry and the last digit of the variable k.
    7. We will use an if statement to check if the variable k is greater than 0.
    8. If the variable k is greater than 0, we will use a variable remainder to store the last digit of the variable k.
    9. We will add the variable remainder to the variable sum.
    10. We will divide the variable k by 10.
    11. We will use an if statement to check if the variable i is greater than or equal to 0.
    12. If the variable i is greater than or equal to 0, we will add the element at the index i of the vector num to the variable sum.
    13. We will decrement the variable i.
    14. We will divide the variable sum by 10 and store the quotient in the variable carry.
    15. We will push the remainder of the variable sum divided by 10 to the vector ans.
    16. We will reverse the vector ans and return it.
*/

//Time Complexity: O(n)