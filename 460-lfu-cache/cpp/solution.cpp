// Local driver for "460. LFU Cache".
// Not part of the LeetCode submission.

#include <iostream>
#include <vector>

using namespace std;

#include "LFUCache.cpp"  // class LFUCache, exactly as pasted into LeetCode

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
        LFUCache obj(2);
        cout << "[null";
        obj.put(1, 1);
        cout << ",null";
        obj.put(2, 2);
        cout << ",null";
        cout << ',';
        print(obj.get(1));
        obj.put(3, 3);
        cout << ",null";
        cout << ',';
        print(obj.get(2));
        cout << ',';
        print(obj.get(3));
        obj.put(4, 4);
        cout << ",null";
        cout << ',';
        print(obj.get(1));
        cout << ',';
        print(obj.get(3));
        cout << ',';
        print(obj.get(4));
        cout << "]\n";
        cout << "    expected: [null, null, null, 1, null, -1, 3, null, -1, 3, 4]\n";
    }

    return 0;
}
