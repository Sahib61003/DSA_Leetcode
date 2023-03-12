//Problem: Minimum Time to Complete Trips
//Link: https://leetcode.com/problems/minimum-time-to-complete-all-jobs/

//Code:

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll start = 1;
        ll end = 1e14;
        while(start <= end){
            ll trip = 0;
            ll mid = start + (end - start)/2;
            for(int i=0;i<time.size();i++)
                trip += mid / time[i];
            if(trip < totalTrips){
                start = mid + 1;
            }
            else 
                end = mid - 1;
        }
        return start;
    }
};

/*Explanation of the Code:
    1. Creating a function consisting of integer array and integer variable totalTrips as parameter.
    2. Creating two variables start and end and assigning them to 1 and 1e14 respectively.
    3. Creating a while loop which will run until start is less than or equal to end.
    4. Creating two variables trip and mid and assigning them to 0 and start + (end - start) / 2 respectively.
    5. Creating a for loop which will run from 0 to time.size().
    6. trip will be assigned to trip + mid / time[i].
    7. Creating an if-else statement which will check if trip is less than totalTrips.
    8. If the condition is true then start will be assigned to mid + 1.
    9. Else end will be assigned to mid - 1.
    10. Returning start.
    11. start is the minimum time to complete all trips.
*/

// Time Complexity: O(nlogn)
