//
// Given an array of intervals where intervals[i] = [start_(i), end_(i)], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
//
// Example 1:
//
//     Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
//     Output: [[1,6],[8,10],[15,18]]
//     Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
//
// Example 2:
//
//     Input: intervals = [[1,4],[4,5]]
//     Output: [[1,5]]
//     Explanation: Intervals [1,4] and [4,5] are considered overlapping.
//
// Example 3:
//
//     Input: intervals = [[4,7],[1,4]]
//     Output: [[1,7]]
//     Explanation: Intervals [1,4] and [4,7] are considered overlapping.
//
// Constraints:
//
// - 1 <= intervals.length <= 10⁴
// - intervals[i].length == 2
// - 0 <= start_(i) <= end_(i) <= 10⁴
// https://leetcode.com/problems/merge-intervals/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals by their lower bounds
        sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {return a[0] < b[0];});

        vector<vector<int>> result;
        result.reserve(intervals.size());

        for (const auto &interval: intervals) {
            // If result is completely empty, then store the first interval into it.
            // If result.back() is already valid but the lower bound of interval is larger than the upper bound of result.back(),
            // then interval is not overlapping with result.back(). Therefore, we don't have to merge it and can just add it
            // as the new last interval in result interval doesn't overlap with it.
            if (result.empty() || (interval[0] > result.back()[1])) {
                result.push_back(interval);
                continue;
            }
            // If this line is reached, then interval overlaps with result.back() so that we have to merge it with it.
            // Since the intervals are sorted w.r.t. the lower bounds, the lower bound of interval (index 0)
            // is always >= the lower bound of result.back() (index 0). For the new upper bound of result.back()
            // we have to use the maximum of both intervals.
            result.back()[1] = max(interval[1], result.back()[1]);
        }
        return result;
    }
};
