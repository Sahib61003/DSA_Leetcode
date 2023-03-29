//Problem: Reducing Dishes
//Link: https://leetcode.com/problems/reducing-dishes/

//Code:
class Solution {
public:
    int maxSatisfaction(vector<int>& sat) {
        int n=sat.size();
        sort(sat.begin(),sat.end(),greater<int>());
        vector<int>sum=sat;
        for(int i=1;i<n;i++){
            sum[i]+=sum[i-1];
        }
        int mx=0,cur=0;
        for(int i=0;i<n;i++){
            cur+=sum[i];
            mx=max(cur,mx);
        }
        return mx;
    }
};

/*Explanation of the Code:
    1. create  a function with paramters sat telling satsifaction.
    2. create a variable n and assign it to size of sat.
    3. sort sat in descending order.
    4. create a vector sum and assign it to sat.
    5. create a for loop and run it from 1 to n.
    6. in the for loop add sum[i] to sum[i-1].
    7. create a variable mx and assign it to 0.
    8. create a variable cur and assign it to 0.
    9. create a for loop and run it from 0 to n.
    10. in the for loop add sum[i] to cur.
    11. add max of cur and mx to mx.
    12. return mx.
*/

//Time Complexity: O(nlogn)
