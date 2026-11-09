// 1. Two Sum                                                         [Easy]
//
// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
// You can return the answer in any order.
//
// Example 1:
//
// Input: nums = [2,7,11,15], target = 9
//
// Output: [0,1]
//
// Explanation:
//
// The sum of nums[0] and nums[1] is 2 + 7 = 9, which equals the target. Therefore, the indices [0, 1] are returned.
//
// Example 2:
//
// Input: nums = [3,2,4], target = 6
//
// Output: [1,2]
//
// Explanation:
//
// The sum of nums[1] and nums[2] is 2 + 4 = 6, which equals the target. Therefore, the indices [1, 2] are returned.
//
// Example 3:
//
// Input: nums = [3,3], target = 6
//
// Output: [0,1]
//
// Explanation:
//
// The sum of nums[0] and nums[1] is 3 + 3 = 6, which equals the target. Therefore, the indices [0, 1] are returned.
//
// Constraints:
//
// - 2 <= nums.length <= 10⁴
// - -10⁹ <= nums[i] <= 10⁹
// - -10⁹ <= target <= 10⁹
// - Only one valid answer exists.
//
// Follow-up: Can you come up with an algorithm that is less than O(n²) time complexity?
// https://leetcode.com/problems/two-sum/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map indexes anlegen mit (target - num) -> index von num => O(n)
        // iterieren über nums => wenn (target - num) in existiert => zurückgeben (i, indexes[target - nums[i]])
        // std::unordered_mapm<>: accessing a key is of O(1)
        // so build a map for reverse lookup value -> index with O(1)
        std::unordered_map<int, int> num_to_index;
        for (auto i = 0 ; i < nums.size() ; ++i) {
            num_to_index[nums[i]] = i;
        }
        for (auto i = 0 ; i < nums.size() ; ++i) {
            const auto num2 = target - nums[i]; // nums[i] + num2 == target
            // now check if num2 was part of nums by searching it in the value -> index lookup map
            const auto it = num_to_index.find(target - nums[i]);
            // if num2 is part of nums (it is valid), but not identical with nums[i] (i != it->second)
            // we found the index pair => return result
            if (it != num_to_index.end() && (i != it-> second)) {
                return vector<int>{i, it->second};
            }
        }
        // otherwise return empty vector
        return {};
    }
};
