# 1614. Maximum Nesting Depth of the Parentheses                      [Easy]
#
# Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
#
# Example 1:
#
# Input: s = "(1+(2*3)+((8)/4))+1"
#
# Output: 3
#
# Explanation:
#
# Digit 8 is inside of 3 nested parentheses in the string.
#
# Example 2:
#
# Input: s = "(1)+((2))+(((3)))"
#
# Output: 3
#
# Explanation:
#
# Digit 3 is inside of 3 nested parentheses in the string.
#
# Example 3:
#
# Input: s = "()(())((()()))"
#
# Output: 3
#
# Constraints:
#
# - 1 <= s.length <= 100
# - s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
# - It is guaranteed that parentheses expression s is a VPS.
# https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution:
    def maxDepth(self, s: str) -> int:
        # TODO
        raise NotImplementedError


if __name__ == "__main__":
    solution = Solution()
    # Example 1
    print(solution.maxDepth("(1+(2*3)+((8)/4))+1"))  # expected: 3
    # Example 2
    print(solution.maxDepth("(1)+((2))+(((3)))"))  # expected: 3
    # Example 3
    print(solution.maxDepth("()(())((()()))"))  # expected: 3
