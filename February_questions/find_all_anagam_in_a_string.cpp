//Problem: Find All Anagrams in a String
//Path: https://leetcode.com/problems/find-all-anagrams-in-a-string/

//Code:
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>hash1(26,0),hash2(26,0);
        int n=p.size(),m=s.size();
        for(int i=0;i<n;i++){
            hash1[p[i]-'a']++;
        }
       
        int i=0,j=0,c=0;
        vector<int>ans;
        while(i<m){
            hash2[s[i]-'a']++;
            if(i>=n) hash2[s[j++]-'a']--;
            if(hash1==hash2)ans.push_back(i-n+1);
            i++;
        }
        return ans;
    }
};

/*Explanation of the code:
    1. initialising two vectors hash1 and hash2 of size 26 and initialising them with 0.
    2. initialising two variables n and m with the size of the strings p and s respectively.
    3. for loop to iterate through the string p and incrementing the hash1 vector.
    4. initialising two variables i and j with 0 and initialising a variable c with 0.
    5. initialising a vector integer ans.
    6. while loop to iterate through the string s.
    7. incrementing the hash2 vector.
    8. if condition to check if i is greater than or equal to n.
    9. decrementing the hash2 vector.
    10. if condition to check if hash1 is equal to hash2.
    11. pushing the value of i-n+1 in the ans vector.
    12. incrementing i.
    13. returning the ans vector.    
*/

//Time Complexity: O(n)