// 460. LFU Cache                                                     [Hard]
//
// Design and implement a data structure for a Least Frequently Used (LFU) cache.
//
// Implement the LFUCache class:
//
// - LFUCache(int capacity) Initializes the object with the capacity of the data structure.
// - int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
// - void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
//
// To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.
//
// When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.
//
// The functions get and put must each run in O(1) average time complexity.
//
// Example 1:
//
//     Input
//     ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
//     [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//     Output
//     [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//
//     Explanation
//     // cnt(x) = the use counter for key x
//     // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
//     LFUCache lfu = new LFUCache(2);
//     lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//     lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//     lfu.get(1);      // return 1
//                      // cache=[1,2], cnt(2)=1, cnt(1)=2
//     lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
//                      // cache=[3,1], cnt(3)=1, cnt(1)=2
//     lfu.get(2);      // return -1 (not found)
//     lfu.get(3);      // return 3
//                      // cache=[3,1], cnt(3)=2, cnt(1)=2
//     lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
//                      // cache=[4,3], cnt(4)=1, cnt(3)=2
//     lfu.get(1);      // return -1 (not found)
//     lfu.get(3);      // return 3
//                      // cache=[3,4], cnt(4)=1, cnt(3)=3
//     lfu.get(4);      // return 4
//                      // cache=[4,3], cnt(4)=2, cnt(3)=3
//
// Constraints:
//
// - 1 <= capacity <= 10⁴
// - 0 <= key <= 10⁵
// - 0 <= value <= 10⁹
// - At most 2 * 10⁵ calls will be made to get and put.
// https://leetcode.com/problems/lfu-cache/
#include <list>
#include <unordered_map>

#include <map>

class LFUCache {
public:
    LFUCache(int capacity): _capacity(capacity), _map{(size_t)capacity} {
    }

    int get(int key) {
        const auto it = _map.find(key);
        if (it == _map.end()) {
            return -1;
        }
        // Now increase the counter for the entry it->second and re-arrange it's position in _counter_list accordingly
        increase_count(it);
        return it->second->value;
    }

    void put(int key, int value) {
        const auto it = _map.find(key);
        // if this key is unknown...
        if (it == _map.end()) {
            // check if the maximum capacity was already reached
            if (_map.size() == _capacity) {
                // The very first node in the list contains in its member list lru_list all entries with the least frequently used counter
                // If this list is larger than 1, then all those nodes have the same usage count
                auto &src_list = _counter_list.begin()->lru_list;
                // and in this list the very first entry is the one was the least recently used
                auto it_entry_reused = src_list.begin();
                // now delete the entry of the key in _maps which will now be replaced
                _map.erase(it_entry_reused->key);
                // Store the new key and value into the re-used ListEntry
                it_entry_reused->key = key;
                it_entry_reused->value = value;

                // if the _counter_list entry which contains the re-used entry has a count != 1, then
                // we have to create a new entry with bucket count 1 and add it at the front of _counter_list
                if (it_entry_reused->it_counter_list_entry->count != 1) {
                    _counter_list.emplace_front(1, List{});
                    // this is now the destination list
                    auto &dest_list = _counter_list.begin()->lru_list;
                    // now copy the re-used entry from the source to the end of the destination list
                    // the position at the end marks that it was the most recently used
                    dest_list.splice(dest_list.end(), src_list , it_entry_reused );
                }
                else {
                    // If the re-used entry did already belong to the set of entries with count == 1, then
                    // we just have to move it to the very end to mark it as the most recently used
                    src_list.splice(src_list.end(), src_list , it_entry_reused );
                }
                // If the entry for the original count of the re-used entry doesn't contain any entries at all,
                // then delete it from _counter_list.
                // This can only happen if the usage count for the re-used entry was >0, since then
                // the entry is moved from its lru_list to the newly inserted one for count == 1
                if (it_entry_reused->it_counter_list_entry->lru_list.empty()) {
                    _counter_list.erase(it_entry_reused->it_counter_list_entry);
                }
                // in any case, the entry has to point to the very first node of _counter_list with count == 1
                it_entry_reused->it_counter_list_entry = _counter_list.begin();
                // and now set this re-used entry as the entry for this new key
                _map[key] = it_entry_reused;
            }
            else {
                // here a previously unknown key was passed, but the capacity is not exceeded yet.
                // Therefore, have a look if the very first element of _counter_list is for counter 1.
                // If yes, then create an entry and add it to the end of this list, marking it as the
                // most recently used.
                // If no, then create a new entry at the very beginning of _counter_list with count=1
                auto it_begin = _counter_list.begin();
                if (it_begin == _counter_list.end() || it_begin->count != 1) {
                    _counter_list.emplace_front(1, List{});
                    it_begin = _counter_list.begin();
                }
                it_begin->lru_list.emplace_back(key, value, it_begin);
                // now store the iterator to the entry of this new key in _map
                _map[key] = std::prev(it_begin->lru_list.end());
            }
        }
        else {
            it->second->value = value;
            // Now increase the counter for the entry it->second and re-arrange it's position in _counter_list accordingly
            increase_count(it);
        }
    }
private:
    const int _capacity;

