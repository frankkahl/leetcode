# 3. Longest Substring Without Repeating Characters                   [Medium]
#
# Given a string s, find the length of the longest substring without duplicate characters.
#
# Example 1:
#
#     Input: s = "abcabcbb"
#     Output: 3
#     Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
#
# Example 2:
#
#     Input: s = "bbbbb"
#     Output: 1
#     Explanation: The answer is "b", with the length of 1.
#
# Example 3:
#
#     Input: s = "pwwkew"
#     Output: 3
#     Explanation: The answer is "wke", with the length of 3.
#     Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
#
# Constraints:
#
# - 0 <= s.length <= 10⁵
# - s consists of English letters, digits, symbols and spaces.
# https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # TODO
        raise NotImplementedError


if __name__ == "__main__":
    solution = Solution()
    # Example 1
    print(solution.lengthOfLongestSubstring("abcabcbb"))  # expected: 3
    # Example 2
    print(solution.lengthOfLongestSubstring("bbbbb"))  # expected: 1
    # Example 3
    print(solution.lengthOfLongestSubstring("pwwkew"))  # expected: 3
