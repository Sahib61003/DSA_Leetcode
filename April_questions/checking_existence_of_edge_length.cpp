//Problem: Checking existence of edge length
//Link: https://leetcode.com/problems/checking-existence-of-edge-length-limited-paths/

//Code:
 class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    bool connected(int i, int j) { return find(i) == find(j); }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) {
        vector<bool> ans(Q.size());
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [&](auto &a, auto &b) { return a[2] < b[2]; });
        sort(begin(E), end(E), [&](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int i = 0;
        for (auto &q : Q) { 
            int u = q[0], v = q[1], limit = q[2], qid = q[3];
            for (; i < E.size() && E[i][2] < limit; ++i) uf.connect(E[i][0], E[i][1]); 
            ans[qid] = uf.connected(u, v);
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. We will use Union Find to solve this problem.
    2. We will sort the queries and edges in increasing order of their limit.
    3. We will iterate over the queries and edges and if the edge is less than the limit, we will connect the two nodes.
    4. Finally, we will return the answer.
*/

//Time Complexity: O(NlogN + QlogQ + ElogE + QlogE)
