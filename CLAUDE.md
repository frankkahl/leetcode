# CLAUDE.md

## Purpose

This folder is for training on LeetCode problems — practising C++ and Python by
solving them. It is not a product; each problem stands on its own.

## Scaffolding a problem

`bin/leetcode-fetch <number | title-slug | URL>` creates the whole folder from
LeetCode's public GraphQL endpoint — no account, key or login involved:

```
./bin/leetcode-fetch 4
./bin/leetcode-fetch https://leetcode.com/problems/two-sum/
```

It writes the description comment, the C++ class with its method bodies in place
(as on the problem page), the driver with the statement's examples wired up, the
`CMakeLists.txt`, and `python/solution.py`. Existing files are left alone unless
`--force` is passed, so re-running it over solved work is safe.

`leetcode-fetch lists` shows your LeetCode lists, `leetcode-fetch lists <name>`
the problems in one, and `--scaffold` creates a folder for each of them. That
part needs your session cookie in `~/.config/leetcode-fetch/session`
(`LEETCODE_SESSION=...`, chmod 600, outside the repo); it expires roughly every
two weeks and is re-copied from the browser's cookie store. Plain problem
scaffolding stays anonymous — no cookie is sent.

Everything below describes what the tool produces — worth knowing when a problem
needs hand-adjusting.

## Layout

One folder per problem, with one subfolder per language. The folder name is the
problem's number and LeetCode's own title slug — `4. Median of Two Sorted
Arrays` becomes `4-median-of-two-sorted-arrays`. The C++ implementation file is
named after the method LeetCode predefines, verbatim including its camelCase:

```
4-median-of-two-sorted-array/
  cpp/
    findMedianSortedArrays.cpp   # class Solution with its bodies, as on the problem page
    solution.cpp                 # main(); #includes the above and runs the examples
    CMakeLists.txt
  python/
    solution.py
```

Every file that declares `class Solution` carries the problem description above
it as a comment block: title and difficulty, the statement, the examples with
their expected output, and the constraints — copied from the problem page.

### cpp/

- `<methodName>.cpp` contains `class Solution` as LeetCode predefines it on the
  problem page — same class name, same method signature. This is the code that
  gets pasted back into LeetCode, so nothing local (no `main`, no test
  scaffolding, no I/O) belongs in it. The method bodies stay **inside** the
  class, exactly as on the web page. The only addition is the `#include`s and
  `using namespace std;` that LeetCode supplies invisibly, so the file also
  compiles on its own; LeetCode accepts them unchanged, so the whole file can be
  copied and pasted into the editor as-is.
- `solution.cpp` holds `main()`, instantiates `Solution`, feeds it the sample
  inputs from the problem statement and prints each result next to the expected
  one. The inputs are LeetCode's own `exampleTestcases` — the contents of the
  Testcase panel — with parameter names and types taken from the problem's
  `metaData`, so they match what the judge actually runs rather than what the
  statement prose happens to say. Design problems are driven from their call
  script (`["LRUCache","put",...]` plus its argument list) and print a
  `[null,null,1,...]` line to compare against the expected one. Only problems
  whose inputs are pointers — linked lists and trees — fall back to carrying the
  examples as comments and a TODO, since those need a builder to exist first.
  It gets the class by `#include "<methodName>.cpp"`, so the class is written
  once and there is nothing to keep in sync.
- `CMakeLists.txt` compiles only `solution.cpp`, at C++20. It still lists
  `<methodName>.cpp` so the IDE indexes it, but marks it `HEADER_FILE_ONLY` —
  compiled as a second translation unit it would just duplicate the class.
- `leetcode_types.h` appears only for problems whose statement relies on a type
  LeetCode predefines on its judge and shows you as a comment (`ListNode`,
  `TreeNode`, `Node`). The header defines it for real, and `<methodName>.cpp` pulls
  it in behind `#if __has_include("leetcode_types.h")`, which is true locally and
  false on LeetCode — so the file still pastes back unedited.

The default compiler here is **g++ 13.3.0**, which supports C++20 in full (and
C++23 as well), so C++20 is a safe target with no fallback needed. CMake itself
is **not installed** — `sudo apt install cmake` gets 4.2.3; keep
`cmake_minimum_required` at 3.20 or higher, since CMake 4 dropped compatibility
with anything below 3.5.

Template:

```cmake
cmake_minimum_required(VERSION 3.20)
project(two_sum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# twoSum.cpp is #included by solution.cpp; it is listed only so the IDE indexes it.
add_executable(two_sum
    solution.cpp
    twoSum.cpp
)
set_source_files_properties(twoSum.cpp PROPERTIES HEADER_FILE_ONLY ON)
```

Build with `cmake -S . -B build && cmake --build build`.

### python/

- `solution.py` contains `class Solution` as predefined on the problem page, plus
  a `if __name__ == "__main__":` block running the sample inputs.

## Working here

- Solutions are practice material: prefer clear, idiomatic code and note the time
  and space complexity of the approach.
- Explain the idea behind an approach before or alongside the code — the point is
  learning, not just a passing submission.
- Don't hand over a full solution unless it is asked for; a hint or a discussion
  of the approach is often what is wanted.
