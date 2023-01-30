//Problem : N-th Tribonacci Number 
//Path: https://leetcode.com/problems/n-th-tribonacci-number/

//Code:
class Solution {
public:
    int tribonacci(int n) {
        vector<int>temp={0,1,1};
        int var=0;
        for(int i=3;i<n+1;++i){
           var=temp[i-1]+temp[i-2]+temp[i-3];
           temp.push_back(var);
        }
        return temp[n];
    }
};

/*Explanation of Code:
1.We can see that the tribonacci sequence is a recursive sequence. 
2.So, we can use the concept of dynamic programming to solve this problem.
3.We can use a vector to store the values of the tribonacci sequence. 
4.We can use a for loop to iterate from 3 to n. 
5.In each iteration, we can add the previous three values of the vector and store it in a variable. 
6.Then, we can push the value of the variable in the vector. 
7.Finally, we can return the value at index n of the vector.
*/

//Time Complexity: O(n)
