//Problem: Cheapest Flight With K Stops
//Path: https://leetcode.com/problems/cheapest-flight-with-k-stops/

//Code:
class Solution { 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        unordered_map<int, vector<pair<int, int>>> graph;
        for(auto e: flights) graph[e[0]].push_back({e[1], e[2]});
        vector<int> prices(n, -1);
        queue<pair<int, int>> q; q.push({src, 0});
        ++K;
        while(!q.empty()) {
            if(!K) break;
            int len = q.size();
            for(int i = 0; i < len; i++) {
                auto cur = q.front(); q.pop();
                for(auto e: graph[cur.first]) {
                    int price = cur.second + e.second; 
                    if(prices[e.first] == -1 || price < prices[e.first]) {
                        prices[e.first] = price;
                        q.push({e.first, price});
                    }
                }
            }
            K--;
        }
        return prices[dst];
    }
};

/*Explanation of the above Code:
    1. Function named findcheapestprice is created
    2. It takes 5 parameters: n, flights, src, dst, K
    3. The first line creates a map named graph
    4. The second line creates a vector named prices
    5. The third line creates a queue named q
    6. The fourth line increments K by 1
    7. While loop is initiated till the queue is not empty
    8. If K is not 0, then the length of the queue is stored in len
    9. For loop is initiated till len
    10. The first element of the queue is stored in cur
    11. The first element of the queue is popped
    12. For loop is initiated till graph[cur.first]
    13. The price is calculated by adding cur.second and e.second
    14. If prices[e.first] is -1 or price is less than prices[e.first], then prices[e.first] is assigned price
    15. The pair of e.first and price is pushed into the queue
    16. K is decremented by 1
    17. The prices[dst] is returned
*/

// Time Complexity: O(n^2)
