// 1614. Maximum Nesting Depth of the Parentheses                     [Easy]
//
// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.
//
// Example 1:
//
// Input: s = "(1+(2*3)+((8)/4))+1"
//
// Output: 3
//
// Explanation:
//
// Digit 8 is inside of 3 nested parentheses in the string.
//
// Example 2:
//
// Input: s = "(1)+((2))+(((3)))"
//
// Output: 3
//
// Explanation:
//
// Digit 3 is inside of 3 nested parentheses in the string.
//
// Example 3:
//
// Input: s = "()(())((()()))"
//
// Output: 3
//
// Constraints:
//
// - 1 <= s.length <= 100
// - s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
// - It is guaranteed that parentheses expression s is a VPS.
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <string>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0;
        int depth = 0;
        for (auto c: s) {
            switch (c) {
                case '(':
                    ++depth;
                    if (depth > max_depth) {
                        max_depth = depth;
                    }
                    break;
                case ')':
                    // in case there are more closing brackets then opening ones
                    // I return -1 as error indicator
                    if (depth == 0) {
                        return -1;
                    }
                    --depth;;
                    break;
                default:
                    break;
            }
        }
        return max_depth;
    }
};
