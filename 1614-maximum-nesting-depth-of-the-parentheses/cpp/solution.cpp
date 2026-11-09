// Local driver for "1614. Maximum Nesting Depth of the Parentheses".
// Not part of the LeetCode submission.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "maxDepth.cpp"  // class Solution, exactly as pasted into LeetCode

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
        string s = "(1+(2*3)+((8)/4))+1";
        Solution solution;
        print(solution.maxDepth(s));
        cout << "    expected: 3\n";
    }

    {  // Example 2
        string s = "(1)+((2))+(((3)))";
        Solution solution;
        print(solution.maxDepth(s));
        cout << "    expected: 3\n";
    }

    {  // Example 3
        string s = "()(())((()()))";
        Solution solution;
        print(solution.maxDepth(s));
        cout << "    expected: 3\n";
    }

    return 0;
}
