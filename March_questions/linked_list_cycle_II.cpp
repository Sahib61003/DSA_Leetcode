//Problem: Linked List Cycle II
//Path: leetcode.com/problems/linked-list-cycle-ii/


//Code:
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *entry = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
        }
        return NULL;
    }
};

/* Explanation of Code:
    1. If the list is empty or has only one node, then there is no cycle.
    2. Use two pointers, slow and fast, to traverse the list.
    3. If there is a cycle, then the two pointers will meet at some node.
    4. To find the start of the cycle, we have another pointer, entry, which starts from the head of the list.
    5. We move both pointers one node at a time. When the two pointers meet, the meeting node is the start of the cycle.
*/

//Time Complexity: O(n)