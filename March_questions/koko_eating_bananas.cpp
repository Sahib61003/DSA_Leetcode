//Problem: Koko Eating bananas
//Link: https://leetcode.com/problems/koko-eating-bananas/description

//Code:
class Solution {
    int hoursRequired(const vector<int> &piles, int k){
        int h = 0;
        if(k == 0){
            return INT_MAX;
        }
        for(int i : piles){
            if(i % k != 0) {
                h++;
            }
            h += (i / k);
        }
        return h;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        long long sum = 0;
        int mx = 0;
        for(int i = 0; i < piles.size(); i++) {
            sum += piles[i];
            mx = max(mx, piles[i]);
        }
        int l = sum / H, r = mx, ans;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int ans = hoursRequired(piles, mid);
            if(ans > H) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
        }
        return l;
    }
};

/*Explanation of the Code:
    1. Creating a function hoursRequired which will return an integer value.
    2. Creating two parameters piles and k.
    3. Creating a variable h and assigning it to 0.
    4. Creating an if-else statement which will check if k is equal to 0.
    5. If the condition is true then INT_MAX will be returned.
    6. Creating a for loop which will run from 0 to piles.size().
    7. Creating an if-else statement which will check if piles[i] % k is not equal to 0.
    8. If the condition is true then h will be assigned to h + 1.
    9. h will be assigned to h + (piles[i] / k).
    10. Returning h.
    11. h is the number of hours required to eat all bananas.
    12. Creating a function minEatingSpeed which will return an integer value.
    13. Creating two parameters piles and H.
    14. Creating two variables sum and mx and assigning them to 0 and 0 respectively.
    15. Creating a for loop which will run from 0 to piles.size().
    16. sum will be assigned to sum + piles[i].
    17. mx will be assigned to max(mx, piles[i]).
    18. Creating three variables l, r and ans and assigning them to sum / H, mx and 0 respectively.
    19. Creating a while loop which will run until l is less than r.
    20. Creating a variable mid and assigning it to l + (r - l) / 2.
    21. Creating a variable ans and assigning it to hoursRequired(piles, mid).
    22. Creating an if-else statement which will check if ans is greater than H.
    23. If the condition is true then l will be assigned to mid + 1.
    24. Else r will be assigned to mid.
    25. Returning l.
    26. l is the minimum eating speed.
*/

//Time Complexity: O(nlogn)