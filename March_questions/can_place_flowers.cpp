//Problem: Can Place flowers
//Link: https://leetcode.com/problems/can-place-flowers/

//Code:
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i=1;i<flowerbed.size()-1;i++)
        {
           if(flowerbed[i-1]+flowerbed[i]+flowerbed[i+1]==0)
            {
                n--;      
                i++;       
            }
        }
        return n<=0;
    }
};

/*Explanation of the above code:
    1. The function canPlaceFlowers takes in a vector of integers called flowerbed and an integer called n.
    2. A 0 is added to the beginning and end of the flowerbed vector using the insert and push_back functions.
    3. A for loop is used to iterate through the flowerbed vector from index 1 to the second to last index.
    4. If the sum of the values at the current index, the previous index, and the next index is 0, 
        then n is decremented by 1 and the index is incremented by 1.
    5. This is done to check if there is a possibility to plant a flower at the current index.
    6. The loop continues until the second to last index is reached.
    7. Finally, if the value of n is less than or equal to 0, then true is returned, 
        which means that all n flowers can be planted in the given flowerbed. 
        Otherwise, false is returned, which means that there are not enough spaces in the flowerbed to plant all n flowers.
*/

//Time Complexity: O(n)