# 56. Merge Intervals                                                 [Medium]
#
# Given an array of intervals where intervals[i] = [start_(i), end_(i)], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
#
# Example 1:
#
#     Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
#     Output: [[1,6],[8,10],[15,18]]
#     Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
#
# Example 2:
#
#     Input: intervals = [[1,4],[4,5]]
#     Output: [[1,5]]
#     Explanation: Intervals [1,4] and [4,5] are considered overlapping.
#
# Example 3:
#
#     Input: intervals = [[4,7],[1,4]]
#     Output: [[1,7]]
#     Explanation: Intervals [1,4] and [4,7] are considered overlapping.
#
# Constraints:
#
# - 1 <= intervals.length <= 10⁴
# - intervals[i].length == 2
# - 0 <= start_(i) <= end_(i) <= 10⁴
# https://leetcode.com/problems/merge-intervals/

class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        # TODO
        raise NotImplementedError


if __name__ == "__main__":
    solution = Solution()
    # Example 1
    print(solution.merge([[1,3],[2,6],[8,10],[15,18]]))  # expected: [[1,6],[8,10],[15,18]]
    # Example 2
    print(solution.merge([[1,4],[4,5]]))  # expected: [[1,5]]
    # Example 3
    print(solution.merge([[4,7],[1,4]]))  # expected: [[1,7]]
