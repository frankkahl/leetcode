// Local driver for "3. Longest Substring Without Repeating Characters".
// Not part of the LeetCode submission.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "lengthOfLongestSubstring.cpp"  // class Solution, exactly as pasted into LeetCode

namespace {

template <typename T> void print(const T& value);
template <typename T> void print(const vector<T>& values);

template <typename T> void print(const T& value) { cout << value; }

template <typename T> void print(const vector<T>& values) {
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i) {
        if (i) cout << ',';
        print(values[i]);
    }
    cout << ']';
}

}  // namespace

int main() {
    cout << boolalpha;

    {  // Example 1
        string s = "1R1T7";
        Solution solution;
        print(solution.lengthOfLongestSubstring(s));
        cout << "    expected: 4\n";
    }

    {  // Example 1
        string s = "abcabcbb";
        Solution solution;
        print(solution.lengthOfLongestSubstring(s));
        cout << "    expected: 3\n";
    }

    {  // Example 2
        string s = "bbbbb";
        Solution solution;
        print(solution.lengthOfLongestSubstring(s));
        cout << "    expected: 1\n";
    }

    {  // Example 3
        string s = "pwwkew";
        Solution solution;
        print(solution.lengthOfLongestSubstring(s));
        cout << "    expected: 3\n";
    }

    return 0;
}
