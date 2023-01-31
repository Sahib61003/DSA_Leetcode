//Problem: Best Team with no Conflicts
//Path: https://www.geeksforgeeks.org/best-team-with-no-conflicts/

//Code:
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<tuple<int,int>> items;
        for (int i = 0; i < size(scores); ++i) items.push_back({scores[i], ages[i]});
        sort(begin(items), end(items));

        map<int,int> res; res[0] = 0;
        for(auto [sc, ag] : items) {
            auto it0 = res.upper_bound(ag);
            int sc2 = sc + (--it0)->second;
            auto it = res.insert(it0, {ag, sc2});
            if (it->second < sc2) it->second = sc2;
            ++it;
            while (it != res.end() && it->second <= sc2) {
                auto it2 = it++;
                res.erase(it2);
            }
        }
        return res.rbegin()->second;
    }
};

/*Explanation of the code:
    1. We have two vectors, one for scores and other for ages. We need to find the best team score.
    2. We create a vector of tuple to store the scores and ages.
    3. We sort the vector of tuple.
    4. We create a map to store the age and score.
    5. We iterate over the vector of tuple.
    6. We create a iterator to store the upper bound of the age.
    7. We calculate the score of the current age.
    8. We insert the age and score in the map.
    9. We check if the score is less than the score of the current age.
    10. If yes, we update the score.
    11. We increment the iterator.
    12. We iterate over the map till the end.
    13. We check if the score is less than or equal to the score of the current age.
    14. If yes, we erase the current iterator.
    15. We return the score of the last element of the map.
*/

//Time Complexity: O(NlogN)

