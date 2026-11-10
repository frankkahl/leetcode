# 56. Merge Intervals: C++ solution refinement

**Date:** 2026-11-10

## Resume this session

```
claude --resume bacc6fda-e261-42c9-ba91-fcaf4c6bb544
```

Originally started in: `/home/frank/devel/leetcode/56-merge-intervals/cpp`

Display name when written: `cpp-99` (directory placeholder; may have since changed).

---

## Summary

A practice session on LeetCode 56. Merge Intervals in C++. The user wrote and submitted the
solution themselves. Claude answered C++ questions and reviewed each revision of
`merge.cpp`, compiling it with `g++ -std=c++20 -Wall -Wextra` and running the driver's
three examples each time.

The solution went through four submitted or reviewed versions:

1. **Reference to `intervals[0]` as a scratch slot.** It started with
   `auto interval = intervals[0];`, which copies, since `auto` drops references. Changed to
   `auto &interval`. Merged with `interval[1] = max(...)` and moved on with
   `interval = next_interval;`. Submitted and accepted. Key insight: that assignment does
   **not** rebind the reference. A C++ reference can't be pointed at a different object;
   assigning through it calls `vector<int>`'s copy assignment into `intervals[0]`. That's
   harmless only because `intervals[0]` is never read as input again after sorting.
2. **Merge into `result.back()`.** Pushed `intervals[0]` into `result`, then either
   `push_back(next)` for a disjoint interval or extended `result.back()[1]`. Each output
   interval is copied once instead of twice. Note: take `result.back()` fresh on each
   iteration, because `push_back` can reallocate and leave references dangling.
3. **One range-based loop with `result.empty() ||`.** Treating "nothing merged yet" like a
   disjoint interval removes the special first element and the empty-input check.
4. **Final version.** Dropped the `size() != 2` sanity checks. They ran after the sort,
   whose comparator already reads `a[0]`, so they couldn't protect anything, and LeetCode
   guarantees size 2. Added `result.reserve(intervals.size())`. Submitted and accepted.
   It's O(n log n) time; apart from the output and the sort's internal space, O(1) extra.
   Intervals that only touch (`[1,4],[4,5]`) merge because the disjoint test is a strict `>`.

Side topics covered along the way:

- **`std::ranges::sort` vs `std::sort`:** the same algorithm. The ranges version takes the
  container directly, supports projections (`ranges::sort(v, {}, [](auto &x){ return x[0]; })`),
  is concept-checked and returns an iterator. It has no execution-policy overloads.
  `vector<int>`'s own lexicographic `operator<` already sorts intervals by their lower
  bound, so no comparator is needed.
- **`emplace_back` vs `push_back`:** they're identical when given an existing object.
  `emplace_back` forwards constructor arguments and calls `explicit` constructors, so
  `v.emplace_back(10)` on a `vector<vector<int>>` appends ten zeros, and
  `emplace_back(1, 5)` means `{5}`, not `{1, 5}`. Braced lists only work with `push_back`.
  Rule of thumb: `push_back` for existing objects and braced lists, `emplace_back` for
  constructor arguments.
- **Skipping the first element in a range-for:** `intervals | std::views::drop(1)` is safe
  on an empty range. `std::ranges::subrange(begin()+1, end())` and
  `std::span(v).subspan(1)` also work, but `subspan(1)` is UB on an empty span.
- **Optional extras not adopted:** `std::move` from `intervals` into `result` (it empties
  the caller's vectors) and `shrink_to_fit` after `reserve`.

## Changes

- `/home/frank/devel/leetcode/56-merge-intervals/cpp/merge.cpp`: edited by the user
  throughout. The final version is described above. Claude made no edits to the project.
- Test binaries were built only in the session scratchpad, not in the project.
- This recap file was created.

## Status

Solved. The final version was submitted on LeetCode and accepted, and it builds without
warnings under `-Wall -Wextra`. The only remaining nit: the end of the first comment block
in the loop still reads "...as the new last interval in result interval doesn't overlap
with it." It should end at "...as the new last interval in result."

Nothing is committed: the whole `56-merge-intervals/` folder, including this recap, is
untracked.
