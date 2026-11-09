# 85. Maximal Rectangle                                               [Hard]
#
# Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
#
# Example 1:
#
# []
#
#     Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
#     Output: 6
#     Explanation: The maximal rectangle is shown in the above picture.
#
# Example 2:
#
#     Input: matrix = [["0"]]
#     Output: 0
#
# Example 3:
#
#     Input: matrix = [["1"]]
#     Output: 1
#
# Constraints:
#
# - rows == matrix.length
# - cols == matrix[i].length
# - 1 <= rows, cols <= 200
# - matrix[i][j] is '0' or '1'.
# https://leetcode.com/problems/maximal-rectangle/

class Solution:
    def maximalRectangle(self, matrix: list[list[str]]) -> int:
        # TODO
        raise NotImplementedError


if __name__ == "__main__":
    solution = Solution()
    # Example 1
    print(solution.maximalRectangle([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))  # expected: 6
    # Example 2
    print(solution.maximalRectangle([["0"]]))  # expected: 0
    # Example 3
    print(solution.maximalRectangle([["1"]]))  # expected: 1
