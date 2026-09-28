// 115. Distinct Subsequences                                         [Hard]
//
// Given two strings s and t, return the number of distinct subsequences of s which equals t.
//
// The test cases are generated so that the answer fits on a 32-bit signed integer.
//
// Example 1:
//
//     Input: s = "rabbbit", t = "rabbit"
//     Output: 3
//     Explanation:
//     As shown below, there are 3 ways you can generate "rabbit" from s.
//     rabbbit
//     rabbbit
//     rabbbit
//
// Example 2:
//
//     Input: s = "babgbag", t = "bag"
//     Output: 5
//     Explanation:
//     As shown below, there are 5 ways you can generate "bag" from s.
//     babgbag
//     babgbag
//     babgbag
//     babgbag
//     babgbag
//
// Constraints:
//
// - 1 <= s.length, t.length <= 1000
// - s and t consist of English letters.
// https://leetcode.com/problems/distinct-subsequences/

#include <string>
using namespace std;

class Solution {
public:
    // works but is way to slow (exponential complexity)
    int numDistinct(string s, string t) {
        int counter = 0;
        auto recurse = [&counter, &s, &t](auto self, size_t s_start, size_t t_pos) -> void {
            if (s_start == s.size()) {
                return;
            }
            string::size_type found_pos = string::npos;
            while ((found_pos = s.find(t[t_pos], s_start)) != string::npos) {
                s_start = found_pos+1;
                // this means that that last char of t was also found in s, so
                if (t_pos+1 == t.size()) {
                    counter++;
                }
                else {
                    self(self, s_start, t_pos+1);
                }
            }
        };
        recurse(recurse, 0, 0);
        // recursive_scan(s, 0, t, 0, counter);
        return counter;
    }
};
