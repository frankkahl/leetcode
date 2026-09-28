---
name: scaffolding-leetcode-problems
description: Use when starting a LeetCode problem in this repo, when a problem is named by number, title or leetcode.com URL, or when asking what is on the user's LeetCode lists.
---

# Scaffolding LeetCode problems

`bin/leetcode-fetch` builds a problem's folder from LeetCode's own data. Run it
instead of writing the files by hand — hand-written scaffolding drifts from the
judge's signature, misses the description comment, and invents test inputs.

## When to use

- "let's do problem 42", a bare number, a title, or a `leetcode.com/problems/...` URL
- "what's on my lists", "start everything in <list name>"
- A folder exists but was created by hand, or is missing `CMakeLists.txt` or the driver

Not for: writing the algorithm. The tool leaves every body as `// TODO` on
purpose — solving is the point of this repo.

## Quick reference

| Goal | Command |
|------|---------|
| Scaffold one problem | `./bin/leetcode-fetch 4` |
| ... by slug or URL | `./bin/leetcode-fetch two-sum` |
| Regenerate over existing files | `./bin/leetcode-fetch 4 --force` |
| Show all lists | `./bin/leetcode-fetch lists` |
| Show one list | `./bin/leetcode-fetch lists "Refreshing C++"` |
| Scaffold a whole list | `./bin/leetcode-fetch lists "Refreshing C++" --scaffold` |

## What it produces

`<id>-<title-slug>/` with `cpp/` (implementation named after the method, driver,
`CMakeLists.txt`, plus `leetcode_types.h` for `ListNode`/`TreeNode` problems) and
`python/solution.py`. Drivers are wired to LeetCode's `exampleTestcases` and print
actual next to expected. The implementation file is LeetCode's snippet with the
bodies inside the class, so it pastes straight back into the editor; the driver
`#include`s it, so the class exists exactly once. `CLAUDE.md` explains the layout.

Build: `cmake -S . -B build && cmake --build build` inside `cpp/`.

## Lists need authentication

`lists` reads `LEETCODE_SESSION` from `~/.config/leetcode-fetch/session`. If it
reports the session is invalid, the cookie was revoked — signing out of
leetcode.com or changing the password kills it. Ask the user to re-copy it from
DevTools -> Application -> Cookies into that file themselves, with `read -rsp`, so
the credential never enters the transcript. Never paste a cookie value into chat,
a command line, or a file inside the repo. Problem scaffolding needs no cookie.

## Common mistakes

- **Creating the folder by hand.** Use the tool, then edit the bodies.
- **Putting local code in `<method>.cpp`.** No `main`, I/O or test helpers there —
  it is what gets pasted into LeetCode. They belong in `solution.cpp`.
- **Compiling `<method>.cpp` as its own source.** CMake lists it with
  `HEADER_FILE_ONLY` so the IDE indexes it; it is built only through the
  driver's `#include`. Don't drop that property or add it to another target.
- **`--force` over solved work.** It overwrites bodies. Without it, existing files
  are skipped, which is what you want when only adding a missing file.
- **Assuming a name.** The folder uses LeetCode's own title slug, so check the
  tool's output rather than guessing the plural or the hyphenation.
