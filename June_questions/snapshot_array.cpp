//Problem: Snapshot Array
//Link: https://leetcode.com/problems/snapshot-array/

//Code:
class SnapshotArray {
public:
    vector<map<int,int>>A;
    // snap_id
    int s_id = 0;
    SnapshotArray(int length) {
        A.resize(length); 
        for(int i = 0; i < length; i++) 
            A[i][0] = 0;
        
    }

    void set(int index, int val) { 
        A[index][s_id] = val;
    }
    
    int snap() {
        s_id++;
        return  s_id - 1;
    }
    
    int get(int index, int snap_id) {
        if(A[index].find(snap_id) == A[index].end())
        {
            auto it = --A[index].lower_bound(snap_id);
            return it->second;
        }
        return A[index][snap_id];
    }
};

/*Explanation of the Code:
    1. We have created a class SnapshotArray.
    2. We have created a vector of map A.
    3. We have created a variable s_id to store the snap_id.
    4. We have created a constructor SnapshotArray.
    5. We have resized the vector A to length.
    6. We have created a for loop to iterate through the vector A.
    7. We have set the value of the current element of the vector A to 0.
    8. We have created a function set.
    9. We have set the value of the current element of the vector A to val.
    10. We have created a function snap.
    11. We have incremented s_id by 1.
    12. We have returned s_id - 1.
    13. We have created a function get.
    14. We have created a if statement to check if the snap_id is not present in the map.
    15. If the above condition is true, we have created a iterator it to store the lower bound of the snap_id.
    16. We have returned the value of the second element of the iterator it.
    17. We have returned the value of the snap_id.
*/

// Time Complexity: O(logn)
