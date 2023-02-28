//Problem: IPO
//Link: https://leetcode.com/problems/ipo/

//Code:

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>>mxh;
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>>mnh;
        for(int i=0;i<capital.size();++i){
            mnh.push({capital[i], profits[i]});
        }   
        while(k > 0){
           while(!mnh.empty() && mnh.top().first<=w){
               auto p = mnh.top();
               mnh.pop();
               mxh.push({p.second, p.first});
           }
           if(!mxh.empty()) {
               w += mxh.top().first;
               mxh.pop();
               k--;
           }
           else break;  
        }
        return w;
    }
};


/*Explanation of the above code:
1. We will use a max heap to store the profits and a min heap to store the capital.
2. We will use a for loop to traverse the capital and profits vector.
3. We will use a while loop to traverse the min heap.
4. We will use a if condition to check if the capital is less than or equal to the current capital.
5. If it is then we will push the profit and capital in the max heap.
6. We will use a while loop to traverse the max heap.
7. We will use a if condition to check if the number of projects is greater than 0.
8. If it is then we will add the profit to the current capital and decrease the number of projects by 1.
9. We will return the current capital.
*/

//Time Complexity: O(nlogn)

*/