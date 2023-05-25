//Problem: Top K Frequenecy Elements
//Link: https://leetcode.com/problems/top-k-frequent-elements/

//Code:
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> Res;
       
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> m;
        for( auto i : mp)
        {
            m.push(make_pair( i.second, i.first));
        }
        
        for( int i =0;i<k ; i++)
        {
            Res.push_back( m.top().second);
            m.pop();
        }
      
        return Res;
    }
};

/*Explanation of the Code:
    1. Creating a variable n which store size of nums.
    2. Creating a unordered_map mp.
    3. Creating a vector Res.
    4. Creating a loop from 0 to n.
    5. Incrementing the value of mp[nums[i]].
    6. Creating a priority_queue m.
    7. Creating a loop for auto i : mp.
    8. Pushing the value of i.second and i.first in m.
    9. Creating a loop from 0 to k.
    10. Pushing the value of m.top().second in Res.
    11. Poping the value of m.
    12. Return Res.
*/

//Time Complexity: O(nlogk)
