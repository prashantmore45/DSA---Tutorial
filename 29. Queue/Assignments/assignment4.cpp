/*
Bonus Question : Design a data structure that follows the constraints of a LeastRecently Used (LRU) cache. 
Implement the LRUCache class: LRUCache(int capacity) : Initialize the LRU cache with positive size capacity.
int get(int key) : Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) : Update the value of the key if the key exists.
Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, 
evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Note : This question uses an additional data structure, map, that we haven’t covered yet. It will be covered in the later chapters. 
But you can read up about it & try to solve the Qs on your own.
*/

#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class LRUCache {
    int capacity;
    queue<int> q;
    unordered_map<int, int> mp;

public:
    LRUCache(int cap) {
        capacity = cap;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Remove key from queue and reinsert at back
        queue<int> temp;

        while (!q.empty()) {
            if (q.front() != key) {
                temp.push(q.front());
            }
            q.pop();
        }

        temp.push(key);
        q = temp;

        return mp[key];
    }

    void put(int key, int value) {

        // If key already exists
        if (mp.find(key) != mp.end()) {
            mp[key] = value;

            // Move it to most recent
            get(key);
            return;
        }

        // If capacity full → remove LRU
        if (q.size() == capacity) {
            int lru = q.front();
            q.pop();
            mp.erase(lru);
        }

        // Insert new key
        q.push(key);
        mp[key] = value;
    }
};

int main() {
    LRUCache cache(2);  // capacity = 2

    cache.put(1, 1);
    cache.put(2, 2);

    cout << cache.get(1) << endl;  // returns 1

    cache.put(3, 3);  // evicts key 2

    cout << cache.get(2) << endl;  // returns -1

    cache.put(4, 4);  // evicts key 1

    cout << cache.get(1) << endl;  // returns -1
    cout << cache.get(3) << endl;  // returns 3
    cout << cache.get(4) << endl;  // returns 4

    return 0;
}

/*
This approach takes O(n) time because queue does not support deletion of arbitrary elements. 
Optimal solution uses doubly linked list + hashmap for O(1).
*/