// Local driver for "4. Median of Two Sorted Arrays".
// Not part of the LeetCode submission.

#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

#include "findMedianSortedArrays.cpp"  // class Solution, exactly as pasted into LeetCode

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
    cout << boolalpha << fixed << setprecision(5);
    {  // Example 2
        vector<int> nums1 = {1,2, 3};
        vector<int> nums2 = {5, 6};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 3.00000\n";
    }

    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3, 5, 6};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 3.00000\n";
    }
    return 0;
    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3,4};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.50000\n";
    }


    {  // Example 1
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.00000\n";
    }

    {  // Example 1
        vector<int> nums1 = {1, 8};
        vector<int> nums2 = {2, 4, 7};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 4.00000\n";
    }

    {  // Example 1
        vector<int> nums1 = {1, 8};
        vector<int> nums2 = {1, 4, 8};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 4.00000\n";
    }

    {  // Example 1
        vector<int> nums1 = {1, 8};
        vector<int> nums2 = {1, 1, 8};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 1.00000\n";
    }

    {  // Example 1
        vector<int> nums1 = {1,3};
        vector<int> nums2 = {2,4};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.50000\n";
    }

    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3,4};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.50000\n";
    }

    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3,4};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.50000\n";
    }

    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.00000\n";
    }

    {  // Example 2
        vector<int> nums1 = {1,2};
        vector<int> nums2 = {3};
        Solution solution;
        print(solution.findMedianSortedArrays(nums1, nums2));
        cout << "    expected: 2.50000\n";
    }
    return 0;
}
