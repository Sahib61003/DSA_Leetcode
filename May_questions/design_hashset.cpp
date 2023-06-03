//Problem: Design Hashset
//Link: https://leetcode.com/problems/design-hashset/

//Code:

class MyHashSet {
private:
    int size;
    std::vector<std::list<int>> buckets;

public:
    MyHashSet() {
        size = 1000;
        buckets = std::vector<std::list<int>>(size);
    }

    void add(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        if (!contains(key, bucket)) {
            bucket.push_back(key);
        }
    }

    void remove(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        bucket.remove(key);
    }

    bool contains(int key) {
        int index = hash(key);
        std::list<int>& bucket = buckets[index];
        return contains(key, bucket);
    }

private:
    int hash(int key) {
        return key % size;
    }

    bool contains(int key, std::list<int>& bucket) {
        for (int num : bucket) {
            if (num == key) {
                return true;
            }
        }
        return false;
    }
};


/*explanation of the Code:
    1. The code implements a simplified version of has set data structure
    2. The code uses a vector of lists to store the elements
    3. The code uses a hash function to map the key to an index in the vector
    4. The code uses a linked list to store the elements in the same bucket
    5. The code uses a simple linear search to check if the element is present in the bucket
    6. The code uses a simple linear search to remove the element from the bucket
    7. The code uses a simple linear search to add the element to the bucket.
    8. The code contains a private class.
    9. The code contains a private function to calculate the hash value.
    10. The code contains a private function to check if the element is present in the bucket.
*/

// Time Complexity: O(1)
