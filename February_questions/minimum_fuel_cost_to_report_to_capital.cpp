//Problem: Minimum Fuel Cost to Report to Capital
//Link: https://leetcode.com/discuss/interview-question/356150/

//Code:
class Solution {
public:
    long long fuel;
    long long dfs(int node, int parent, vector<vector<int>>& adj, int& seats) { 
        int representatives = 1;                                                        // The node itself has one representative.
        for (auto& child : adj[node]) {
            if (child != parent) {
                representatives += dfs(child, node, adj, seats);                      // Add count of representatives in each child subtree to the parent subtree.
            }
        }
        if (node != 0) {
            fuel += ceil((double)representatives / seats);                           // Count the fuel it takes to move to the parent node.
                                                                                     // Root node does not have any parent so we ignore it.
        }
        return representatives;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        vector<vector<int>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].push_back(road[1]);
            adj[road[1]].push_back(road[0]);
        }
        dfs(0, -1, adj, seats);
        return fuel;
    }
};

/*Explanation of the above code:
    1. We will use a dfs function to traverse the tree.
    2. We will use a representatives variable to store the number of representatives.
    3. We will use a for loop to traverse the adj list.
    4. We will use a if condition to check if the child is not equal to the parent.
    5. If it is not then we will update the representatives to the representatives plus the dfs function call.
    6. We will use a if condition to check if the node is not equal to 0.
    7. If it is not then we will update the fuel to the fuel plus the ceil function call.
    8. We will return the representatives.
    9. We will use a minimumFuelCost function to return the minimum fuel cost.
    10. We will use a dfs function call to traverse the tree.
    11. We will return the fuel.
*/

// Time Complexity: O(n)