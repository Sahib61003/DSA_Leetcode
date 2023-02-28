//Problem: Shortest Path with Alternating Colors
//Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/

//Code:
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, int>> adj[n];
        for(auto it : redEdges) {
            adj[it[0]].push_back({it[1], 1});
        }
        for(auto it : blueEdges) {
            adj[it[0]].push_back({it[1], 2});
        }
        vector<vector<int>> dist(n, vector<int> (3, 1e9));
        queue<pair<int, int>> q;
        q.push({0, 0});
        dist[0][0] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int prev_color = q.front().second;
            q.pop();
            for(auto it : adj[node]) {
                int adj_node = it.first;
                int color = it.second;
                if(color == prev_color) continue;
                if(dist[adj_node][color] == 1e9)
                {
                    dist[adj_node][color] = dist[node][prev_color] + 1;
                    q.push({adj_node, color});
                }
            }
        } 
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++){
            ans[i] = min(dist[i][1], dist[i][2]);
            if(ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        return ans;
    }
};

/*Explanation of the code:
1. We will use a vector of pairs to store the adjacent nodes and the color.
2. We will use a for loop to traverse the red edges and blue edges.
3. We will use a if condition to check if the color is red.
4. If it is then we will push the adjacent node and the color in the vector of pairs.
5. We will use a if condition to check if the color is blue.
6. If it is then we will push the adjacent node and the color in the vector of pairs.
7. We will use a vector of vectors to store the distance.
8. We will use a queue to store the node and the color.
9. We will push the source node and the color in the queue.
10. We will use a while loop to traverse the queue.
11. We will use a for loop to traverse the adjacent nodes.
12. We will use a if condition to check if the color is same as the previous color.
13. If it is then we will continue.
14. We will use a if condition to check if the distance is equal to 1e9.
15. If it is then we will update the distance.
16. We will push the adjacent node and the color in the queue.
17. We will use a vector to store the final answer.
18. We will use a for loop to traverse the distance vector.
19. We will use a if condition to check if the distance is equal to 1e9.
20. If it is then we will push -1 in the vector.
21. If it is not then we will push the minimum distance in the vector.
22. We will return the vector.
*/

// Time Complexity: O(n)
