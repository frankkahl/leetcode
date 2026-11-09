// Local driver for "85. Maximal Rectangle".
// Not part of the LeetCode submission.

#include <iostream>
#include <vector>
using namespace std;

#include "maximalRectangle.cpp"  // class Solution, exactly as pasted into LeetCode

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
        vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
        Solution solution;
        print(solution.maximalRectangle(matrix));
        cout << "    expected: 6\n";
    }

    {  // Example 2
        vector<vector<char>> matrix = {{'0'}};
        Solution solution;
        print(solution.maximalRectangle(matrix));
        cout << "    expected: 0\n";
    }

    {  // Example 3
        vector<vector<char>> matrix = {{'1'}};
        Solution solution;
        print(solution.maximalRectangle(matrix));
        cout << "    expected: 1\n";
    }

    return 0;
}
