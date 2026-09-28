// Local driver for "115. Distinct Subsequences".
// Not part of the LeetCode submission.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "numDistinct.cpp"  // class Solution, exactly as pasted into LeetCode

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
        string s = "rabbbit";
        string t = "rabbit";
        Solution solution;
        print(solution.numDistinct(s, t));
        cout << "    expected: 3\n";
    }

    {  // Example 2
        string s = "babgbag";
        string t = "bag";
        Solution solution;
        print(solution.numDistinct(s, t));
        cout << "    expected: 5\n";
    }

    return 0;
}
