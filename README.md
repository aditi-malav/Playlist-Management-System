# Playlist-Management-System

## Overview
A C++ playlist management system implemented using a **singly linked list**.
The project focuses on **correctness, safe transformations, and state recovery**
rather than UI complexity.

---

## Design Philosophy
- Treat the playlist as a **mutable linked structure**
- Separate **user operations** from **system-level validation**
- Prioritize **data safety and recoverability** after transformations

---

## Core Features
- Add / delete songs at any position
- Shuffle, reverse, and de-duplicate playlist
- Undo support using **state snapshots**
- Loop detection using **Floyd’s Cycle Detection Algorithm**
- Explicit memory management to avoid leaks

---

## Undo Mechanism
- Undo is implemented via **deep copy snapshots**
- Before every transformation, the current playlist state is saved
- Undo restores the most recent valid state
- Prevents reliance on inverse operations

---

## Loop Detection
- Detects cycles using Floyd’s algorithm
- Can identify:
  - whether a loop exists
  - starting node of the loop
  - loop length
- Implemented as a **structural safety check**, not user input behavior

---

## Playlist Operations
- Add song:
  - at head
  - at end
  - before a given song
  - after a given song
- Delete song from any position
- Print playlist
- Supports song names with spaces (`getline`)

---

## Transformations
- Shuffle playlist
- Reverse playlist
- Remove duplicate songs

---

## Memory Management
- All nodes are dynamically allocated and explicitly deallocated
- `freePlaylist()` ensures safe cleanup
- Undo history is fully cleared on program exit
- Designed to avoid memory leaks and infinite traversal

---

## Project Structure

```text
.
├── playlist.h      // Node structure and function declarations
├── playlist.cpp    // Linked list logic, validation, undo support
├── main.cpp        // Menu-driven interface and user interaction
├── Makefile        // Build configuration
└── README.md
```
---

## ⏱️ Time & Space Complexity

| Operation | Time Complexity | Space Complexity |
|---------|-----------------|------------------|
| Add / Delete Song | O(n) | O(1) |
| Shuffle Playlist | O(n) | O(1) |
| Reverse Playlist | O(n) | O(1) |
| Remove Duplicates | O(n) | O(n) |
| Undo (State Restore) | O(n) | O(n) |
| Loop Detection (Floyd’s Algorithm) | O(n) | O(1) |
| Loop Start Detection | O(n) | O(1) |
| Loop Length Calculation | O(n) | O(1) |

---

## Key Learnings

- Practical understanding of **singly linked list internals**
- Safe pointer manipulation and traversal techniques
- Difference between **user-visible data** and **structural correctness**
- Designing **system-level validation** independent of user input
- Implementing undo using **state snapshots** instead of inverse operations
- Memory-safe programming with explicit allocation and deallocation
- Applying classical algorithms (Floyd’s cycle detection) in real systems
- Structuring medium-sized C++ projects with headers, source files, and build scripts

---

## Conclusion
A system-oriented C++ project that emphasizes safe linked list transformations,
structural validation, and state recovery through undo.





