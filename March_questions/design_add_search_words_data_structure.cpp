//Problem: Design Add and Search Words Data Structure
//Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/

//Code:
class WordDictionary {
public:
    vector<string> v;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        v.push_back(word);
    }
    
    bool search(string word) {
        int count=0;
        int n=word.size();
        for(int i=0; i<v.size(); i++){
            if(n==v[i].size()){
                for(int j=0; j<n; j++){
                    if(v[i][j]==word[j]||word[j]=='.'){
                        count++;
                    }
                    else{
                        count=0;
                        break;
                    }
                }
                if(count==n) return true;
            }
        }
        return false;
    }
};

/*Explanation of the Code:
    1. We use a vector to store the words.
    2. We insert the word into the vector.
    3. We use a variable to store the number of characters in the word.
    4. We use a variable to store the number of characters that match.
    5. We iterate over the vector.
    6. We check if the size of the word is equal to the size of the word in the vector.
    7. We iterate over the word.
    8. We check if the character in the word is equal to the character in the word in the vector or if the character in the word is a '.'.
    9. If the character in the word is equal to the character in the word in the vector or if the character in the word is a '.', we increment the count variable.
    10. If the count variable is equal to the number of characters in the word, we return true.
    11. If the count variable is not equal to the number of characters in the word, we return false.
*/

//Time Complexity: O(n*m)