//Problem: Average salary excluding minimum and maximum salary
//Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

//Code:
class Solution {
public:
    double average(vector<int>& salary) {
        int max = salary[0];  
        int min = salary[0];
        int sum = 0;
        for (int i = 0; i < salary.size(); i++) { 
            if (salary[i] > max) {
                max = salary[i];
            }
            if (salary[i] < min) {
                min = salary[i];
            }
            sum += salary[i];
        }
        return (sum - max - min) / (salary.size() - 2.0);
        
    }
};

/*Explanation of the Code:  
    1. We will iterate over the vector salary.
    2. We will find the maximum and minimum salary.
    3. We will find the sum of all the salaries.
    4. We will return the average of all the salaries excluding the maximum and minimum salary.
*/

//Time Complexity: O(n)
