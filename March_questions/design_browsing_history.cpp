//Problem: Design Browsing History
//Link: https://leetcode.com/problems/design-browsing-history/

//Code:
class BrowserHistory {
public:
vector<string>v;
int curr, cnt = 0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        curr = 0;
    }
    void visit(string url) {
        curr++;
        v.resize(curr);
        v.push_back(url); 
    }
    
    string back(int steps) {
        curr = max(0, curr - steps);
        return v[curr];
    }
    
    string forward(int steps) {
        int n = v.size();
        curr = min(n-1, curr+steps);
        return v[curr];
    }
};

/*Explanation of the Code:
    1. We use a vector to store the history of the browser.
    2. We use a variable to store the current index of the vector.
    3. We use a variable to store the number of elements in the vector.
    4. We insert the homepage into the vector.
    5. We insert the url into the vector.
    6. We return the url at the current index of the vector.
*/

//Time Complexity: O(1)