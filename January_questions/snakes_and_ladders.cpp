//Problem: Snakes and Ladders
//Path: https://leetcode.com/problems/snakes-and-ladders/

//Code:

class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};

/*Explanation of the code:
    1. This code is a class for solving the problem of finding the minimum number of moves 
        to reach the last cell on a board with snakes and ladders.
    2. It uses BFS algorithm to find the solution by storing the distance of each cell from the starting point in a queue. 
    3. The code initializes a grid of cells with their respective labels and coordinates, 
        and uses two loops to iterate through the cells with a specific order. 
    4. The grid of distances is initialized with -1, and the starting cell is given distance 0. 
    5. The queue is initialized with the starting cell, and the BFS algorithm is applied to 
        find the minimum number of moves to reach the last cell.
*/

//Time Complexity:  O(n^2)
