// Local driver for "609. Find Duplicate File in System".
// Not part of the LeetCode submission.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "findDuplicate.cpp"  // class Solution, exactly as pasted into LeetCode

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
        vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
        Solution solution;
        print(solution.findDuplicate(paths));
        cout << "    expected: [[\"root/a/2.txt\",\"root/c/d/4.txt\",\"root/4.txt\"],[\"root/a/1.txt\",\"root/c/3.txt\"]]\n";
    }

    {  // Example 2
        vector<string> paths = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)"};
        Solution solution;
        print(solution.findDuplicate(paths));
        cout << "    expected: [[\"root/a/2.txt\",\"root/c/d/4.txt\"],[\"root/a/1.txt\",\"root/c/3.txt\"]]\n";
    }

    return 0;
}
