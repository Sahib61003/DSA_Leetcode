//Code:
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        // write the code
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};
