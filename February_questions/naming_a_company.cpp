//Problem: Naming a company
//Path: https://leetcode.com/discuss/interview-question/1021581/Amazon-or-OA-2021-or-Naming-a-company

//Code:
class Solution
{
    public:
        long long distinctNames(vector<string> &ideas) {
            long long ans = 0;
            unordered_set<string> suffixes[26];
            for (const string &idea : ideas){
                suffixes[idea[0] - 'a'].insert(idea.substr(1));
            }
            for (int i = 0; i < 25; ++i){
                for (int j = i + 1; j < 26; ++j) {
                    int count = 0;
                    for (const string &suffix : suffixes[i]){
                        if (suffixes[j].count(suffix))
                            ++count;
                    }
                    ans += 2 * (suffixes[i].size() - count) * (suffixes[j].size() - count);
                }
            }
            return ans;
        }
};

/*Explanation of the above code:
    1. We will use the greedy approach to solve this problem.
    2. We will iterate over the array and update the value of the array at each index 
       with the maximum value of the index + the value at the index.
    3. We will then iterate over the array again and find the index which is the maximum value of the index 
       + the value at the index.
    4. We will then update the index to the value of the index which we found in the previous step.
    5. We will repeat the above steps until we reach the last index of the array.
    6. We will return the number of steps taken to reach the last index of the array.
*/

// Time Complexity: O(n)