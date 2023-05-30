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

