//Problem: Boats to Save People
//Link: https://leetcode.com/problems/boats-to-save-people/

//Code:
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int boatCount = 0, left = 0, right = people.size() - 1;
        while(left <= right){
            if(people[left] + people[right] <= limit){
                left++;
                right--;
            }
            else{
                right--;
            }
            boatCount++;
        }
        return boatCount;
    }
};

/*Explanation of the Code:
    1. Sort the array in ascending order.
    2. Initialize boatCount = 0, left = 0, right = people.size() - 1.
    3. While left <= right:
        3.1 If people[left] + people[right] <= limit:
            3.1.1 Increment left and decrement right.
        3.2 Else:
            3.2.1 Decrement right.
        3.3 Increment boatCount.
    4. Return boatCount.
*/

//Time Complexity: O(nlogn)