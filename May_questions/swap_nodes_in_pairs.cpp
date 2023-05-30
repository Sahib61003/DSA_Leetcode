//Problem: Swap Nodes in Pair
//Link: https://leetcode.com/problems/swap-nodes-in-pairs/

//Code:
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) 
        {
            return head;
        }
            
        ListNode* temp; 
        temp = head->next; 
        
        head->next = swapPairs(head->next->next); 
        temp->next = head; 
        
        return temp; 
    }
};

/*Explanation of the Code:
    1. The idea is to swap the first two nodes and then call the function recursively for the rest of the list.
    2. The base case of the recursion would be when the list is empty or has just one node.
    3. The recursive function returns the pointer to the swapped list.
    4. The first two lines of the function are the base case.
    5. The third line stores the pointer to the second node in the list in a temporary variable.
    6. The fourth line calls the function recursively for the rest of the list.
    7. The fifth line makes the next of the second node point to the first node.
    8. The sixth line makes the next of the first node point to the rest of the list.
    9. The seventh line returns the pointer to the second node.
*/

// Time Complexity: O(N)
