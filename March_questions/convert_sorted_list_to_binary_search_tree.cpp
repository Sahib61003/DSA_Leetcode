//Problem: Convert Sorted List to Binary Search Tree
//Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

//Code:
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }
        ListNode* mid = findMiddle(head);
        TreeNode* root = new TreeNode(mid->val);
        if (head == mid) {
            return root;
        }
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (prev) {
            prev->next = nullptr;
        }
        return slow;
    }
};

/*Explanation of the Code:
    1. The sortedListToBST() function takes a pointer to the head of a linked list as input and returns a pointer to the root of a binary search tree.
    2. The sortedListToBST() function uses the findMiddle() function to find the middle element of the linked list.
    3. The sortedListToBST() function creates a new node with the value of the middle element of the linked list and assigns it to the root of the binary search tree.
    4. The sortedListToBST() function recursively calls itself to create the left and right subtrees of the binary search tree.
    5. The sortedListToBST() function uses dynamic memory allocation to create and manage the binary search tree.
    6. The findMiddle() function takes a pointer to the head of a linked list as input and returns a pointer to the middle element of the linked list.
    7. The findMiddle() function uses the slow and fast pointers technique to find the middle element of the linked list.
    8. The findMiddle() function uses dynamic memory allocation to create and manage the linked list.
    9. The findMiddle() function uses a prev pointer to break the linked list into two halves.
    10. The findMiddle() function returns a pointer to the middle element of the linked list.

*/

// Time Complexity: O(n)