    // forward declaration
    struct CounterListEntry;
    // The counter list keeps an ordered sequence of nodes containing the usage count of elements and a sub-list
    // containing all elements with this usage count. So the very first node are elements with the lowest usage count
    // The entries in the sub-list are ordered in ascending order of the most recent usage. So the very first entry
    // of this sub-list is always least recently used one.
    using CounterList =  std::list<CounterListEntry>;

    struct ListEntry{
        int key{-1};
        int value{-1};
        // This points to the entry in the _counter-list which contains the count of this element and the sub-list of which
        // this entry is part of.
        // Warning: The fact that it_counter_list->second contains elements which refer back to it_counter_list_entry
        //    might result in an infinite loop of gdb when it tries to display the content.
        CounterList::iterator it_counter_list_entry;
    };

    // This is the sub-list in the nodes of CounterList which store all entries having the same usage count
    using List = std::list<ListEntry>;

    // Data type stored in CounterList / _counter_list
    struct CounterListEntry{
        int count{0};
        List lru_list;
    };


    CounterList _counter_list;

    // This is the key lookup map. We have chosen an unordered_one to guarantee O(1) access
    std::unordered_map<int, List::iterator> _map;

    // This handles increasing the count of *it. Since the count of an element is defined by the
    // node of _counter_list in wholse lru_list it's contained, This method handles moving
    // the element into the lru_list of the node with the correct count. If no such node exists yet, it creates one
    // This helper method
    void increase_count(std::unordered_map<int, List::iterator>::iterator it) {

        // Get the actual entry first
        auto it_entry = it->second;
        // now look up the node in _counter_list of whose lru_list it's a member of
        auto it_counter_list_entry = it->second->it_counter_list_entry;
        // The usage count of the entry is then it_counter_list_entry->count
        // Now we increase this count
        auto new_count =it_counter_list_entry->count + 1;
        // and then we look up if there is already a node which stores entries for this usage count
        // since we increased the count by one and _counter_list is sorted w.r.t. the count, we check if the next following
        // element in _counter_list stores elements of this new count, if there is a next node.
        auto it_next_counter_entry = std::next(it_counter_list_entry);
        if (it_next_counter_entry == _counter_list.end() || it_next_counter_entry->count != new_count) {
            // If the next node doesn't store elements of the new count, we insert a new node for this count
            // between the current and the next node
            it_next_counter_entry = _counter_list.emplace(it_next_counter_entry, new_count, List{});
        }
        // The lru_list of this next entry is now our destination sub-list
        auto &dest_list = it_next_counter_entry->lru_list;
        // and the lru_list of the current counter list entry our soruce
        auto &src_list = it_counter_list_entry->lru_list;

        // Now we move the entry to this new list
        dest_list.splice(dest_list.end(), src_list, it_entry);
        // If the lru_list of the old counter is now empty, we can erase the node in the _counter_list for the old counter
        // entirely
        if (it_counter_list_entry->lru_list.empty()) {
            _counter_list.erase(it_counter_list_entry);
        }
        // Now we have to update the iterator of the current entry to point to the new node in _counter_list with the
        // correct count
        it_entry->it_counter_list_entry = it_next_counter_entry;
    }
};
