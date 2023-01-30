//Problem: LFU Cache
//Path:  https://leetcode.com/problems/LFU-cache/

//Code:
class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty())
                minFreq++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/*Explanation of the Code in brief:
    1. The code implements an LRU (Least Recently Used) Cache data structure using a combination of unordered_maps and linked lists.
    2. The class LFUCache has four unordered_maps for storing key-value pairs, frequencies, and positions,
        and an integer for minimum frequency.
    3. The constructor LFUCache(int capacity) initializes the cache with a given capacity and sets the minimum frequency to 0.
    4. The get method retrieves the value of the given key from the cache. If the key is not present, 
        it returns -1. If the key is present, it updates the frequency of the key and its position in the linked list of the corresponding frequency. 
    5. If the linked list of the minimum frequency is empty after the update, the minimum frequency is incremented.
    6. The put method adds a key-value pair to the cache. If the capacity is 0, the method returns without doing anything. 
    7. If the key already exists, the method updates its value and frequency. 
    8. If the cache is full, the least frequently used key is removed before adding the new key-value pair.
*/

//Time Complexity: O(1)
