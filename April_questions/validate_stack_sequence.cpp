//Problem: Validate Stack Sequence
//Link: https://leetcode.com/problems/validate-stack-sequences/

//Code:
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; 
        for(auto val : pushed){
            st.push(val); 
            while(st.size() > 0 && st.top() == popped[j]){ 
                st.pop(); 
                j++;
            }
        }
        return st.size() == 0; 
    }
};

/*Explanation of the Code:  
    1. We use a stack to store the pushed elements.
    2. We use a variable j to store the index of the popped vector.
    3. We iterate through the pushed vector.
    4. We push the element into the stack.
    5. We check if the top of the stack is equal to the element at index j of the popped vector.
    6. If it is, we pop the stack and increment j.
    7. We return true if the stack is empty.
*/
// Time Complexity: O(n)
