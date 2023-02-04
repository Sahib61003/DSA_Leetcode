//Problem: Permutation in String
//Path: https://leetcode.com/problems/permutation-in-string/


//Code:
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        for(int i = 0; i < s1.size(); i++)
            count1[s1[i] - 'a']++;
    
        for(int i = 0; i < s2.size(); i++){
            bool flag = true;
            string str = s2.substr(i, s1.size());         
            int count2[26] = {0};

            for(int j = 0; j < str.size(); j++)
                count2[str[j] - 'a']++;         

            for(int idx = 0; idx < 26; idx++){
                if(count1[idx] != count2[idx]){
                    flag = false;
                    break;
                }
            }    
            if(flag) return true;         
        }
        return false;
    }
};


/*Explanation of the code:
1. We will take out substring of size s1 from s2 and check if it is permutation of s1 or not.
2. We will store the letters occurance places in s1 and substring of s2.
3. If all the letters ocuurences are same in substring and s1 then it means there is permutation.
4. If we got true at any point of time return true.    
*/

//Time Complexity: O(n^2)