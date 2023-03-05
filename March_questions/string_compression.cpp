//Problem: String Compression
//Link: leetcode.com/problems/string-compression/

//Code:
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if (n == 1) {
            return 1;
        }
        int i = 0, j = 0;
        while (i < n) {
            int count = 1;
            while (i < n - 1 && chars[i] == chars[i + 1]) {
                count++;
                i++;
            }
            chars[j++] = chars[i++];
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[j++] = c;
                }
            }
        }
        return j;
    }
};

/* Explanation of the Code:
    1. It takes a vector of characters as an argument and returns an integer.
    2. It first checks the length of the input vector, and if it is 1, it returns 1 as there is no need to compress a single character.
    3. It then uses two variables "i" and "j" to traverse the vector while keeping track of the current index in the original vector "i" and the current index in the compressed vector "j".
    4. It uses a while loop to count the consecutive occurrences of a character in the original vector, and if the count is greater than 1, it converts the count to a string and appends it to the compressed vector.
    5. Finally, it returns the length of the compressed vector, which is equal to the value of "j".
*/

//Time Complexity: O(n)