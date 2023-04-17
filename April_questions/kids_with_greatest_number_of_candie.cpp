//Problem: Kids with greatest number of Candies
//Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

//Code:
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& cd, int ex) {
        int mx =0;
        vector<bool> ans;
        for(int a : cd ) mx =max(mx,a);
        for(int a : cd){
            if(a+ex >= mx) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. We will find the maximum number of candies in the vector.
    2. We will iterate through the vector and check if the candies + extra candies >= maximum candies.
    3. If yes, we will push true in the vector else false.
    4. We will return the vector.
*/

//Time Complexity: O(n)