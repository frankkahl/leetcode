// 3. Longest Substring Without Repeating Characters                  [Medium]
//
// Given a string s, find the length of the longest substring without duplicate characters.
//
// Example 1:
//
//     Input: s = "abcabcbb"
//     Output: 3
//     Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
//
// Example 2:
//
//     Input: s = "bbbbb"
//     Output: 1
//     Explanation: The answer is "b", with the length of 1.
//
// Example 3:
//
//     Input: s = "pwwkew"
//     Output: 3
//     Explanation: The answer is "wke", with the length of 3.
//     Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
//
// Constraints:
//
// - 0 <= s.length <= 10⁵
// - s consists of English letters, digits, symbols and spaces.
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> non_repeating_chars;
        int i_start = 0;
        int i_pos = 0;
        int max_length = 0;
        int curr_length = 0;
        while (true) {
            // first: increase i_pos until either the end is reached or - if not - the character at position i_pos is
            // in the set of all characters already seen exactly once
            // along this iteration store each new character into the set
            while (i_pos < s.size() && !non_repeating_chars.contains(s[i_pos])) {
                non_repeating_chars.insert(s[i_pos]);
                ++curr_length;  // for each newly found character increase the length of the sequence comprising unique characters
                ++i_pos;
            }
            // now check if the current_length exceeds the longest substring without repeating characters
            // if yes, store it as new maximum length
            if (curr_length > max_length) {
                max_length = curr_length;
            }
            // break the infinite loop if the end of the string is reached
            if (i_pos == s.size()) {
                break;
            }
            // if i_pos didn't reach the end of the string yet, then the condition
            // non_repeating_chars.contains(s[i_pos]) == true triggered the termination of the while loop.
            // Therefore,
            // now iterate i_start until it reached the position with the first occurrence of s[i_pos].
            // along the way remove all those characters from the non_repeating_chars set
            while (s[i_start] != s[i_pos]) {
                non_repeating_chars.erase(s[i_start]);
                ++i_start;
                --curr_length;
            }
            // now i_start points to the first occurrence of the character s[i_pos]
            // so remove it too and move the new beginning a potential longest sub-string candidate one beyond it
            ++i_start;
            --curr_length;
            non_repeating_chars.erase(s[i_pos]);
        }
        return max_length;
    }
};
