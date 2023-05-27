//Problem: Swapping Nodes in Linked List
//Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

//Code:
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* leftNode = head;
        ListNode* rightNode = head;
        
        for (int i = 1; i < k; i++) {
            leftNode = leftNode->next;
        }
        
        ListNode* current = leftNode;
        while (current->next != nullptr) {
            current = current->next;
            rightNode = rightNode->next;
        }
        
        int temp = leftNode->val;
        leftNode->val = rightNode->val;
        rightNode->val = temp;
        
        return head;
    }
};

/*Explanation of the Code:
1. We will traverse the linked list till the kth node and store it in the leftNode.
2. We will traverse the linked list till the end and store it in the rightNode.
3. We will swap the values of the leftNode and the rightNode.
4. We will return the head of the linked list.
*/

//Time Complexity: O(n)
