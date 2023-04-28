//Problem: Similar String Groups
//Link: https://leetcode.com/problems/similar-string-groups/


//Code:
class Solution {
public:
    bool isSimilar(string& a, string &b) {
        int cnt = 0;
        for(int i=0; i<a.length(); i++)
            if(a[i] != b[i])    cnt++;
        return cnt <= 2;
    }
    void dfs(vector<string>& strs, int ind, vector<bool> &vis) {
        vis[ind] = true;
        for(int i=0; i<strs.size(); i++)  {
            if(isSimilar(strs[ind], strs[i]) && !vis[i])
            dfs(strs, i, vis);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int ans = 0;
        vector<bool> vis(strs.size(), false);

        for(int i=0; i<strs.size(); i++){
            if(!vis[i]) {
                ans++;
                dfs(strs, i, vis);
            }
        }
        return ans;
    }
};


/*Explanation of the Code:
    1. We will use DFS to find the number of connected components in the graph.
    2. We will use a function isSimilar to check if two strings are similar or not.
    3. We will use a vector vis to keep track of the visited nodes.
    4. We will iterate over the vector of strings and if the string is not visited, we will increment the answer and call the dfs function.
    5. In the dfs function, we will mark the current node as visited and iterate over the vector of strings and if the string is not visited and is similar to the current string, we will call the dfs function.
    6. Finally, we will return the answer.
*/

//Time Complexity: O(N^2 * L)
