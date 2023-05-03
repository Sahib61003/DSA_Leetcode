//Problem: Find difference of two arrays
//Link: https://leetcode.com/problems/find-the-difference/

//Code:
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
};

/*Explanation of the Code:  
    1. We will iterate over the vector nums1 and insert all the elements in the set set1.
    2. We will iterate over the vector nums2 and insert all the elements in the set set2.
    3. We will iterate over the set set1 and check if the element is present in the set set2.
    If it is not present, we will push it in the vector distinct_nums1.
    4. We will iterate over the set set2 and check if the element is present in the set set1. 
    If it is not present, we will push it in the vector distinct_nums2.
    5. We will return the vector of vectors {distinct_nums1, distinct_nums2}.
*/

// Time Complexity: O(n)

