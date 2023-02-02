//Problem: An Alien Dictionary
//Link: https://leetcode.com/problems/alien-dictionary/

//Code:
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mp;
        bool res=true;
        for(int i=0;i<order.size();i++)mp[order[i]]=i;
        for(int i=0;i<words.size()-1;i++){
            for(int j=0;j<words[i].size();j++){
                if (j >= words[i + 1].length()) return false;
                 if(mp[words[i][j]]>mp[words[i+1][j]])return false;
                 else if(mp[words[i][j]]<mp[words[i+1][j]]){
                     break;
                 }
                 
            }
            
        }
        return true;
    }
};

/* Explaantion of Code:
    1. We will use map to store the order of the characters.
    2. We will iterate over the words and check if the current word is greater than the next word.
    3. If the current word is greater than the next word, we will return false.
    4. If the current word is smaller than the next word, we will break the loop and move to the next word.
    5. If the current word is equal to the next word, we will continue the loop.
    6. If we reach the end of the loop, we will return true.
*/

//Time Complexity: O(n)
