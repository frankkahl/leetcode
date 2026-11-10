// Local driver for "56. Merge Intervals".
// Not part of the LeetCode submission.

#include <iostream>
#include <vector>
using namespace std;

#include "merge.cpp"  // class Solution, exactly as pasted into LeetCode

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

    {  // Example 3
        vector<vector<int>> intervals = {{4,7},{1,4}};
        Solution solution;
        print(solution.merge(intervals));
        cout << "    expected: [[1,7]]\n";
    }

    {  // Example 1
        vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
        Solution solution;
        print(solution.merge(intervals));
        cout << "    expected: [[1,6],[8,10],[15,18]]\n";
    }

    {  // Example 2
        vector<vector<int>> intervals = {{1,4},{4,5}};
        Solution solution;
        print(solution.merge(intervals));
        cout << "    expected: [[1,5]]\n";
    }

    return 0;
}
