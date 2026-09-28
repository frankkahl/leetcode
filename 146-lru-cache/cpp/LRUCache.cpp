// 146. LRU Cache                                                     [Medium]
//
// Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
//
// Implement the LRUCache class:
//
// - LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// - int get(int key) Return the value of the key if the key exists, otherwise return -1.
// - void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
//
// The functions get and put must each run in O(1) average time complexity.
//
// Example 1:
//
//     Input
//     ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//     Output
//     [null, null, null, 1, null, -1, null, -1, 3, 4]
//
//     Explanation
//     LRUCache lRUCache = new LRUCache(2);
//     lRUCache.put(1, 1); // cache is {1=1}
//     lRUCache.put(2, 2); // cache is {1=1, 2=2}
//     lRUCache.get(1);    // return 1
//     lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//     lRUCache.get(2);    // returns -1 (not found)
//     lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//     lRUCache.get(1);    // return -1 (not found)
//     lRUCache.get(3);    // return 3
//     lRUCache.get(4);    // return 4
//
// Constraints:
//
// - 1 <= capacity <= 3000
// - 0 <= key <= 10⁴
// - 0 <= value <= 10⁵
// - At most 2 * 10⁵ calls will be made to get and put.
// https://leetcode.com/problems/lru-cache/
#include <list>
#include <unordered_map>

class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity), _map{(size_t)capacity} {
    }
    
    int get(int key) {
        const auto it = _map.find(key);
        if (it == _map.end()) {
            return -1;
        }
        // this takes entry for the key key in the list and moves it to the end of the list, indicating that it was access the latest
        // the important point here is that the iterator to the element remains valid after splice()
        _list.splice(_list.end(), _list , it->second );
        return it->second->second ;
    }
    
    void put(int key, int value) {
        const auto it = _map.find(key);
        // if this key is unknown...
        if (it == _map.end()) {
            // check if the maximum capacity was already reached
            if (_map.size() == _capacity) {
                // if the capacity is reached then oldest element is evicted. The oldest element is stored at the very
                // beginning of the list and the key is stored as the first element of the pair
                _map.erase(_list.begin()->first);
                // Now use the very first element as storage...
                _list.begin()->first = key;
                _list.begin()->second = value;
                // ...then move it to the end of the list marking it as the elment accessed the lates
                _list.splice(_list.end(), _list , _list.begin() );
            }
            else {
                // if no, then create an entry at the end of the list, marking it as the one accessed/created the latest
                _list.emplace_back(key,  value);
            }
            // now store the iterator to this list entry under key in the _map
            _map[key] = std::prev(_list.end());
        }
        else {
            // the key has already an entry, so overwrite its value in the _list
            it->second->second = value;
            // and then move it to the end of the list marking it as accessed the latest
            _list.splice(_list.end(), _list , it->second );
        }
    }
private:
    const int _capacity;

    // a std::list is ordered. Here, the very first element of the list is the oldest
    // and the element at the end of the list is one which was created/accessed the latest4
    // the first element of the pair is the key, the second element is the value
    // storing the key here, too, is required to obtain the key of the oldest element so that we can erase it
    // in the map if the capacity is exhausted before overwriting the node in the list with the new entry
    typedef std::list< std::pair<int, int> > List;
    List _list;
    // the unordered_map guaranteed O(1) access.
    std::unordered_map<int, List::iterator> _map;
};
