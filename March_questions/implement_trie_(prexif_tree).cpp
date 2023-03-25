//Problem: Implement Trie (Prefix Tree)
//Link: https://leetcode.com/problems/implement-trie-prefix-tree/

//Code:
class Trie {
public:
unordered_map<string,int>mpp,mp;
    Trie() { 
    }
    void insert(string word) {
        mpp[word]++;
        string s;
        for(auto it : word)
        {
            s.push_back(it);
            if(mp[s]==0) mp[s]++;
        }
    }
    bool search(string word) {
        if(mpp[word]) return true;
        return false;
    }
    bool startsWith(string prefix) {
        if(mp[prefix]) return true;
        return false;
    }
};

/*Explanation of the Code:
    1. We use two hash maps to store the words and prefixes.
    2. We use the first hash map to store the words.
    3. We use the second hash map to store the prefixes.
    4. We insert the word into the first hash map.
    5. We insert the prefix into the second hash map.
    6. We check if the word is present in the first hash map.
    7. We check if the prefix is present in the second hash map.
    8. We return true if the word is present in the first hash map.
    9. We return true if the prefix is present in the second hash map.
    10. We return false if the word is not present in the first hash map.
    11. We return false if the prefix is not present in the second hash map.
*/

//Time Complexity: O(n)