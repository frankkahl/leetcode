// Local driver for "1. Two Sum".
// Not part of the LeetCode submission.

#include <iostream>
#include <vector>
using namespace std;

#include "twoSum.cpp"  // class Solution, exactly as pasted into LeetCode

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
        vector<int> nums = {2,7,11,15};
        int target = 9;
        Solution solution;
        print(solution.twoSum(nums, target));
        cout << "    expected: [0,1]\n";
    }

    {  // Example 2
        vector<int> nums = {3,2,4};
        int target = 6;
        Solution solution;
        print(solution.twoSum(nums, target));
        cout << "    expected: [1,2]\n";
    }

    {  // Example 3
        vector<int> nums = {3,3};
        int target = 6;
        Solution solution;
        print(solution.twoSum(nums, target));
        cout << "    expected: [0,1]\n";
    }

    return 0;
}
