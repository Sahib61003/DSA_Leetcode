//Problem: Fruit into Basket
//Path: https://leetcode.com/problems/fruit-into-baskets/

//Code:
class Solution {
public:
   int totalFruit(vector<int>& fruits) {
       int n = fruits.size() ,ans=0 ,i=0, j=0;     
       unordered_map<int,int>mp;     
       while(j<n){
           mp[fruits[j]]++;
           while(mp.size()>2){
               mp[fruits[i]]--;
               if(mp[fruits[i]]==0) mp.erase(fruits[i]);
               i++;
           }
           ans = max(ans,j-i+1);
           j++;
       }
       return ans;
   }
};

/*Explanation of the above code:
    1. We will use two pointers i and j to traverse the array.
    2. We will use a map to store the frequency of the elements.
    3. We will traverse the array using j and keep on adding the elements to the map.
    4. If the size of the map becomes greater than 2, we will start removing the elements from the map using i.
    5. We will keep on updating the answer with the maximum of the previous answer and the current answer.
    6. We will return the answer.
*/

//Time Complexity: O(n)
