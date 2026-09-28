// 4. Median of Two Sorted Arrays                                     [Hard]
//
// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
//
// The overall run time complexity should be O(log (m+n)).
//
// Example 1:
//
//     Input: nums1 = [1,3], nums2 = [2]
//     Output: 2.00000
//     Explanation: merged array = [1,2,3] and median is 2.
//
// Example 2:
//
//     Input: nums1 = [1,2], nums2 = [3,4]
//     Output: 2.50000
//     Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
//
// Constraints:
//
// - nums1.length == m
// - nums2.length == n
// - 0 <= m <= 1000
// - 0 <= n <= 1000
// - 1 <= m + n <= 2000
// - -10⁶ <= nums1[i], nums2[i] <= 10⁶
// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <iostream>

using namespace std;

bool one_step(vector<int> &nums1, size_t &i1, vector<int> &nums2, size_t &i2, const size_t total_num, double &median) {
    if (i1 == nums1.size() && i2 == nums2.size()) {
        return false;
    }
    if (i2 == nums2.size() || (nums1[i1] > nums2[i2])) {
        // this normalizes the arguments such that i2 is always valid
        std::swap(i1, i2);
        std::swap(nums1, nums2);
    }
    while (nums1[i1] < nums2[i2] && i1 < nums1.size() && (i1 + i2) < total_num / 2) {
        ++i1;
    }
    if ((i1 + i2) == total_num / 2) {
        if (i1 == nums1.size()) {
            if (total_num % 2) {
                median = nums2[i2];
            } else {
                median = (nums2[nums1.size() - 1] + nums2[i2]) / 2.0;
            }
            return true;
        } else {
            if (total_num % 2) {
                median = nums2[i2];
            } else {
                median = (nums2[i1] + nums2[i2 + 1]) / 2.0;
            }
            return true;
        }
    }
    return false;
}

double median_one_list(const vector<int> &nums) {
    if (nums.size() % 2) {
        return nums[nums.size() / 2];
    }
    return (nums[nums.size() / 2] + nums[nums.size() / 2 - 1]) / 2.0;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        const auto total_num = nums1.size() + nums2.size();
        const bool is_even = !(total_num % 2);
        // first check for the edge cases
        // both lists are empty
        if (total_num == 0) {
            return 0.0;
        }
        // if only one list is empty then calculating teh median of the other becomes trivial
        // see implementation of median_one_list()
        if (nums1.empty()) {
            return median_one_list(nums2);
        }
        if (nums2.empty()) {
            return median_one_list(nums1);
        }
        // the interesting part is if both lists are non-empty
        int i1 = 0;
        int i2 = 0;
        // now initialize the two sliding values of the combined sequence
        int prev_val = 0;
        int curr_val = 0;
        int idx_curr_val = -1; // index of the current value in the combined sequence

        // for an even number of total element, e.g. 8, total_num/2 is 4, which labels the 5th element of the combined
        // list, so that the median is the average of the 4th and 5th element
        // for an odd number, e.g. 7, total_num /2 is 3, which is exactly the fourth element, which is the median element
        while (true) {
            // this can be optimized if i2 already reaches the end of nums2
            // in that case it just iterates over nums1 until the condition is reached
            // later on I plan to replace it by a simple direct calculation of the of the index
            auto calc_med = [&total_num, &is_even](const vector <int> &nums1, const vector<int> &nums2) -> double  {
                const vector<int>::size_type i1 = (total_num /2 - nums2.size());
                if (is_even) {
                    if (i1) {
                        return (double)(nums1[i1] + nums1[i1-1]) / 2.0;
                    }
                    return (double)(nums1[i1] + (nums2[nums2.size()-1]))/2.0;
                }
                return nums1[i1];

            };

            if (i2 == nums2.size()) {
                return calc_med(nums2, nums1);
            }
            if (i1 == nums1.size()) {
                return calc_med(nums1, nums2);
            }
            if (idx_curr_val == total_num / 2) {
                break;
            }
            if (nums1[i1] < nums2[i2]) {
                prev_val = curr_val;
                curr_val = nums1[i1];
                ++i1;
                ++idx_curr_val;
                continue;
            }
            if (nums2[i2] <= nums1[i1]) {
                prev_val = curr_val;
                curr_val = nums1[i2];
                ++i2;
                ++idx_curr_val;
                continue;
            }
        }
        if (is_even) {
            return (prev_val + curr_val) / 2.0;
        }
        return curr_val;
    }
};

// double Solution::findMedianSortedArrays_(vector<int> &nums1, vector<int> &nums2) {
//     auto &s1 = nums1;
//     auto &s2 = nums2;
//     // const size_t total_num = nums1.size() + nums2.size();
//     size_t i1 = 0;
//     size_t i2 = 0;
//     double median = 0.0;
//     while (!one_step(s1, i1, s2, i2, s1.size() + s2.size(), median)) {
//     }
//     std::cout << "i1: " << i1 << ", i2: " << i2 << ", median: " << median << std::endl;
//     return median;
// }
