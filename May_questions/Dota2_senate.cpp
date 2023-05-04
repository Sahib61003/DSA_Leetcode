//Problem: Dota2 Senate
//Link: 

//Code:
class Solution {
public:
    string predictPartyVictory(string senate) {
   
        int score = 0; // +ve for R and -ve for D
        for (int i = 0; i < senate.size(); ++i) {
            const char ch = senate[i];
            if (ch == 'R') {
                if (score < 0) 
                    senate.push_back('D');
                
                ++score;
            } else {
                if (score > 0) 
                    senate.push_back('R');
                
                --score;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
 
   }
};

/*Explanation of the Code:
    1. Created a function which takes string senate input.
    2. Created a variable score which will be used to keep track of the score of the teams.
    3. Created a for loop which will iterate through the string senate.
    4. Created a variable ch which will store the character at the index i of the string senate.
    5. If the character is R then we will check if the score is less than 0 then we will push back D in the string senate and increment the score by 1.
    6. If the character is D then we will check if the score is greater than 0 then we will push back R in the string senate and decrement the score by 1.
    7. At last we will return the score if it is greater than 0 then we will return Radiant else we will return Dire.
*/

// Time Complexity: O(n)
