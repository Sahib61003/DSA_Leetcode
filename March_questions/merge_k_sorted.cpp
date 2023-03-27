//Problem: Merge k Sorted Lists
//Link: https://leetcode.com/problems/merge-k-sorted-lists/

//Code:
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>v;
        for(int i=0;i<lists.size();i++){
            while(lists[i]){
                v.push_back(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }
        sort(rbegin(v),rend(v));
        ListNode* ans=nullptr;
        for(int i=0;i<v.size();i++){
            ans=new ListNode(v[i],ans);
        }
        return ans;
    }
};

/*Explanation of the Code:
    1. Initialising a function mergeKLists with parameter lists of the vector
    2. Initialising a vector v
    3. For loop to iterate through the vector lists
    4. While loop to iterate through the list
    5. Pushing the value of the list into the vector v
    6. Moving to the next node
    7. Sorting the vector v in descending order
    8. Initialising a ListNode ans with value null
    9. For loop to iterate through the vector v
    10. Creating a new node with value v[i] and pointing it to the previous node
    11. Returning the node ans
*/

//Time Complexity: O(nlogn)
