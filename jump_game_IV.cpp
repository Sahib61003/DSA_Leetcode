//Problem: Jump Game IV
//Link: leetcode.com/problems/jump-game-iv/

//Code:
class Solution {
public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size();
    unordered_map<int, vector<int>> graph;
    queue<int> q{{0}};
    vector<bool> seen(n);
    seen[0] = true;
    for (int i = 0; i < n; ++i)
      graph[arr[i]].push_back(i);
    for (int steps = 0; !q.empty(); ++steps) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int i = q.front();
        q.pop();
        if (i == n - 1)
          return steps;
        seen[i] = true;
        const int u = arr[i];
        if (i + 1 < n)
          graph[u].push_back(i + 1);
        if (i - 1 >= 0)
          graph[u].push_back(i - 1);
        for (const int v : graph[u]) {
          if (seen[v])
            continue;
          q.push(v);
        }
        graph[u].clear();
      }
    }
    throw;
  }
};

/*Explanation of the Code:
    1. This code defines a class Solution that has a single public method "minJumps" that takes a vector of integers as an argument and returns an integer.
    2. It initializes a queue with the starting index 0, an unordered map "graph" to represent the graph of the input array, 
       and a vector of booleans "seen" to keep track of visited indices.
    3. It populates the graph by iterating over the input array and adding each element's index to the corresponding key's vector in the map.
    4. It uses a while loop to traverse the graph using breadth-first search.
    5. It uses two nested loops. The outer loop increments the steps taken to reach the current index, 
       while the inner loop processes all the indices in the current level of the graph.
    6. It dequeues the front element of the queue and checks if it is the last index.
       If so, it returns the number of steps taken.
    7. It marks the dequeued index as seen and adds its adjacent indices to the graph.
    8. It iterates over all the indices adjacent to the dequeued index and enqueues them if they have not been seen before.
    9. It clears the dequeued index's vector in the graph.
    10. If the loop completes without finding the last index, it throws an exception.
*/

//Time Complexity: O(n)