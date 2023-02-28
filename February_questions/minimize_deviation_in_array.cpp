// Problem: Minimize Deviation in Array
// Link: https://leetcode.com/problems/minimize-deviation-in-array/

//Code:

class Solution {
public:
      int minimumDeviation(vector<int>& a) {
            int n = a.size(); 
            int mn = INT_MAX;  
            for (int i = 0 ; i<n ; i++) {
                  if (a[i] & 1) a[i] *= 2;
                  mn = min(mn, a[i]);
            }  
            for (int i = n - 1 ; i>= 0; i--) {
                  while (a[i] % 2 == 0 and a[i]/2 >= mn) a[i] >>= 1;
            }
            sort(a.begin(), a.end()); 
            int ans = a[n - 1] - a[0]; 
            int i = n - 1; 
            while (a[i] % 2 == 0) { 
                  a[i] /= 2;
                  ans = min(ans, a[(i - 1 + n) % n] - a[i]); 
                  i = (i - 1 + n) % n;
            } 
            return (int)ans; 
      }
};

/*Explanation of the code:
    1. We will use a for loop to traverse the array.
    2. We will use a if condition to check if the number is odd.
    3. If it is then we will multiply it by 2.
    4. We will use a for loop to traverse the array in reverse order.
    5. We will use a while loop to check if the number is even and the number divided by 2 is greater than or equal to the minimum number.
    6. If it is then we will divide the number by 2.
    7. We will use a sort function to sort the array.
*/

//Time Complexity: O(nlogn)