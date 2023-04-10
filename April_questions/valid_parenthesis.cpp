//Problem: Valid Parenthesis
//Link: https://leetcode.com/problems/valid-parentheses/

//Code:
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

/*Explanation of the Code:
    1. We will use stack to solve this problem.
    2. We will iterate over the string and if we encounter an opening bracket, we will push it into the stack.
    3. If we encounter a closing bracket, we will check if the stack is empty or not. If it is empty, we will return false.
    4. If the stack is not empty, we will check if the top of the stack is the opening bracket of the closing bracket we are currently at.
    5. If it is, we will pop the top of the stack.
    6. If it is not, we will return false.
    7. At the end, we will check if the stack is empty or not. If it is empty, we will return true. If it is not, we will return false.
*/

//Time Complexity: O(n)