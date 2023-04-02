//Problem: Succesful pair of spells and potions
//Link:

//Code:
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> res;
        for (int spell: spells) {
            long potion_needed = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), potion_needed);
            res.push_back(potions.end() - it);
        }
        return res;
    }
};

/*Explanation of the Code:
    1. Sort the potions array.
    2. For each spell, find the potion needed to make the spell successful.
    3. Find the number of potions greater than or equal to the potion needed.
    4. Push the number of potions into the result array.
    5. return the result array.
*/

//Time Complexity: O(nlogn)
