# LeetCode scaffolding: in-class method bodies, driver includes implementation

**Date:** 2026-09-28

## Resume this session

```
claude --resume 114f1209-a4ff-4b82-9ab2-b905033bad3b
```

Originally started in: `/home/frank/devel/leetcode`

Display name when written: `leetcode-inline-methods` (auto-generated; may have since changed).

---

## Summary

Goal: make every problem's `<methodName>.cpp` copy-and-paste-able into the LeetCode
editor unchanged, and stop duplicating the class definition in `solution.cpp`. Method
bodies were to stay inside the class, as on the problem page.

Before this, `bin/leetcode-fetch` split the snippet into a declaration-only class plus
out-of-class bodies (`int Solution::foo(...) { ... }`), and `solution.cpp` repeated the
class block token-for-token so the two translation units linked. The split was only
needed because in-class bodies are implicitly `inline` and emit no symbol in a separate
TU.

Chosen approach: `solution.cpp` does `#include "<methodName>.cpp"` and is the only
compiled TU. The implementation file stays self-contained (its own `#include`s,
`using namespace std;`, guarded `leetcode_types.h` include, no `main`), so it both
compiles alone and pastes back as-is. CMake still lists the implementation file so
CLion indexes it, but marks it `HEADER_FILE_ONLY` so it is not built twice. Merging
everything into one file was not needed.

Then the five existing solved problems were converted to the same layout. The
conversion was done by a throwaway script that moved each out-of-class definition
(with any `//` comment directly above it) into the class in place of its declaration,
re-indented. A line-multiset comparison against the backup confirmed only the old
declarations disappeared. The first version of the script had an index-shift bug that
garbled 146/460; those were restored from the backup before rerunning, so no damage
remains.

The conversion also showed why removing the duplicate matters: 146's driver copy of
the class had already drifted (`std::list<int>` vs. `std::list<std::pair<int,int>>`
in the implementation), an ODR violation the compiler never flagged.

## Changes

- `bin/leetcode-fetch`
  - `parse_cpp()` now keeps the class as in the snippet, filling empty bodies with
    `// TODO` + a placeholder `return`; no more out-of-class definitions.
  - `render_impl()` emits that class only.
  - `render_driver()` takes `impl_name` and emits
    `#include "<impl>"  // class <Name>, exactly as pasted into LeetCode` instead of
    the preamble / types include / class copy.
  - `render_cmake()` adds a comment and
    `set_source_files_properties(<impl> PROPERTIES HEADER_FILE_ONLY ON)`.
  - Fixed a pre-existing bug: design problems with a no-arg constructor produced
    `MedianFinder obj();` (vexing parse, didn't compile); now `MedianFinder obj;`.
- `.claude/skills/scaffolding-leetcode-problems/SKILL.md` — "What it produces" and
  "Common mistakes" rewritten for the include layout.
- `CLAUDE.md` (project) — intro sentence, layout comments, `cpp/` section and CMake
  template updated; the out-of-class / ODR / two-rules explanation removed.
- Converted problems (`cpp/<method>.cpp`, `cpp/solution.cpp`, `cpp/CMakeLists.txt`):
  `3-longest-substring-without-repeating-characters`, `4-median-of-two-sorted-arrays`,
  `115-distinct-subsequences`, `146-lru-cache`, `460-lfu-cache`.
  - Problem 4 additionally: free helpers `one_step` and `median_one_list` moved above
    `class Solution`, since the in-class body now needs them declared first.
- Backup of all five `cpp/` folders before conversion (session scratchpad, not
  durable): `/tmp/claude-1000/-home-frank-devel-leetcode/114f1209-a4ff-4b82-9ab2-b905033bad3b/scratchpad/backup/cpp-before.tar`.

## Status

- Generator verified by scaffolding problems 1, 146, 206 (ListNode), 4 and 295 into
  the scratchpad: each implementation compiles standalone and each driver compiles
  and runs with `g++ -std=c++20 -Wall`.
- Converted problems 3, 4, 115, 460: implementation compiles standalone; driver output
  byte-identical to the pre-conversion baseline.
- 146: implementation compiles standalone, but `solution.cpp` does not build because
  of a **pre-existing** bug — `std::string a;` declared twice in `main()` (lines 33 and
  58). Left untouched; with the second renamed in a scratch copy it prints the expected
  `[null,null,null,1,null,-1,null,-1,3,4]`. Fix: delete one of the two lines.
- The CMake build itself is untested — CMake is not installed; builds were done with
  `g++` directly. In CLion, reload the CMake project in each converted folder.
- Nothing committed; all problem files were already untracked before the session.
