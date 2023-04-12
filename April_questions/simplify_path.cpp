//Problem: Simplify Path
//Link: https://leetcode.com/problems/simplify-path/

//Code:
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        stringstream ss(path);
        string dir;
        while (getline(ss, dir, '/')) {
            if (dir.empty() || dir == ".") {
                continue;
            } else if (dir == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(dir);
            }
        }
        string res;
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res.empty() ? "/" : res;
    }
};

/*Explanation of the Code:  
    1. We use a stack to store the directories.
    2. We use stringstream to split the string by '/'.
    3. We use getline() to get the string between '/'.
    4. If the string is empty or '.', we do nothing.
    5. If the string is '..', we pop the stack.
    6. If the string is a directory, we push it into the stack.
    7. We use a string to store the result.
    8. We pop the stack and add the string to the result.
    9. We return the result.
*/

// Time Complexity: O(n)