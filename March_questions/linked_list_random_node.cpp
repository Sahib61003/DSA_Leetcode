//Problem: Linked List Random Node
//Link: https://leetcode.com/problems/linked-list-random-node/

//Code:
class Solution {
    vector<int> v;
    int n;
public:
    Solution(ListNode *head) {
        ListNode *ptr = head;
        while (ptr) {
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        n = v.size();
    }
    int getRandom() {
        static int i = 0;
        if (i == 0) {
            srand(time(NULL));
            i++;
        }
        return v[rand() % n];
    }
};

/*Explanation of Code:
    1. The Solution class has a constructor that takes a linked list as input and initializes a vector with the values of the linked list.
    2. The getRandom() function returns a random element from the vector.
    3. The getRandom() function uses a static integer variable named i to seed the random number generator with the current time only once.
    4. The getRandom() function uses the rand() function to generate a random index for the vector, 
       which is then used to retrieve a random element from the vector.
    5. The Solution class uses dynamic memory allocation to create and manage the linked list.

*/

// Time Complexity: O(1)