# 609. Find Duplicate File in System — hash containers, string parsing, optimization review

**Date:** 2026-11-10

## Resume this session

```
claude --resume 7f065654-6f49-45bc-8635-b285cb14bba2
```

Originally started in: `/home/frank/devel/leetcode/609-find-duplicate-file-in-system/cpp`

Display name when written: `cpp-81` (a placeholder derived from the directory; may have since changed).

---

## Summary

This was a learning session around LeetCode 609 (Find Duplicate File in System) in C++.
It was mostly Q&A, and the user wrote the code themselves. Topics covered:

- **Complexity of `unordered_map` / `unordered_set`:** O(1) average and O(n) worst case for
  find/insert/erase, amortized O(1) insert because of rehashing, `reserve`, string keys costing
  O(L) to hash, and a comparison with the tree-based `map`/`set` (O(log n), ordered).
- **Splitting a string on spaces:** `istringstream >>` (merges runs of whitespace),
  `getline` with a delimiter (keeps empty tokens), `views::split`, and `find`/`substr`.
  Member functions such as `find_first_of`/`find_first_not_of`, `substr`, and
  `string_view::remove_prefix`.
- **Detecting a failed `istringstream >>` without exceptions:** streams don't throw by
  default. Test the extraction expression or `fail()`, and don't use `eof()`/`good()`, since
  `eofbit` can be set even after a successful read.
- **Set → vector:** the iterator-range constructor, C++23 `from_range` / `ranges::to`.
  Moving elements out of a set takes `extract`, because the elements are const.
- **Map values → `vector<vector<string>>`:** a loop with `std::move(pair.second)`, or
  C++23 `views::values | as_rvalue | ranges::to`.
- **`folder + "/" + file`:** up to three allocations (counting the `file` substr). Better to
  `reserve` the exact size and `append` the pieces, which takes one allocation.
- **`string_view`:** available since C++17. `starts_with` came in C++20, `contains` in
  C++23, and `operator+` with `string` in C++26.

### Solution review

First submission: `istringstream` tokenizing, a per-folder `unordered_set` of tokens, and
`unordered_map<string, unordered_set<string>>`. Review findings: the algorithm is already
optimal at O(total chars). The overhead was constant-factor only, from sets that the
constraints make redundant (names are unique per folder), copying out of the sets, stream
construction, and `substr` copies.

The user rewrote it with `find(' ')`/`substr` tokenizing and
`unordered_map<string, vector<string>>`, moving the qualifying groups into the result.
The resubmission was accepted at **40 ms (beats 73%), 37.5 MB (beats 80%)**. LeetCode's AI
rated it optimal at O(n·l).

## Changes

- `609-find-duplicate-file-in-system/cpp/findDuplicate.cpp`: solution rewritten by the
  user (not by Claude) as described above.
- `~/.claude/projects/-home-frank-devel-leetcode/memory/609-open-optimizations.md` and
  `MEMORY.md`: memory entry listing the parked optimizations below.
- This recap file.

## Status

Solved and accepted. Parked at the user's request to focus on interview prep. Open,
optional constant-factor improvements:

1. Tokenize with `string_view` instead of `substr` copies.
2. Build the full path in one allocation (`reserve` + `append`).
3. Key the map by `string_view` into `paths`, so content is never copied.
4. Detect the first token with a flag, not `folder.empty()`.
5. Interview follow-up (from LeetCode's analysis): for huge files, group by size, then by
   hash, and compare bytes only when hashes collide.
